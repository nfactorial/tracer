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


#include "node.h"
#include "hit_result.h"
#include "interval.h"
#include "ray.h"

namespace tracer {
    Node::Node()
    : m_type(kNodeType_Invalid)
    , m_boundsDirty(true)
    , m_receiveShadows(true)
    , m_castShadows(true)
    {
    }

    Node::~Node() {
    }

    //! \brief  Retrieves the bounding volume of the node.
    void Node::getBounds() {
        if ( m_boundsDirty ) {
            refreshBounds();
        }
    }

    //! \brief  Recomputes the bounding volume of the node.
    void Node::refreshBounds() {
        m_boundsDirty = false;
    }

    //! \brief  Determines if and where the specified ray intersects the nodes geometry.
    //! \param  result [in] -
    //!         Upon returning, this structure will contain a description of the intersection.
    //! \param  ray [in] -
    //!         The ray to be tested against the geometry, the ray should be in the nodes local space.
    //! \param  interval [in] -
    //!         The time interval where an intersection would be considered valid.
    //! \return <em>True</em> if a valid intersection was found otherwise <em>false</em>.
    bool Node::intersect(HitResult &result, const Ray &ray, const Interval &interval) {
        return false;
    }


    //! \brief  Determines whether or not a specified name is suitable for use with a node.
    //! \param  name [in] -
    //!         The name to be validated.
    //! \return <em>True</em> if the name is considered valid, otherwise <em>false</em>.
    bool Node::validateName(const std::string &name) {
        if (name.length() == 0) {
            return false;
        }

        return true;
    }
}
