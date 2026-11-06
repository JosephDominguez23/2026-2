//
// Created by jdomi on 31/10/2026.
//

#include "Bebida.h"

#include <cstring>
#include <iomanip>

Bebida::Bebida() {
    tamano=nullptr;
}

Bebida::~Bebida() {
    if (tamano != nullptr) delete tamano;
}

void Bebida::set_tamano(const char *tamano) {
    if (this->tamano!=nullptr) delete this->tamano;
    this->tamano = new char[strlen(tamano) + 1];
    strcpy(this->tamano, tamano);
}

void Bebida::get_tamano(char *tamano) {
    if (this->tamano!=nullptr)
        strcpy(tamano, this->tamano);
}

void Bebida::leebebida(ifstream &arch) {
    char cad[100];
    leeproducto(arch);
    arch.getline(cad,100);
    set_tamano(cad);
}

void Bebida::imprimirbebida(ofstream &arch) {
    double precio;
    imprimeproducto(arch,precio);
    arch <<left<<setw(20)<< tamano <<right<<setw(10) << precio << endl;
}


