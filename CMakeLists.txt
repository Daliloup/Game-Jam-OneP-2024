cmake_minimum_required(VERSION 3.27)
project(Chouette)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(raylib)
file(COPY ./sprites DESTINATION .)

add_executable(Chouette main.cpp
        ObjectManager.cpp
        ObjectManager.h
        Object.cpp
        Object.h)
target_link_libraries(Chouette PRIVATE raylib)
