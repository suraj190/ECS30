cmake_minimum_required(VERSION 3.8)
project(WordCount)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES wcount.c)
add_executable(WordCount ${SOURCE_FILES})