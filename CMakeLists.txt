cmake_minimum_required(VERSION 3.26)
project(bitbuddy VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND CMAKE_PREFIX_PATH "/Users/ryanhecht/Qt/6.6.1/macos")
list(APPEND CMAKE_PREFIX_PATH "/Users/daniel/Qt/6.6.1/macos")
list(APPEND CMAKE_PREFIX_PATH "/shaylan/path")
list(APPEND CMAKE_PREFIX_PATH "/annabel/path")
list(APPEND CMAKE_PREFIX_PATH "/razvan/path")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

qt_standard_project_setup()

include_directories(include)

add_executable(bitbuddy src/main.cpp
        src/MainWindow.cpp
        include/MainWindow.h)
target_link_libraries(bitbuddy
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

