cmake_minimum_required(VERSION 3.8)
project(Change_NEW)

set(CMAKE_C_STANDARD 11)

#add additional lines
set(GCC_ENABLE_WARNINGS " -Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_ENABLE_WARNINGS}")

set(SOURCE_FILES change.c)
add_executable(Change_NEW ${SOURCE_FILES})

