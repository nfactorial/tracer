project(tracer_sampling_test)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${TRACER_MATH_SOURCE_DIR}/include)

add_executable(tracer_sampling_test
        test_sample_container.cpp)

target_link_libraries(tracer_sampling_test gtest gtest_main)
target_link_libraries(tracer_sampling_test tracer_sampling)