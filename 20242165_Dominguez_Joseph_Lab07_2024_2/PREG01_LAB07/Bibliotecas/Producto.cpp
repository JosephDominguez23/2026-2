//
// Created by jdomi on 31/10/2026.
//

#include "Producto.h"

#include <cstring>
#include <iomanip>

Producto::Producto() {
    nombre=nullptr;
    precio=0;
}

Producto::~Producto() {
    if (nombre!=nullptr) delete nombre;
}

double Producto::get_precio() const {
    return precio;
}

void Producto::set_precio(double precio) {
    this->precio = precio;
}

void Producto::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Producto::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre, this->nombre);
}

void Producto::leeproducto(ifstream &arch) {
    //142,B,Cafe,2,grande
    char cad[100];
    arch.getline(cad,100,',');
    set_nombre(cad);
    arch>>precio;
    arch.get();
}

void Producto::imprimeproducto(ofstream &arch, double &monto) {
    arch<<"Producto solicitado:  ";
    arch <<left<<setw(50)<< nombre <<right;
    monto = precio;
}



