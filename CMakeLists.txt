cmake_minimum_required(VERSION 3.26)
project(bitbuddy VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND CMAKE_PREFIX_PATH "/Users/ryanhecht/Qt/6.6.1/macos")
list(APPEND CMAKE_PREFIX_PATH "/Users/danielesemezie/Qt/6.6.2/macos")
list(APPEND CMAKE_PREFIX_PATH "/shaylan/path")
list(APPEND CMAKE_PREFIX_PATH "/annabel/path")
list(APPEND CMAKE_PREFIX_PATH "/razvan/path")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        SpatialAudio
        REQUIRED)

qt_standard_project_setup()

include_directories(game/include)

add_executable(bitbuddy game/src/main.cpp
        resources.qrc
        game/src/MainWindow.cpp
        game/include/MainWindow.h
        game/src/model/Event.cpp
        game/include/model/Event.h
        game/src/model/SingleAttributeEvent.cpp
        game/include/model/SingleAttributeEvent.h
        game/include/model/BitBuddyAttributeName.h
        game/src/service/EventGeneratorService.cpp
        game/include/service/EventGeneratorService.h
        game/src/service/EventDispatcherService.cpp
        game/include/service/EventDispatcherService.h
        game/include/model/DeprecatedEventListener.h
        game/src/service/GameService.cpp
        game/include/service/GameService.h
        game/include/model/BitBuddyEvents.h
        game/src/model/BitBuddyEvents.cpp
        game/src/component/BitBuddyStatusWidget.cpp
        game/include/component/BitBuddyStatusWidget.h
        game/src/model/BitBuddyAttributeName.cpp
        game/src/model/BitBuddy.cpp
        game/include/model/BitBuddy.h
        game/src/model/BitBuddyAttribute.cpp
        game/include/model/BitBuddyAttribute.h
        game/src/component/BitBuddyActionButton.cpp
        game/include/component/BitBuddyActionButton.h
        game/src/service/BitBuddySpriteHandler.cpp
        game/include/service/BitBuddySpriteHandler.h
        game/src/LauncherWindow.cpp
        game/include/LauncherWindow.h
        game/include/SettingsWindow.h
        game/src/SettingsWindow.cpp
        game/src/service/MusicService.cpp
        game/include/service/MusicService.h
        game/src/model/audio.cpp
        game/include/model/audio.h
        game/src/service/FileStorageService.cpp
        game/include/service/FileStorageService.h

)


target_link_libraries(bitbuddy
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        Qt::SpatialAudio
)
