cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
project(Bundle)

include(CTest)

add_subdirectory(lib/yaml-cpp)

add_executable(
    bundle
    src/main.cpp
)

target_link_libraries(
    bundle
    PRIVATE
    yaml-cpp
)

# cmake tests
add_test(NAME noBundleFile COMMAND bundle)
set_property (TEST noBundleFile PROPERTY WILL_FAIL true)

add_test(NAME bundleVersion COMMAND bundle --version)
set_property (TEST bundleVersion PROPERTY WILL_FAIL false)

add_test(NAME bundleVersionShort COMMAND bundle -v)
set_property (TEST bundleVersionShort PROPERTY WILL_FAIL false)

add_test(NAME bundleHelpDocs COMMAND bundle --help)
set_property (TEST bundleHelpDocs PROPERTY WILL_FAIL false)

add_test(NAME bundleHelpDocsShort COMMAND bundle -h)
set_property (TEST bundleHelpDocsShort PROPERTY WILL_FAIL false)
