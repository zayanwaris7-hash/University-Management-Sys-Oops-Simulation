cmake_minimum_required(VERSION 3.10)

project(University-Management-Sys-Oops-Simulation)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FILES src/*.cpp)

add_executable(University-Management-Sys-Oops-Simulation ${SRC_FILES})

target_include_directories(University-Management-Sys-Oops-Simulation PRIVATE include)

target_compile_options(University-Management-Sys-Oops-Simulation PRIVATE -Wall -Wextra)