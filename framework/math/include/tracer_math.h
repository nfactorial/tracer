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

#if !defined( MATH_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
#define MATH_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL


//////////////////////////////////////////////////////////////////

#include <vectormath_aos.h>


//////////////////////////////////////////////////////////////////

namespace tracer {
    typedef Vectormath::Aos::Vector3 Vector3;
    typedef Vectormath::Aos::Quat Quaternion;
    typedef Vectormath::Aos::Matrix3 Matrix3x3;
    typedef Vectormath::Aos::Matrix4 Matrix4x4;

    const float EPSILON = 1E-7f;

    //! \brief  Ensures a value resides within a specified range.
    //! \param  value [in] -
    //!         The value to be clamped.
    //! \param  minimum [in] -
    //!         The minimum value of the range.
    //! \param  maximum [in] -
    //!         The maximum value of the range.
    //! \return If the supplied value is between the specified range the value is returned.
    inline float clamp( float value, float minimum, float maximum )
    {
        return value < minimum ? minimum : value > maximum ? maximum : value;
    }

    //! \brief  Ensures a value is within the [0...1] range.
    //! \param  value [in] -
    //!         The value to be clamped.
    //! \return 0 if value was below 0, 1 if value was above 1 otherwise value is returned.
    inline float saturate( float value )
    {
        return clamp( value, 0.0f, 1.0f );
    }

    inline float Bias( float value, float t )
    {
        return ( 1.0f - t ) + t*value;
    }

    inline float lerp( float start, float end, float t )
    {
        return start + t*( end - start );
    }

    inline const Vector3 reflect( const Vector3 incident, const Vector3 normal )
    {
        return incident - normal * 2.0f * Vectormath::Aos::dot( incident, normal );
    }
}


//////////////////////////////////////////////////////////////////

#endif //!defined( MATH_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
