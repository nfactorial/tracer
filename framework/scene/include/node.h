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

#ifndef PROJECT_NODE_H_H
#define PROJECT_NODE_H_H


//////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "node_type.h"


//////////////////////////////////////////////////////////////////////////////////////

namespace tracer {
    class Ray;

    struct Interval;
    struct HitResult;

    //! \brief  Represents a single object within a scene.
    class Node {
    public:
        Node();
        ~Node();

        const std::string& getName() const;

        bool castShadows() const;
        bool receiveShadows() const;

        kNodeType getNodeType() const;

        void getBounds();

        bool intersect(HitResult &result, const Ray &ray, const Interval &interval);

    private:
        void refreshBounds();

    private:
        kNodeType m_type;
        bool m_boundsDirty;

        std::string m_name;

        bool m_receiveShadows;
        bool m_castShadows;
    };


    //! \brief  Retrieves the name associated with the node.
    //! \return The name currently associated with the node.
    inline const std::string& Node::getName() const {
        return m_name;
    }

    //! \brief  Retrieves the type of the node represented by the object.
    //! \return The type of node represented by the object.
    inline kNodeType Node::getNodeType() const {
        return m_type;
    }


    //! \brief  Determines whether or not the node should cast shadows in a scene.
    //! \return <em>True</em> if the node casts shadows otherwise <em>false</em>.
    inline bool Node::castShadows() const {
        return m_castShadows;
    }


    //! \brief  Determines whether or not the node should receive shadows in a scene.
    //! \return <em>True</em> if the node receives shadows otherwise <em>false</em>.
    inline bool Node::receiveShadows() const {
        return m_receiveShadows;
    }
}


//////////////////////////////////////////////////////////////////////////////////////

#endif //PROJECT_NODE_H_H
