cmake_minimum_required(VERSION 3.27)
project(untitled C)

set(CMAKE_C_STANDARD 23)

add_executable(untitled main.c
        sources/login.c
        headers/login.h
        sources/interface.c
        headers/interface.h
        sources/search.c
        headers/search.h
        sources/borrowDonate.c
        headers/borrowDonate.h)
