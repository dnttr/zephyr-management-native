cmake_minimum_required(VERSION 3.31)
project(zephyr-management-native)

include(${CMAKE_SOURCE_DIR}/tools/Dependencies.cmake)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        ${CMAKE_SOURCE_DIR}/src/loader.cpp
        ${CMAKE_SOURCE_DIR}/src/bindings.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

prepare_dependencies()
target_include_directories(${PROJECT_NAME} PUBLIC include)

set_target_properties(${PROJECT_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        OUTPUT_NAME "zm"
        INSTALL_RPATH "@loader_path"
)