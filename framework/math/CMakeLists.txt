project(TRACER_MATH)

include_directories(include)
include_directories(${TRACER_EXTERNAL_SOURCE_DIR}/sce_vectormath/include/vectormath/SSE/cpp) # TODO: Simplify this

set(SOURCE_FILES
        src/interval.cpp)

set(INCLUDE_FILES
        include/random_generator.h
        include/interval.h
        include/interval.inl
        include/tracer_math.h
        include/ray.h
        include/ray.inl)

add_library(tracer_math ${SOURCE_FILES} ${HEADER_FILES})

if(TRACER_BUILD_TESTS)
    add_subdirectory(test)
endif()
