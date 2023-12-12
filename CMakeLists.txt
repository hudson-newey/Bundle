cmake_minimum_required(VERSION 3.1)
project(Bundler)

add_subdirectory(lib/yaml-cpp)

add_executable(
    bundler
    src/main.cpp
)

target_link_libraries(
    bundler
    PRIVATE
    yaml-cpp
)
