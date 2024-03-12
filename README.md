# BitBuddy

BitBuddy is a silly little C++ game developed in the Qt framework.

### Dependencies

* A modern C++ compiler (Opening and running the project in CLion should be enough)
* Qt 6.2.1 or later
* CMake 3.26 or later

### Running the Program

You need to ensure that CMake can find your QT 6 installation. You can either set this manually in the `CMakeLists.txt`
by appending a manual`CMAKE_PREFIX_PATH` or you can set the `CMAKE_PREFIX_PATH` environment variable to the path of your
Qt 6 installation.

