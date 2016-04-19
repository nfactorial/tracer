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

#include "node.h"
#include "gtest/gtest.h"

TEST( Node, Construction ) {
    tracer::Node node;

    EXPECT_TRUE(node.castShadows());
    EXPECT_TRUE(node.receiveShadows());
    EXPECT_EQ(tracer::kNodeType_Invalid, node.getNodeType());
}

TEST( Node, NameValidation ) {
    std::string emptyName;
    std::string validName("valid_name");

    EXPECT_FALSE(tracer::Node::validateName(emptyName));
    EXPECT_TRUE(tracer::Node::validateName(validName));
}
