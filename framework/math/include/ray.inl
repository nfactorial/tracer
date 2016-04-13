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

#if !defined( RAY_INL_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
#define RAY_INL_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL


//////////////////////////////////////////////////////////////////

namespace tracer {
    inline Ray::Ray() {
    }

    inline Ray::~Ray() { }

    inline Ray::Ray(const Ray &other)
    : m_origin(other.m_origin), m_direction(other.m_direction) {
    }

    inline Ray::Ray(const Vector3 origin, const Vector3 direction)
    : m_origin(origin), m_direction(direction) {
    }


    //! \brief Copy operator for the Ray class
    inline const Ray &Ray::operator=(const Ray &other) {
        m_origin = other.m_origin;
        m_direction = other.m_direction;

        return *this;
    }

    //! \brief  Retrieves the starting position of the ray.
    //! \return The starting point for the ray.
    inline const Vector3 Ray::getOrigin() const {
        return m_origin;
    }


    //! \brief  Gets the direction the ray is travelling.
    //! \return The direction the ray is travelling.
    inline const Vector3 Ray::getDirection() const {
        return m_direction;
    }


    //! \brief  Computes the point on the ray a specified distance along its length.
    //! \param  distance [in] -
    //!         The distance along the ray where its position is to be evaluated.
    //! \return The position of the ray at the specified distance.
    inline const Vector3 Ray::getLocation(float distance) const {
        return m_origin + (m_direction * distance);
    }
}


//////////////////////////////////////////////////////////////////

#endif //!defined( RAY_INL_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
