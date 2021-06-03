cmake_minimum_required(VERSION 3.16)
project(gnl_cm C)

set(CMAKE_C_STANDARD 99)

add_executable(gnl_cm
        get_next_line_utils.c        
        get_next_line.h
        get_next_line.c
        main.c
        )