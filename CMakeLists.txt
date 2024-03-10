cmake_minimum_required(VERSION 3.26)
project(bitbuddy VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND CMAKE_PREFIX_PATH "/Users/ryanhecht/Qt/6.6.1/macos")
list(APPEND CMAKE_PREFIX_PATH "/daniel/path")
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
        resources.qrc
        src/MainWindow.cpp
        include/MainWindow.h
        src/model/Event.cpp
        include/model/Event.h
        src/model/SingleAttributeEvent.cpp
        include/model/SingleAttributeEvent.h
        include/model/BitBuddyAttributeName.h
        src/service/EventGeneratorService.cpp
        include/service/EventGeneratorService.h
        src/service/EventDispatcherService.cpp
        include/service/EventDispatcherService.h
        include/model/DeprecatedEventListener.h
        src/service/GameService.cpp
        include/service/GameService.h
        include/model/BitBuddyEvents.h
        src/model/BitBuddyEvents.cpp
        src/component/BitBuddyStatusWidget.cpp
        include/component/BitBuddyStatusWidget.h
        src/model/BitBuddyAttributeName.cpp
        src/model/BitBuddy.cpp
        include/model/BitBuddy.h
        src/model/BitBuddyAttribute.cpp
        include/model/BitBuddyAttribute.h
        src/component/BitBuddyActionButton.cpp
        include/component/BitBuddyActionButton.h
        src/service/BitBuddySpriteHandler.cpp
        include/service/BitBuddySpriteHandler.h
        src/LauncherWindow.cpp
        include/LauncherWindow.h

)


target_link_libraries(bitbuddy
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

