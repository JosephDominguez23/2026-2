cmake_minimum_required(VERSION 4.0)
project(PREG01_LAB07)

set(CMAKE_CXX_STANDARD 20)

add_executable(PREG01_LAB07 main.cpp
        Bibliotecas/Producto.cpp
        Bibliotecas/Producto.h
        Bibliotecas/Bebida.cpp
        Bibliotecas/Bebida.h
        Bibliotecas/Entrada.cpp
        Bibliotecas/Entrada.h
        Bibliotecas/PlatoFondo.cpp
        Bibliotecas/PlatoFondo.h
        Bibliotecas/Comanda.cpp
        Bibliotecas/Comanda.h
        Bibliotecas/Restaurante.cpp
        Bibliotecas/Restaurante.h
)
