cmake_minimum_required(VERSION 3.27)
project(Chouette)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(raylib)

add_executable(Chouette main.cpp)
target_link_libraries(Chouette PRIVATE raylib)
