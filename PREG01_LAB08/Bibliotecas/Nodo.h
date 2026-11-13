//
// Created by jdomi on 12/11/2026.
//

#ifndef PREG01_LAB08_NODO_H
#define PREG01_LAB08_NODO_H
#include "DetalleComanda.h"


class Nodo {
private:
    DetalleComanda dato;
    Nodo *sig;
    friend class Cola;
public:

};


#endif //PREG01_LAB08_NODO_H