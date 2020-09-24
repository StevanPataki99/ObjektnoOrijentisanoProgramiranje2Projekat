cmake_minimum_required(VERSION 3.17)
project(Pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pong main.cpp engine.cpp engine.h eventlistener.h keyboardeventlistener.cpp keyboardeventlistener.h drawable.h movable.h player.cpp player.h spritesheet.cpp spritesheet.h sprite.cpp sprite.h ball.cpp ball.h objectgroup.cpp objectgroup.h)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

target_link_libraries(Pong ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})


