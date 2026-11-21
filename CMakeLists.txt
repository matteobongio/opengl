cmake_minimum_required(VERSION 3.23)

project(opengl)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(GLFW_BUILD_X11 OFF)

add_executable(opengl)

find_package(OpenGL REQUIRED)
add_subdirectory("vendor/glfw-3.5.1")
add_subdirectory("vendor/glad")

target_sources(opengl
		PRIVATE
				src/main.cpp
)

target_link_libraries(opengl
    PRIVATE
        glfw
		glad
        OpenGL::GL
)
