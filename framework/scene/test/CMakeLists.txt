project(tracer_scene_test)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${TRACER_MATH_SOURCE_DIR}/include)

add_executable(tracer_scene_test
        test_scene.cpp
        test_node.cpp)

target_link_libraries(tracer_scene_test gtest gtest_main)
target_link_libraries(tracer_scene_test tracer_math tracer_scene)