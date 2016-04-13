project(tracer_sampling)

include_directories(include)
include_directories(${TRACER_MATH_SOURCE_DIR}/include)
include_directories(${TRACER_EXTERNAL_SOURCE_DIR}/sce_vectormath/include/vectormath/SSE/cpp) # TODO: Simplify this

set(SOURCE_FILES
        src/stochastic_sampler.cpp)

set(INCLUDE_FILES
        include/image_sample.h
        include/sample_container.h
        include/isampler.h
        include/stochastic_sampler.h)

add_library(tracer_sampling ${SOURCE_FILES} ${HEADER_FILES})

if(TRACER_BUILD_TESTS)
    add_subdirectory(test)
endif()
