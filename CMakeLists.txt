cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES x86_64)

option(TRACER_BUILD_TESTS "Build unit tests." ON)
# option(TRACER_BUILD_TESTS "Build unit tests." OFF)

include_directories(SYSTEM external/sce_vectormath/include/vectormath/SSE/cpp)

add_subdirectory(external)

add_subdirectory(framework)
add_subdirectory(application)
