cmake_minimum_required(VERSION 4.0)
project(CLASES_OBJETOS)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLASES_OBJETOS main.cpp
        Biblioteca/Cliente.cpp
        Biblioteca/Cliente.h
        Biblioteca/Plato.cpp
        Biblioteca/Plato.h
        Biblioteca/Restaurante.cpp
        Biblioteca/Restaurante.h)
