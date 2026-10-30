cmake_minimum_required(VERSION 4.0)
project(OBEJTOS_SOBRECARGA)

set(CMAKE_CXX_STANDARD 20)

add_executable(OBEJTOS_SOBRECARGA main.cpp
        Bibliotecas/Mascota.cpp
        Bibliotecas/Mascota.h
        Bibliotecas/VacunaAplicada.cpp
        Bibliotecas/VacunaAplicada.h
        Bibliotecas/Veterinaria.cpp
        Bibliotecas/Veterinaria.h)
