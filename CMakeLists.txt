cmake_minimum_required(VERSION 3.17)
project(NeoShell C)

set(CMAKE_C_STANDARD 99)

add_executable(NeoShell main.c shell_loop.h shell_loop.c builtin.h read_line.c execute.c neosh_cd.c neosh_exit.c split_line.c)