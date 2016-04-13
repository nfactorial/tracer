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

#if !defined( STRATIFIEDSAMPLER_HEADER_INCLUDED_MAY_2015_NFACTORIAL )
#define STRATIFIEDSAMPLER_HEADER_INCLUDED_MAY_2015_NFACTORIAL


// -----------------------------------------------------------------------------------

#include "isampler.h"


// -----------------------------------------------------------------------------------

namespace tracer {
    //!< \brief Calculates a spread of samples within an image pixel.
    class StochasticSampler : public ISampler {
    public:
        StochasticSampler(int xSamples, int ySamples, bool jitter);
        ~StochasticSampler();

        // ISampler methods
        int getMaximumSamples() const;
        bool getImageSamples(SampleContainer &samples, const RandomGenerator &random, int x, int y);
        int getImageSamples(ImageSample *sampleOutput, const RandomGenerator &random, int x, int y);

    private:
        bool m_jitter;
        int m_xSamples;
        int m_ySamples;
    };
}


// -----------------------------------------------------------------------------------

#endif //!defined( STRATIFIEDSAMPLER_HEADER_INCLUDED_MAY_2015_NFACTORIAL )
