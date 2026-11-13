cmake_minimum_required(VERSION 4.2)
project(Lab08_25_2_Simple)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab08_25_2_Simple main.cpp
        Biblioteca/Metrica.h
        Biblioteca/Metrica.cpp
        Biblioteca/MetricaBasica.h
        Biblioteca/MetricaBasica.cpp
        Biblioteca/MetricaEngagement.h
        Biblioteca/MetricaEngagement.cpp
        Biblioteca/MetricaCalidad.cpp
        Biblioteca/MetricaCalidad.h
        Biblioteca/Nodo.cpp
        Biblioteca/Nodo.h
        Biblioteca/Lista.cpp
        Biblioteca/Lista.h
        Biblioteca/AdministrarMetricas.cpp
        Biblioteca/AdministrarMetricas.h)
