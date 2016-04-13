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

#if !defined( ISAMPLER_HEADER_INCLUDED_MAY_2015_NFACTORIAL )
#define ISAMPLER_HEADER_INCLUDED_MAY_2015_NFACTORIAL


// -----------------------------------------------------------------------------------

#include "image_sample.h"


// -----------------------------------------------------------------------------------

namespace tracer {
    class RandomGenerator;
    class SampleContainer;


    struct ISampler {
        virtual int getMaximumSamples() const = 0;
        virtual bool getImageSamples(SampleContainer &samples, const RandomGenerator &random, int x, int y) = 0;
        virtual int getImageSamples(ImageSample *sampleOutput, const RandomGenerator &random, int x, int y) = 0;
    };
}


// -----------------------------------------------------------------------------------

#endif //!defined( ISAMPLER_HEADER_INCLUDED_MAY_2015_NFACTORIAL )
