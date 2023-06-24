cmake_minimum_required(VERSION 3.1)
project(YamlExample)

add_subdirectory(lib/yaml-cpp) # This is one way of referencing another
                                       # CMake project

add_executable(
    bundler
    src/main.cpp
)

target_link_libraries(
    bundler
    PRIVATE
    yaml-cpp
)