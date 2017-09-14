cmake_minimum_required(VERSION 3.7)
project(Simple-C-Calculator)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES lab1_avoytovi.c)
add_executable(lab1_avoytovi.c ${SOURCE_FILES})
add_executable(main lab1_avoytovi.c)