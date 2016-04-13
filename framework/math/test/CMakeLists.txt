project(tracer_math_test)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${TRACER_MATH_SOURCE_DIR}/include)

add_executable(tracer_math_test
        test_interval.cpp)

target_link_libraries(tracer_math_test gtest gtest_main)
target_link_libraries(tracer_math_test tracer_math)
