project(tracer_scene)

include_directories(include)
include_directories(${TRACER_MATH_SOURCE_DIR}/include)
include_directories(${TRACER_MATERIALS_SOURCE_DIR}/include)

include_directories(${TRACER_EXTERNAL_SOURCE_DIR}/sce_vectormath/include/vectormath/SSE/cpp) # TODO: Simplify this

set(SOURCE_FILES
        src/node.cpp
        src/scene.cpp)

set(INCLUDE_FILES
        include/hit_result.h
        include/node.h
        include/node_type.h
        include/scene.h)

add_library(tracer_scene ${SOURCE_FILES} ${HEADER_FILES})

if(TRACER_BUILD_TESTS)
    add_subdirectory(test)
endif()
