//
// Created by jdomi on 12/11/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_ARBOL_H
#define LAB08_ARBOL_DRONES_PARTE1_ARBOL_H
#include "Nodo.h"


class Arbol {
private:
    Nodo *raiz;
public:
    Arbol();
    void inserta(ifstream &arch);
    void imprimerep(ofstream &arch);
    void enorden(ofstream &arch, Nodo *nodo);
    void actualiza();
    int cuenta(Nodo *ptr,char car);
    void recorre(Nodo *&parbol, int &n, char tipo, int valor);
};


#endif //LAB08_ARBOL_DRONES_PARTE1_ARBOL_H