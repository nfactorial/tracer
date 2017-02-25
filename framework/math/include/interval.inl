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

#if !defined( INTERVAL_INL_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
#define INTERVAL_INL_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL


//////////////////////////////////////////////////////////////////

#include <math.h>


//////////////////////////////////////////////////////////////////

namespace tracer {
    //! \brief  Retrieves the length of the interval.
    //! \return The length of the interval.
    inline float Interval::getLength() const {
        return fabsf(end - start);
    }


    //! \brief  Determines whether or not a position lies within the interval.
    //! \param  t [in] -
    //!         The location to be compared with the interval.
    //! \return <em>True</em> if the specified value t lies within the interval otherwise <em>false</em>.
    inline bool Interval::contains(float t) const {
        return (t >= start && t <= end);
    }
}


//////////////////////////////////////////////////////////////////

#endif //!defined( INTERVAL_INL_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
