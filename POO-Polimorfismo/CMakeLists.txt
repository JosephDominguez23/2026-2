cmake_minimum_required(VERSION 4.0)
project(POO_Polimorfismo)

set(CMAKE_CXX_STANDARD 20)

add_executable(POO_Polimorfismo main.cpp
        Bibliotecas/Product.cpp
        Bibliotecas/Product.h
        Bibliotecas/StackNode.cpp
        Bibliotecas/StackNode.h
        Bibliotecas/Stack.cpp
        Bibliotecas/Stack.h
        Bibliotecas/Package.cpp
        Bibliotecas/Package.h
        Bibliotecas/StandartPackage.cpp
        Bibliotecas/StandartPackage.h
        Bibliotecas/RefrigeratedPackage.cpp
        Bibliotecas/RefrigeratedPackage.h
        Bibliotecas/QueueNode.cpp
        Bibliotecas/QueueNode.h
        Bibliotecas/Queue.cpp
        Bibliotecas/Queue.h
        Bibliotecas/PackageManager.cpp
        Bibliotecas/PackageManager.h)
