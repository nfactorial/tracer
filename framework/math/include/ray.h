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

#if !defined( RAY_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
#define RAY_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL


//////////////////////////////////////////////////////////////////

#include "tracer_math.h"


//////////////////////////////////////////////////////////////////

namespace tracer {
    //! \brief  Defines a basic ray within the engine.
    //!
    //! A ray has a position and direction where the direction is normally
    //! of unit length. The world position of the ray can be obtained by
    //! passing a time value to the evaluation operator.
    //!
    //! \code
    //! Ray ray;
    //! Vector3 position = ray( time );
    //! \endcode
    //!
    class Ray {
    public:
        Ray();
        ~Ray();

        Ray(const Ray &other);
        Ray(const Vector3 origin, const Vector3 direction);

        const Ray& operator=(const Ray &other);

        const Vector3 getOrigin() const;
        const Vector3 getDirection() const;

        const Vector3 getLocation(float distance) const;

    private:
        Vector3 m_origin;
        Vector3 m_direction;
    };
}


//////////////////////////////////////////////////////////////////


#include "ray.inl"


//////////////////////////////////////////////////////////////////

#endif //!defined( RAY_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
