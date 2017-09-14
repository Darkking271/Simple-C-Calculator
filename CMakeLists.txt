cmake_minimum_required(VERSION 3.7)
project(Simple-C-Calculator)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c solver.c solver.h)
add_executable(main.c ${SOURCE_FILES})
add_executable(main main.c)