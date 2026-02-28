cmake_minimum_required(VERSION 3.15)
project(NBodyEngine CXX)

# Enforce modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Automatically fetch some tools
# 1. fetch the pybind
include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG        v2.11.1 
)
FetchContent_MakeAvailable(pybind11)
# 2. 


# Compile the C++ code into a Python extension module (.pyd)
# Note: "nbody_core" is the final name
pybind11_add_module(nbody_core src/physics.cpp)