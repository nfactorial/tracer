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

#include "gtest/gtest.h"
#include "sample_container.h"

namespace {
    static const size_t     kTestCapacity   = 16;
}


TEST(SampleContainer, Construction) {
    tracer::TSampleContainer<kTestCapacity> samples;

    EXPECT_EQ(0, samples.size());
    EXPECT_EQ(kTestCapacity, samples.capacity());
}

TEST(SampleContainer, AddSample) {
    tracer::TSampleContainer<kTestCapacity> samples;

    EXPECT_EQ(0, samples.size());
    for (size_t loop = 0; loop < samples.capacity(); ++loop) {
        tracer::ImageSample sample;
        sample.x = loop;
        sample.y = loop;

        EXPECT_TRUE(samples.addSample(sample));
    }
    EXPECT_EQ(samples.capacity(), samples.size());

    // Collection is full, addSample should return false if we attempt to add another
    tracer::ImageSample overflow;

    overflow.x = 0.0f;
    overflow.y = 0.0f;

    EXPECT_FALSE(samples.addSample(overflow));

    // Verify the collection contains the expected values
    for (size_t loop = 0; loop < samples.capacity(); ++loop) {
        EXPECT_EQ(float(loop), samples[loop].x);
        EXPECT_EQ(float(loop), samples[loop].y);
    }
}

TEST(SampleContainer, Clear) {
    tracer::TSampleContainer<kTestCapacity> samples;

    EXPECT_EQ(0, samples.size());
    for (size_t loop = 0; loop < samples.capacity(); ++loop) {
        tracer::ImageSample sample;
        sample.x = loop;
        sample.y = loop;

        EXPECT_TRUE(samples.addSample(sample));
    }
    EXPECT_EQ(samples.capacity(), samples.size());

    samples.clear();

    EXPECT_EQ(0, samples.size());
}

TEST(SampleContainer, Index) {
    tracer::TSampleContainer<kTestCapacity> samples;

    // Sanity check the unit test, we wont work if capacity is not greater than two.
    EXPECT_TRUE(samples.capacity() > 2);

    const size_t halfCapacity = samples.capacity() / 2;

    EXPECT_EQ(0, samples.size());
    for (size_t loop = 0; loop < halfCapacity; ++loop) {
        tracer::ImageSample sample;
        sample.x = loop;
        sample.y = loop;

        EXPECT_TRUE(samples.addSample(sample));
    }
    EXPECT_EQ(halfCapacity, samples.size());

    EXPECT_DEATH(samples[halfCapacity], "(index < m_size)");
    EXPECT_DEATH(samples[samples.capacity()], "(index < m_size)");
}
