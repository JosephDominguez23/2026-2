//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_COLA_H
#define COLA_COLA_H
#include "NodoCola.h"
struct Cola {
    struct NodoCola * inicio;
    struct NodoCola * fin;
    int longitud;
    int cantidad;
    int k;
    double suma;
};
#endif //COLA_COLA_H