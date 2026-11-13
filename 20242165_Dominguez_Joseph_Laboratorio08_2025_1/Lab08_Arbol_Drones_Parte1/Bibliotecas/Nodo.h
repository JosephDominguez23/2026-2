//
// Created by jdomi on 12/11/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_NODO_H
#define LAB08_ARBOL_DRONES_PARTE1_NODO_H
#include "Dron.h"


class Nodo {
private:
    Dron *dron;
    Nodo *izq;
    Nodo *der;
public:
    Nodo();
    virtual ~Nodo();
    friend class Arbol;
    void asignaMemoria(char *tipo);
    void leeDron(ifstream &arch);
    int cmp(Nodo &nuevo);
};


#endif //LAB08_ARBOL_DRONES_PARTE1_NODO_H