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

#ifndef PROJECT_MATERIAL_H
#define PROJECT_MATERIAL_H


//////////////////////////////////////////////////////////////////

#include <vectormath_aos.h>


//////////////////////////////////////////////////////////////////

namespace tracer {
    class Node;

    struct SurfaceInfo;

    //! \brief
    class Material {
    public:
        Material();
        virtual ~Material();

        virtual void evaluate(SurfaceInfo &info, Node *node, Vectormath::Aos::Vector3 position);

    public:
        float m_Ka;         // Ambient coefficient
        float m_Kd;         // Diffuse coefficient
        float m_Ks;         // Specular coefficient
        float m_Kr;         // Reflection coefficient
    };
}


//////////////////////////////////////////////////////////////////

#endif //PROJECT_MATERIAL_H
