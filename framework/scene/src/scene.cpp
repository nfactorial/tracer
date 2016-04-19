//
// Copyright 2016 nfactorial
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "scene.h"
#include "node.h"
#include "hit_result.h"
#include "ray.h"
#include "interval.h"
#include "surface_info.h"
#include "material.h"

namespace tracer {
    Scene::Scene() {
        //
    }

    Scene::~Scene() {
        for (auto it = m_nodeMap.begin(); it != m_nodeMap.end(); ++it ) {
            delete it->second;
        }

        for (auto it = m_lightMap.begin(); it != m_lightMap.end(); ++it ) {
            delete it->second;
        }
    }


    //! \brief  Adds a new node to the scene.
    //! \param  type [in] -
    //!         The type of node to be created within the scene.
    //!
    //! Note: This may be changed to 'createNode' or similar factory function so that we
    //! don't rely on external code to create the node while we delete it.
    bool Scene::createNode(kNodeType type, const std::string &name){
        Node *node = nullptr;

        if (Node::validateName(name)) {
            // TODO: Lock mutex here if we want to be thread safe
            if (!findNode(name)) {
                node = new Node(); // TODO: Initialize with correct data

                switch (type) {
                    case kNodeType_Geometry:
                        m_nodeMap[name] = node;
                        break;

                    case kNodeType_Light:
                        m_lightMap[name] = node;
                        break;

                    default:
                        break;
                }
            }
        }

        return ( nullptr != node );
    }


    //! \brief  Retrieves a node from the scene with the specified name.
    //! \param  name [in] -
    //!         Name of the node to be retrieved.
    //! \return Pointer to the Node with the specified name, if one could not be found this method returns <em>nullptr</em>.
    Node* Scene::findNode(const std::string &name) {
        // TODO: Use a map to look-up the node.

        auto node = m_nodeMap.find(name);
        if (node != m_nodeMap.end()) {
            return node->second;
        }

        auto light = m_lightMap.find(name);
        if (light != m_lightMap.end()) {
            return light->second;
        }

        return nullptr;
    }


    //! \brief  Removes a node from the scene.
    //! \param  name [in] -
    //!         Name of the node to be deleted.
    //! \return <em>True</em> if the node was deleted successfully otherwise <em>false</em>.
    bool Scene::deleteNode( const std::string &name ) {
        auto node = m_nodeMap.find(name);
        if (node != m_nodeMap.end()) {
            delete node->second;
            m_nodeMap.erase(node);
            return true;
        }

        auto light = m_lightMap.find(name);
        if (light != m_lightMap.end()) {
            delete light->second;
            m_lightMap.erase(light);
            return true;
        }

        return false;
    }


    //! \brief  Traces a ray through the scene and determines its color.
    //!
    //! NOTE: The tracing performance is currently very poor, we're simply brute forcing
    //!       everything and have no hierarhical scene representation to help.
    //!
    //! \param  result [in/out] -
    //!         Vector3 that will contain the color of the ray.
    //! \param  ray [in] -
    //!         The ray whose path is to be traced through the scene.
    //! \param  interval [in] -
    //!         The interval of interest for the ray being traced.
    //! \return Distance from the ray origin to the ray intersection, if no intersection was found this will be infinity.
    float Scene::traceRay(Vectormath::Aos::Vector3 &result, const Ray &ray, const Interval &interval) {
        return traceRay(result, ray, interval, 1);
    }


    //! \brief  Traces a ray through the scene and determines its color.
    //! \param  result [in/out] -
    //!         Vector3 that will contain the color of the ray.
    //! \param  ray [in] -
    //!         The ray whose path is to be traced through the scene.
    //! \param  interval [in] -
    //!         The interval of interest for the ray being traced.
    //! \param  depth [in] -
    //!         The current ray traversal depth.
    //! \return Distance from the ray origin to the ray intersection, if no intersection was found this will be infinity.
    float Scene::traceRay(Vectormath::Aos::Vector3 &result, const Ray &ray, const Interval &interval, int depth) {
        HitResult intersection;
        if (hitTest(intersection, ray, interval)) {
            SurfaceInfo surface;

            if (intersection.material) {
                intersection.material->evaluate(surface, intersection.node, intersection.location);
            }
            else {
                /*
                surface.Ka = 0.05f;
                surface.Kr = 0.60f;
                surface.Ks = 0.0f;
                surface.Kd = 1.0f - surface.Ka - surface.Kr;
                surface.color = intersection.color;
                 */
                surface.Ka = 0.05f;
                surface.Kr = 0.0f;
                surface.Ks = 0.0f;
                surface.Kd = 1.0f - surface.Ka - surface.Kr;
                surface.color = Vectormath::Aos::Vector3(0.2f, 0.7f, 0.3f);
            }

            Vectormath::Aos::Vector3 diffuse(illuminate(ray, intersection.location, intersection.normal, depth));
            Vectormath::Aos::Vector3 reflected(0.0f);
            Vectormath::Aos::Vector3 ambient(1.0f);

            Vectormath::Aos::Vector3 surfaceColor(surface.color);

            if (depth < 3 && surface.Kr > 0.001f) {
                traceRay(reflected,
                         Ray(intersection.location, tracer::reflect(ray.getDirection(), intersection.normal)),
                         Interval::Front, depth + 1);
            }

            Vectormath::Aos::Vector3 lighting(ambient * surface.Ka + diffuse * surface.Kd + reflected * surface.Kr);

            result = Vectormath::Aos::mulPerElem(surfaceColor, lighting);
            return intersection.distance;
        }

        // result = Vector3( 0.0f );
        result = Vectormath::Aos::Vector3(0.1f, 0.3f, 0.8f);
        return std::numeric_limits<float>::infinity();
    }


    //! \brief  Determines if and when a specified ray intersects the scene.
    //!
    //! This method only returns the nearest intersection point along the given ray,
    //! within the specified interval. No recursion or shading is performed.
    //!
    //! \param  result [in/out] -
    //!         Object where the intersection result will be stored.
    //! \param  ray [in] -
    //!         Ray to be intersected with the scene, if possible.
    //! \param  interval [in] -
    //!         The interval of interest, only intersections within this interval will be returned.
    //! \return <em>True</em> if an intersection was found otherwise <em>false</em>.
    bool Scene::hitTest(HitResult &result, const Ray &ray, const Interval &interval) {
        bool intersected = false;

        result.distance = std::numeric_limits<float>::infinity();

        for (auto it = m_nodeMap.begin(); it != m_nodeMap.end(); ++it ) {
            HitResult localResult;

            if (it->second->intersect(localResult, ray, interval)) {
                // Only consider the intersection if it exists within our interval and is closer than the last intersection
                if (interval.contains(localResult.distance) && localResult.distance < result.distance) {
                    // TODO: Change end point of interval to closest intersection, saves additional comparison
                    intersected = true;
                    result = localResult;
                }
            }
        }

        return intersected;
    }


    //! \brief  Computes the illumination of a single point within the scene.
    //! \param  incident [in] -
    //!         The ray that is intersecting the point of illumination.
    //! \param  position [in] -
    //!         The world position of the point that is to be illuminated.
    //! \param  normal [in] -
    //!         The surface normal at the point of intersection.
    //! \return The amount of illumination at the specified point.
    const Vectormath::Aos::Vector3 Scene::illuminate(const Ray &incident, const Vectormath::Aos::Vector3 &position, const Vectormath::Aos::Vector3 &normal, int depth) {
        // return Vector3( normal[ 0 ] * 0.5f + 0.5f, 0.0f, 0.0f );
        // return Vector3( 0.0f, normal[ 1 ] * 0.5f + 0.5f, 0.0f );
        // return Vector3( 0.0f, 0.0f, normal[ 2 ] * 0.5f + 0.5f );
        // output = Vector3( 0.0f, 0.0f, output[ 2 ] * 0.5f + 0.5f );

        // Vector3 result( 0.0f );

        Vectormath::Aos::Vector3 lightPos(0.0f, 2.0f, -3.0f);

        // Temp light from directly above
        Vectormath::Aos::Vector3 lightDir(0.0f, -1.0f, 0.0f);

        lightDir = Vectormath::Aos::normalize(Vectormath::Aos::Vector3(0.0f) - lightPos);

        float illum = 0.0f;

        HitResult result;

        Ray shadowRay(position, -lightDir);
        if (!hitTest(result, shadowRay, Interval::Front)) {
            float d = tracer::clamp(Vectormath::Aos::dot(normal, -lightDir), 0.0f, 1.0f);
            illum += d;
        }

        if (illum > 1.0f)
            illum = 1.0f;

        Vectormath::Aos::Vector3 color(illum);
        // Vector3 color( 1.0f );

    /*  if ( depth < 3 )
        {
            Vector3 reflected;
            traceRay( reflected, Ray( position, reflect( incident.getDirection(), normal ) ), Interval::Front, depth + 1 );
            color = color + reflected * Kr;
            //color = reflected * Kr;
        }
    */
        return color;
    /*
        ShadeInfo shadeInfo;

        shadeInfo.incident  = incident;
        shadeInfo.location  = position;
        shadeInfo.normal    = normal;

        for ( auto it = m_lightMap.begin(); it != m_lightMap.end(); ++it) {
            result += it->second->illuminate( shadeInfo );
        }

        return result;
    */
    }
}
