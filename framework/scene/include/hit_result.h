//
// Copyright 2014 nfactorial
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#if !defined( HIT_RESULT_HEADER_INCLUDED_MAY_2015_NFACTORIAL )
#define HIT_RESULT_HEADER_INCLUDED_MAY_2015_NFACTORIAL


// -----------------------------------------------------------------------------------

#include "tracer_math.h"


// -----------------------------------------------------------------------------------

namespace tracer {
    class Node;
    class Material;

    struct HitResult {
        float distance;         // Distance along ray to the intersection point
        Vector3 color;          // Color associated with the object (not material)
        Vector3 localCoord;     // Object space positino of the intersection
        Vector3 location;       // World position of the intersection
        Vector3 normal;         // World Normal at the point of intersection
        Material *material;     // Material associated with intersection point
        Node *node;             // Node we intersected with
    };
}


// -----------------------------------------------------------------------------------

#endif //!defined( HIT_RESULT_HEADER_INCLUDED_MAY_2015_NFACTORIAL )
