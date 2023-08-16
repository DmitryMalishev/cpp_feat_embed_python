# DEMO-project to demonstrate using embedded package of Python into a C++ Windows application

Shown C++ and Python connection allows to distribute the program with no need for a user to install Python in the OS.

Used MSVC 2022 and Python 3.10. You may need to re-create the solution for another version of MSVC and update sources for another version of Python.

For simplicity, the program just calculates an average of array.

Steps to launch the project:
[1] Clone the repo WITH submodules.
[2] Install Python 3.10 to the OS as usual. Install numpy. Verify PYTHONPATH env variable.
[3] Launch 'python_bootstrap.bat' to download embedded Python 3.10 and copy numpy.
[4] Open the solution in MSVC and build it.
[5] Now you have the binary and the folder with embedded Python. Copy some DLLs and you're ready to distribute or make an installer.

 