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
#include "interval.h"

TEST(Interval, TestEmpty) {
    tracer::Interval empty = tracer::Interval::Empty;

    EXPECT_FALSE(empty.contains(0.0f));
    EXPECT_FALSE(empty.contains(0.0001f));
    EXPECT_FALSE(empty.contains(100.0f));

    EXPECT_FALSE(empty.contains(-0.0001f));
    EXPECT_FALSE(empty.contains(-1.0f));
    EXPECT_FALSE(empty.contains(-100.0f));
}

TEST(Interval, TestFront) {
    tracer::Interval front = tracer::Interval::Front;

    EXPECT_TRUE(front.contains(0.0f));
    EXPECT_TRUE(front.contains(0.0001f));
    EXPECT_TRUE(front.contains(100.0f));

    EXPECT_FALSE(front.contains(-0.0001f));
    EXPECT_FALSE(front.contains(-1.0f));
    EXPECT_FALSE(front.contains(-100.0f));
}

TEST(Interval, TestBack) {
    tracer::Interval back = tracer::Interval::Back;

    EXPECT_FALSE(back.contains(0.0f));
    EXPECT_FALSE(back.contains(0.0001f));
    EXPECT_FALSE(back.contains(100.0f));

    EXPECT_TRUE(back.contains(-0.0001f));
    EXPECT_TRUE(back.contains(-1.0f));
    EXPECT_TRUE(back.contains(-100.0f));
}

TEST(Interval, TestInfinite) {
    tracer::Interval infinite = tracer::Interval::Back;

    EXPECT_TRUE(infinite.contains(0.0f));
    EXPECT_TRUE(infinite.contains(0.0001f));
    EXPECT_TRUE(infinite.contains(100.0f));

    EXPECT_TRUE(infinite.contains(-0.0001f));
    EXPECT_TRUE(infinite.contains(-1.0f));
    EXPECT_TRUE(infinite.contains(-100.0f));
}
