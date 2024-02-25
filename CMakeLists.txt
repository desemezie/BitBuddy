cmake_minimum_required(VERSION 3.26)
project(bitbuddy)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(bitbuddy main.cpp)
target_link_libraries(bitbuddy
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

