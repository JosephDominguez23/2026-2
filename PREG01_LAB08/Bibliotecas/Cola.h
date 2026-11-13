//
// Created by jdomi on 12/11/2026.
//

#ifndef PREG01_LAB08_COLA_H
#define PREG01_LAB08_COLA_H
#include "DetalleComanda.h"
#include "Nodo.h"


class Cola {
private:
    int longitud;
    Nodo *cabeza;
    Nodo *cola;
public:
    Cola();

    int get_longitud() const;
    void set_longitud(int longitud);
    void encolar(DetalleComanda &);
    void desencolar(DetalleComanda &);
};


#endif //PREG01_LAB08_COLA_H