#include <iostream>
#include <fstream>
#include <vector>

#include "pybind11/include/pybind11/pybind11.h"
#include "pybind11/include/pybind11/embed.h"
#include "pybind11/include/pybind11/stl.h"

namespace py = pybind11;

const bool USE_EMBEDDED_PYTHON = true;

int main()
{
    std::cout << "C++: program entry point" << std::endl;

    try
    {
        if (USE_EMBEDDED_PYTHON)
        {
            Py_SetPath(L"python_embedded\\;python_embedded\\python310.zip");
            std::cout << "C++: using EMBEDDED Python" << std::endl;
        }
        else
        {
            std::cout << "C++: using DEFAULT Python" << std::endl;
        }

        std::cout << "C++: acquiring Python interpreter" << std::endl;
        py::scoped_interpreter guard{};

        // Printing Python search paths for debug
        std::cout << "-----\nPython search paths:" << std::endl;
        PyRun_SimpleString("import sys\nprint(sys.path)");
        std::cout << "-----" << std::endl;

        std::cout << "C++: requesting function from Python" << std::endl;
        py::function py_calc_avg =
            py::reinterpret_borrow<py::function>(
                py::module::import("numpy").attr("mean")
            );

        // Making test array
        std::vector<uint8_t> array = { 1, 2, 5, 10, 17 };

        // Caclulating average value by calling Python
        std::cout << "C++: calling Python function" << std::endl;
        py::object py_result = py_calc_avg(array);
        std::cout << "C++: received value: " << py_result.cast<float>() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "C++: program finished successfully" << std::endl;
}
