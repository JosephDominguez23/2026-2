//
// Created by Alan on 17/06/2026.
//

#ifndef LAB08_25_2_SIMPLE_LISTA_H
#define LAB08_25_2_SIMPLE_LISTA_H
#include "Nodo.h"


class Lista {
private:
    Nodo *ini;
    int longitud;

public:
    Lista();
    int get_longitud() const;
    void set_longitud(int longitud);
    void crearLista(ifstream &arch);
    void insertarEnOrden(Nodo *nuevo);
    void imprimirLista(ofstream &arch);
    void imprimirBloque(ofstream &arch, const char* tipo, int &activas, int &expiradas);
    void eliminar();
    void eliminarNodosLista();
    void liberarNodo(Nodo *eliminar);
};


#endif //LAB08_25_2_SIMPLE_LISTA_H
