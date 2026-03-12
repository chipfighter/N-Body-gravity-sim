#include <pybind11/pybind11.h>
#include <pybind11/stl.h>    // Convert data between C++ std::vector and Python list 
#include "../include/nbody/Universe.h"

namespace py = pybind11;

PYBIND11_MODULE(nbody_core, m){
    py::class_<nbody::Universe>(m, "Universe")
        .def(py::init<>())
        .def("add_star", &nbody::Universe::add_star)
        .def("step", &nbody::Universe::step)
        .def("get_positions", &nbody::Universe::get_positions);
}

// "Python3_EXECUTABLE": "${sourceDir}/../python_server/.venv/Scripts/python.exe",可能是我这里写错了