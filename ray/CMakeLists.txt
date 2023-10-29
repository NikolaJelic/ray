add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        "${CMAKE_CURRENT_BINARY_DIR}/include"
)

target_compile_features(${PROJECT_NAME} PUBLIC
        cxx_std_23
)


target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
        include/ray/image_render.hpp
        include/ray/vec.hpp
        include/ray/color.hpp
        include/ray/image.hpp
)

target_sources(${PROJECT_NAME} PRIVATE
        src/image_render.cpp
        src/main.cpp
        src/image.cpp
)