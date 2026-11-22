cmake_minimum_required(VERSION 3.23)

project(opengl)

include(FetchContent)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(GLFW_BUILD_X11 OFF)

add_executable(opengl)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

find_package(OpenGL REQUIRED)
add_subdirectory("vendor/glfw-3.5.1")
add_subdirectory("vendor/glad")

FetchContent_Declare(
    glm
    GIT_REPOSITORY	https://github.com/g-truc/glm.git
    GIT_TAG 	8d1fd52e5ab5590e2c81768ace50c72bae28f2ed #1.0.3
)

FetchContent_MakeAvailable(glm)

target_sources(opengl PRIVATE ${SOURCES})

# Makes `#include "mesh/mesh.h"` work from anywhere
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_compile_definitions(opengl PRIVATE
    SHADER_DIR="${CMAKE_SOURCE_DIR}/src/shaders"
    RESOURCES="${CMAKE_SOURCE_DIR}/resources"
)

target_link_libraries(opengl
    PRIVATE
        glfw
        glad
        OpenGL::GL
        glm::glm
)
