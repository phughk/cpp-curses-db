cmake_minimum_required(VERSION 3.10)
project(main)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(cpp-curses-db main.cpp)
target_link_libraries(cpp-curses-db ${CURSES_LIBRARIES})
