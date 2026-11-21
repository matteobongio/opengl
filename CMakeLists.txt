cmake_minimum_required(VERSION 3.23)

project(opengl)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(GLFW_BUILD_X11 OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(opengl)

find_package(OpenGL REQUIRED)
add_subdirectory("vendor/glfw-3.5.1")
add_subdirectory("vendor/glad")

target_sources(opengl PRIVATE ${SOURCES})

# Makes `#include "mesh/mesh.h"` work from anywhere
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_compile_definitions(opengl PRIVATE
    SHADER_DIR="${CMAKE_SOURCE_DIR}/src/shaders"
)

target_link_libraries(opengl
    PRIVATE
        glfw
		glad
        OpenGL::GL
)
