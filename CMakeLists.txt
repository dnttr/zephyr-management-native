cmake_minimum_required(VERSION 3.31)
project(zephyr-management)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    app.cpp)

add_executable(zephyr_management "src/${SOURCES}")
