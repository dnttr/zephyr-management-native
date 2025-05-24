cmake_minimum_required(VERSION 3.31)
project(zephyr-management)

include(${CMAKE_SOURCE_DIR}/tools/Dependencies.cmake)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    library.cpp)

add_library(${PROJECT_NAME} SHARED "src/${SOURCES}")

prepare_dependencies()
target_include_directories(${PROJECT_NAME} PUBLIC include /usr/local/include)

#these libs should be installed on the system for now, later they will be bundled with the project and opened using dlopen
target_link_libraries(${PROJECT_NAME} PUBLIC /usr/local/lib/libznb.dylib /usr/local/lib/libze.dylib)

set_target_properties(${PROJECT_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME "zm"
        VERSION 1.0.0
        SOVERSION 1
        INSTALL_RPATH "@loader_path"
)



