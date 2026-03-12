cmake_minimum_required(VERSION 3.27)
project(NBodyEngine CXX)

# Enforce modern C++ (C++ Standard 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Some local third party files
# 1. pybind11
add_subdirectory(third_party/pybind11)

# Automatically fetch some tools 

# Compile the C++ code into a Python extension module (.pyd)
# Note: "nbody_core" is the final name
pybind11_add_module(nbody_core src/Universe.cpp src/bindings.cpp)