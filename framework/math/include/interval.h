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

#if !defined( INTERVAL_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
#define INTERVAL_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL


//////////////////////////////////////////////////////////////////

namespace tracer {
    //! \brief  The Interval object is used to represent a segment of time within the application.
    struct Interval {
        float start;
        float end;

        Interval(float start, float end);

        float getLength() const;

        bool contains(float t) const;

        static const Interval Infinite;
        static const Interval Front;
        static const Interval Back;
        static const Interval Empty;
    };
}


//////////////////////////////////////////////////////////////////

#include "interval.inl"


//////////////////////////////////////////////////////////////////

#endif //!defined( INTERVAL_HEADER_INCLUDED_DECEMBER_2014_NFACTORIAL )
