cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
project(Bundler)

include(CTest)

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

# cmake tests
add_test(NAME noBundleFile COMMAND bundler)
set_property (TEST noBundleFile PROPERTY WILL_FAIL true)

add_test(NAME bundlerVersion COMMAND bundler --version)
set_property (TEST bundlerVersion PROPERTY WILL_FAIL false)

add_test(NAME bundlerVersionShort COMMAND bundler -v)
set_property (TEST bundlerVersionShort PROPERTY WILL_FAIL false)

add_test(NAME bundlerHelpDocs COMMAND bundler --help)
set_property (TEST bundlerHelpDocs PROPERTY WILL_FAIL false)

add_test(NAME bundlerHelpDocsShort COMMAND bundler -h)
set_property (TEST bundlerHelpDocsShort PROPERTY WILL_FAIL false)
