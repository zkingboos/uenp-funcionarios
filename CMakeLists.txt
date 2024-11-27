cmake_minimum_required(VERSION 3.27)
project(funcionario C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
        src/main.c
        src/programa.c
        src/empresa.c
        src/funcionario.c
        src/tela.c
        src/util.c)

add_executable(funcionario ${SOURCES})
