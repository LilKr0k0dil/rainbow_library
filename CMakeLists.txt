cmake_minimum_required(VERSION 3.10)
project(rainbow_library)

set(CMAKE_CXX_STANDARD 11)

add_library(rainbow_library INTERFACE)

target_include_directories(rainbow_library INTERFACE include)