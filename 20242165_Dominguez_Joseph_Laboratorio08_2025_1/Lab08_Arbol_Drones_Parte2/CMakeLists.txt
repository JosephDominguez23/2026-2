cmake_minimum_required(VERSION 4.0)
project(Lab08_Arbol_Drones_Parte2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab08_Arbol_Drones_Parte2 main.cpp
        Bibliotecas/Arbol.cpp
        Bibliotecas/Central.cpp
        Bibliotecas/Dron.cpp
        Bibliotecas/DroneEstacionamiento.cpp
        Bibliotecas/DroneSemaforo.cpp
        Bibliotecas/DroneVelocidad.cpp
        Bibliotecas/Nodo.cpp)
