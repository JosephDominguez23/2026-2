cmake_minimum_required(VERSION 4.0)
project(StreamersHerencia)

set(CMAKE_CXX_STANDARD 20)

add_executable(StreamersHerencia main.cpp
        Bibliotecas/Metrica.cpp
        Bibliotecas/Metrica.h
        Bibliotecas/MetricaBasica.cpp
        Bibliotecas/MetricaBasica.h
        Bibliotecas/MetricaEngagement.cpp
        Bibliotecas/MetricaEngagement.h
        Bibliotecas/MetricaCalidad.cpp
        Bibliotecas/MetricaCalidad.h
        Bibliotecas/Streamers.cpp
        Bibliotecas/Streamers.h
        Bibliotecas/StreamerGratuito.cpp
        Bibliotecas/StreamerGratuito.h
        Bibliotecas/StreamerPago.cpp
        Bibliotecas/StreamerPago.h
        Bibliotecas/GestorStreamers.cpp
        Bibliotecas/GestorStreamers.h)
