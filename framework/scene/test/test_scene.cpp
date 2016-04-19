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

#include "scene.h"
#include "node.h"
#include "gtest/gtest.h"

TEST( Scene, Construction ) {
    tracer::Scene scene;

    EXPECT_EQ(0, scene.getNodeCount());
    EXPECT_FALSE(scene.deleteNode("example"));
    EXPECT_EQ(nullptr, scene.findNode("example"));
}

TEST( Scene, NameValidation ) {
    // TODO: Ensure scene.validateName returns true and false appropriately.
}

TEST( Scene, NodeManagement ) {
    tracer::Scene scene;

    std::string emptyName;
    std::string testName( "example_node" );

    EXPECT_FALSE(scene.createNode(tracer::kNodeType_Geometry, emptyName));
    EXPECT_FALSE(scene.createNode(tracer::kNodeType_Light, emptyName));

    EXPECT_FALSE(scene.deleteNode(emptyName));
    EXPECT_FALSE(scene.deleteNode(testName));

    EXPECT_TRUE(scene.createNode(tracer::kNodeType_Geometry, testName));
    EXPECT_FALSE(scene.createNode(tracer::kNodeType_Geometry, testName));
    EXPECT_FALSE(scene.createNode(tracer::kNodeType_Light, testName));

    EXPECT_NE(nullptr, scene.findNode(testName));

    EXPECT_TRUE(scene.deleteNode(testName));
    EXPECT_FALSE(scene.deleteNode(testName));

    EXPECT_EQ(nullptr, scene.findNode(testName));

    EXPECT_TRUE(scene.createNode(tracer::kNodeType_Light, testName));
    EXPECT_FALSE(scene.createNode(tracer::kNodeType_Light, testName));
    EXPECT_FALSE(scene.createNode(tracer::kNodeType_Geometry, testName));

    EXPECT_NE(nullptr, scene.findNode(testName));

    EXPECT_TRUE(scene.deleteNode(testName));
}
