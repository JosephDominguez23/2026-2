//
// Created by jdomi on 12/11/2026.
//

#include "Bebida.h"

string Bebida::get_tamano() const {
    return tamano;
}

void Bebida::set_tamano(const string &tamano) {
    this->tamano = tamano;
}

void Bebida::leer(ifstream &arch) {
    //Cafe,2,grande
    Producto::leer(arch);
    getline(arch,tamano);
}
