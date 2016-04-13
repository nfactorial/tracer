project(TRACER_MATERIALS)

include_directories(include)
include_directories(${TRACER_EXTERNAL_SOURCE_DIR}/sce_vectormath/include/vectormath/SSE/cpp) # TODO: Simplify this

set(SOURCE_FILES
        src/material.cpp)

set(INCLUDE_FILES
        include/material.h
        include/surface_info.h)

add_library(tracer_materials ${SOURCE_FILES} ${HEADER_FILES})

#if(TRACER_BUILD_TESTS)
#    add_subdirectory(test)
#endif()
