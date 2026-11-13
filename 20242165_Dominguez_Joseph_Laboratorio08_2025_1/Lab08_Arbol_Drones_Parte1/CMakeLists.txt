cmake_minimum_required(VERSION 4.0)
project(Lab08_Arbol_Drones_Parte1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab08_Arbol_Drones_Parte1 main.cpp
        Bibliotecas/Dron.cpp
        Bibliotecas/Dron.h
        Bibliotecas/DroneSemaforo.cpp
        Bibliotecas/DroneSemaforo.h
        Bibliotecas/DroneEstacionamiento.cpp
        Bibliotecas/DroneEstacionamiento.h
        Bibliotecas/DroneVelocidad.cpp
        Bibliotecas/DroneVelocidad.h
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Arbol.cpp
        Bibliotecas/Arbol.h
        Bibliotecas/Central.cpp
        Bibliotecas/Central.h)
