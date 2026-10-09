cmake_minimum_required(VERSION 4.0)
project(CLASES_OBJETOS_Y_SOBRECARGAS)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLASES_OBJETOS_Y_SOBRECARGAS main.cpp
        Bibliotecas/Mascota.cpp
        Bibliotecas/Mascota.h
        Bibliotecas/VacunaAplicada.cpp
        Bibliotecas/VacunaAplicada.h
        Bibliotecas/Veterinaria.cpp
        Bibliotecas/Veterinaria.h)
