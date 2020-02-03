cmake_minimum_required(VERSION 3.8)
project(Conversion_2)

set(CMAKE_C_STANDARD 11)
#add additional lines
set(GCC_ENABLE_WARNINGS " -Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_ENABLE_WARNINGS}")

set(SOURCE_FILES main.c)
add_executable(Conversion_2 ${SOURCE_FILES})