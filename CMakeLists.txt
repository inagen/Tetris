cmake_minimum_required(VERSION 3.5)
project (tetris)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tetris main.cpp game.cpp gameState.cpp)

find_package(SFML COMPONENTS audio graphics window system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(tetris ${SFML_LIBRARIES})
target_link_libraries(tetris sfml-graphics)