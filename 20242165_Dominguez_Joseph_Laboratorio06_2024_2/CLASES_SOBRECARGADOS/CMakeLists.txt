cmake_minimum_required(VERSION 4.0)
project(CLASES_SOBRECARGADOS)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLASES_SOBRECARGADOS main.cpp
        Bibliotecas/Cliente.cpp
        Bibliotecas/Cliente.h
        Bibliotecas/Plato.cpp
        Bibliotecas/Plato.h
        Bibliotecas/Restaurante.cpp
        Bibliotecas/Restaurante.h)
