project(TRACER_TEST)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tracer_tests
        test_.cpp)

target_link_libraries(tracer_tests gtest gtest_main)
target_link_libraries(tracer_tests tracer_core)
