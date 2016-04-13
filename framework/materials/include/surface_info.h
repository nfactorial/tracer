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

#ifndef PROJECT_SURFACE_INFO_H
#define PROJECT_SURFACE_INFO_H


//////////////////////////////////////////////////////////////////

namespace tracer {
    //! \brief Simple definition of a surface within the scene.
    struct SurfaceInfo {
        float Ka;   // Ambient coefficient
        float Kd;   // Diffuse coefficient
        float Ks;   // Specular coefficient
        float Kr;   // Reflective coefficient
        Vectormath::Aos::Vector3 color;
    };
}


//////////////////////////////////////////////////////////////////

#endif //PROJECT_SURFACE_INFO_H
