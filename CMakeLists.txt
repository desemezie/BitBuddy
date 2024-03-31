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
list(APPEND CMAKE_PREFIX_PATH "/home/razvan/Qt/6.6.3/gcc_64")

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
        game/src/window/LauncherWindow.cpp
        game/include/window/LauncherWindow.h
        game/include/window/SettingsWindow.h
        game/src/window/SettingsWindow.cpp
        game/src/service/MusicService.cpp
        game/include/service/MusicService.h
        game/src/model/audio.cpp
        game/include/model/audio.h
        game/src/service/FileStorageService.cpp
        game/include/service/FileStorageService.h
        game/src/service/BitBuddyService.cpp
        game/include/service/BitBuddyService.h
        game/src/service/UserBankAccountService.cpp
        game/include/service/UserBankAccountService.h
        game/src/model/UserBankAccount.cpp
        game/include/model/UserBankAccount.h
        game/src/model/BitBuckGenerator.cpp
        game/include/model/BitBuckGenerator.h
        game/src/service/TransactionService.cpp
        game/include/service/TransactionService.h
        game/src/component/UserBankAccountBalanceWidget.cpp
        game/include/component/UserBankAccountBalanceWidget.h
        game/src/window/StatsWindow.cpp
        game/include/window/StatsWindow.h
        game/src/component/LightButton.cpp
        game/include/component/LightButton.h
        game/src/component/StatsButton.cpp
        game/include/component/StatsButton.h
        game/src/window/ShopWindow.cpp
        game/include/window/ShopWindow.h
        game/src/window/BoardWindow.cpp
        game/include/window/BoardWindow.h
        game/src/window/TieWindow.cpp
        game/src/window/BuddyWindow.cpp
        game/include/window/BuddyWindow.h
        game/include/window/TieWindow.h
)


target_link_libraries(bitbuddy
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
        Qt::SpatialAudio
)
