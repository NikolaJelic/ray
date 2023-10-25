add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        "${CMAKE_CURRENT_BINARY_DIR}/include"
)

target_compile_features(${PROJECT_NAME} PUBLIC
        cxx_std_23
)


target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
        include/ray/render/image_render.hpp

)

target_sources(${PROJECT_NAME} PRIVATE
        src/render/image_render.cpp
        src/main.cpp
)