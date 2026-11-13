//
// Created by jdomi on 12/11/2026.
//

#include "Entrada.h"

#include <cstring>

Entrada::Entrada() {
    picante=false;
}

bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}

void Entrada::leer(ifstream &arch) {
    //Quesadillas,5.5,sin picante
    char cad[50];
    Producto::leer(arch);
    arch.getline(cad, 50);
    if (strcmp(cad,"picante")) {
        picante=true;
    }
}
