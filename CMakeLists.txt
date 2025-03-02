cmake_minimum_required(VERSION 3.30)
project(My_Project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

add_subdirectory(src)
add_subdirectory(tests)