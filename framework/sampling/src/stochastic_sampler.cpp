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

#include "stochastic_sampler.h"
#include "sample_container.h"
#include "random_generator.h"


// -----------------------------------------------------------------------------------

namespace tracer {
    StochasticSampler::StochasticSampler(int xSamples, int ySamples, bool jitter)
    : m_jitter(jitter)
    , m_xSamples(xSamples)
    , m_ySamples(ySamples) {
    }

    StochasticSampler::~StochasticSampler() {
    }


    //! \brief  Determines the maximum number of samples this sampler may compute for a single pixel.
    //! \return The maximum number of samples this sampler will produce.
    int StochasticSampler::getMaximumSamples() const {
        return m_xSamples * m_ySamples;
    }

    bool StochasticSampler::getImageSamples(SampleContainer &samples, const RandomGenerator &random, int x, int y) {
        const float dx = 1.0f / m_xSamples;
        const float dy = 1.0f / m_ySamples;

        ImageSample sample;

        samples.clear();
        for (int yLoop = 0; yLoop < m_ySamples; ++yLoop) {
            for (int xLoop = 0; xLoop < m_xSamples; ++xLoop) {
                const float xJitter = m_jitter ? random.nextFloatAbs() : 0.5f;
                const float yJitter = m_jitter ? random.nextFloatAbs() : 0.5f;

                sample.x = x + (xLoop + xJitter) * dx;
                sample.y = y + (yLoop + yJitter) * dy;

                if (!samples.addSample(sample)) {
                    return false;
                }
            }
        }

        return true;
    }


    //! \brief  Calculates a collection of image samples using the stratified sampler.
    //! \param  sampleOutput [in/out] -
    //!         Buffer where the resulting samples are to be stored.
    //! \param  random [in] -
    //!         The random number generator to be used when calculating the samples.
    //! \param  x [in] -
    //!         Image position the samples will be computed for.
    //! \param  y [in] -
    //!         Image position the samples will be computed for.
    //! \return The number of samples computed by the stratified sampler.
    int StochasticSampler::getImageSamples(ImageSample *sampleOutput, const RandomGenerator &random, int x, int y) {
        int nSamples = 0;

        if (sampleOutput) {
            const float dx = 1.0f / m_xSamples;
            const float dy = 1.0f / m_ySamples;

            for (int yLoop = 0; yLoop < m_ySamples; ++yLoop) {
                for (int xLoop = 0; xLoop < m_xSamples; ++xLoop) {
                    const float xJitter = m_jitter ? random.nextFloatAbs() : 0.5f;
                    const float yJitter = m_jitter ? random.nextFloatAbs() : 0.5f;

                    sampleOutput[nSamples].x = x + (xLoop + xJitter) * dx;
                    sampleOutput[nSamples].y = y + (yLoop + yJitter) * dy;

                    nSamples++;
                }
            }
        }

        return nSamples;
    }
}
