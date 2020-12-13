cmake_minimum_required(VERSION 3.14)

project(livereload LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 CONFIG REQUIRED Core Quick Widgets)

add_executable(livereload
    Config.cpp
    main.cpp
)

target_link_libraries(livereload
    PRIVATE Qt5::Core Qt5::Widgets)

add_executable(livereload-qml
    Config.cpp
    main-qml.cpp
    qml.qrc
)

target_compile_definitions(livereload-qml
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(livereload-qml
    PRIVATE Qt5::Core Qt5::Quick)
