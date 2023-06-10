cmake_minimum_required(VERSION 3.0)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

set(SOURCES
        main.cpp
        snake.cpp
        food.cpp
        game.cpp
        )

add_executable(SnakeGame ${SOURCES})

target_link_libraries(SnakeGame sfml-graphics sfml-window sfml-system)
