//
// Created by jdomi on 12/11/2026.
//

#include "Cola.h"

Cola::Cola() {
    cabeza=nullptr;
    cola=nullptr;
    longitud=0;
}

int Cola::get_longitud() const {
    return longitud;
}

void Cola::set_longitud(int longitud) {
    this->longitud = longitud;
}

void Cola::encolar(DetalleComanda &dato) {
    Nodo *nuevo=new Nodo;
    nuevo->dato=dato;
    if (longitud==0) {
        cabeza=nuevo;
        cola=nuevo;
    } else {
        cola->sig=nuevo;
        cola=nuevo;
    }
    longitud++;
}

void Cola::desencolar(DetalleComanda &aux) {
    if (longitud!=0) {
        aux=cabeza->dato;
        if (cabeza==cola) cola=nullptr;
        cabeza=cabeza->sig;
    }
    longitud--;
}
