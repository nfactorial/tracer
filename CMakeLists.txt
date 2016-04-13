cmake_minimum_required(VERSION 3.3)

set(CMAKE_OSX_ARCHITECTURES x86_64)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

option(TRACER_BUILD_TESTS "Build unit tests." ON)
# option(TRACER_BUILD_TESTS "Build unit tests." OFF)

add_subdirectory(external)

add_subdirectory(framework)
add_subdirectory(application)
