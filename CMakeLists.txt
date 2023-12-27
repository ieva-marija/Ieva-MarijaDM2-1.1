cmake_minimum_required(VERSION 3.25)
project(strategija)
set(SOURCES
    src/main.cpp
    src/test.cpp
    src/gen.cpp
    src/mylib.cpp
    src/genlist.cpp
)
add_executable(my_executables ${SOURCES})
target_include_directories(my_executables PRIVATE include)
