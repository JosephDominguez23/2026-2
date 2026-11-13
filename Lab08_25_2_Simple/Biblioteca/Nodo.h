//
// Created by Alan on 17/06/2026.
//

#ifndef LAB08_25_2_SIMPLE_NODO_H
#define LAB08_25_2_SIMPLE_NODO_H
#include "Metrica.h"


class Nodo {
private:
    Metrica *metrica;
    Nodo *siguiente;
public:
    Nodo();
    void cargarNodo(ifstream &arch);
    void imprimirNodo(ofstream &arch);
    int cmp(Nodo &nuevo);
    friend class Lista;
    const char *obtenerTipo();
    bool esActiva();

};


#endif //LAB08_25_2_SIMPLE_NODO_H
