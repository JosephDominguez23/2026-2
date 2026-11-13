//
// Created by jdomi on 12/11/2026.
//

#include "Producto.h"

Producto::Producto() {
    precio=0;
}

string Producto::get_nombre() const {
    return nombre;
}

void Producto::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

double Producto::get_precio() const {
    return precio;
}

void Producto::set_precio(double precio) {
    this->precio = precio;
}

void Producto::leer(ifstream &arch) {
    //Cafe,2,
    getline(arch,nombre,',');
    if (arch.eof()) return;
    arch>>precio;
    arch.get();
}
