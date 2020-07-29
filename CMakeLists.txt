cmake_minimum_required(VERSION 3.10)
project(Compiler VERSION 0.0.1)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()

add_test(myTests myTest)