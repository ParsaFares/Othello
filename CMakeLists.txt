cmake_minimum_required(VERSION 3.6)

project(Othello)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(Qt5_BASE_DIR ~/Qt5.8.0/5.8/clang_64/)

set(CMAKE_PREFIX_PATH ${Qt5_BASE_DIR};${CMAKE_PREFIX_PATH})

set(SOURCE_FILES main.cpp AI/Point.h AI/Point.cpp)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui)