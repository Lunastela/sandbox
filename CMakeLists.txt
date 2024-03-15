cmake_minimum_required(VERSION 3.24.0)
project(Sandbox VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(lib/SDL)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

add_executable(Sandbox src/main.cpp)
target_link_libraries(Sandbox PRIVATE
    SDL2
    OpenGL
    GLEW::glew
)