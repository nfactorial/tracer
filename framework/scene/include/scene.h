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

#ifndef PROJECT_SCENE_H
#define PROJECT_SCENE_H


//////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <unordered_map>

#include <vectormath_aos.h>
#include "node_type.h"


//////////////////////////////////////////////////////////////////////////////////////

namespace tracer {
    class Ray;
    class Node;

    struct Interval;
    struct HitResult;

    //! \brief
    class Scene {
        typedef std::unordered_map< std::string, Node* >    NodeMap;

    public:
        Scene();
        ~Scene();

        bool createNode( kNodeType type, const std::string &name );

        Node* findNode( const std::string &name );
        bool deleteNode( const std::string &name );

        float traceRay( Vectormath::Aos::Vector3 &result, const Ray &ray, const Interval &interval );
        float traceRay( Vectormath::Aos::Vector3 &result, const Ray &ray, const Interval &interval, int depth );

        bool hitTest( HitResult &result, const Ray &ray, const Interval &interval );
        const Vectormath::Aos::Vector3 illuminate( const Ray &incident, const Vectormath::Aos::Vector3 &position, const Vectormath::Aos::Vector3 &normal, int depth );

        size_t getNodeCount() const;

        bool validateName(const std::string &name) const;

    private:
        NodeMap m_nodeMap;
        NodeMap m_lightMap;
    };


    //! \brief  Retrieves the number of nodes that currently exist with the scene object.
    //! \return The number of nodes currently contained within the scene.
    inline size_t Scene::getNodeCount() const {
        return m_nodeMap.size();
    }
}


//////////////////////////////////////////////////////////////////////////////////////

#endif //PROJECT_SCENE_H
