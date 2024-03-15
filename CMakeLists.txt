cmake_minimum_required(VERSION 3.22.0)
project(Sandbox VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(lib/SDL)
add_subdirectory(lib/glm)

set(gl_VERSIONS 4.6)
set(gles2_VERSIONS 3.2)
set(vulkan_VERSIONS 1.0 1.1)

set(gl_PROFILES core)
set(APIS gl gles2 vulkan)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/glad/include)
file(GLOB BUTTERFLIES_SOURCES_C ${CMAKE_CURRENT_SOURCE_DIR} *.c lib/glad/src/gl.c)
add_library(glad ${BUTTERFLIES_SOURCES_C})

add_executable(Sandbox src/main.cpp)
target_link_libraries(Sandbox PRIVATE
    SDL2
    glad
    glm
)