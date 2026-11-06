//
// Created by jdomi on 31/10/2026.
//

#include "Entrada.h"

#include <cstring>
#include <iomanip>

Entrada::Entrada() {
    picante=false;
}


bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}

void Entrada::leeentrada(ifstream &arch) {
    //142,E,Bruschetta,4,picante
    char cad[100];
    leeproducto(arch);
    arch.getline(cad,100);
    if (strcmp(cad,"picante")==0)
        picante=true;
}

void Entrada::imprimeentrada(ofstream &arch) {
    double precio;
    imprimeproducto(arch,precio);
    arch<<left;
    if (picante)
        arch << setw(20) << "Picante";
    else
        arch << setw(20) << "Sin picante";
    arch <<right<< setw(10)<< precio << endl;
}

