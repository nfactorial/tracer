project( tracer )

set(SOURCE_FILES
        application.cpp)

add_executable(tracer ${SOURCE_FILES})

target_link_libraries(tracer    tracer_scene
                                tracer_sampling
                                tracer_math)
