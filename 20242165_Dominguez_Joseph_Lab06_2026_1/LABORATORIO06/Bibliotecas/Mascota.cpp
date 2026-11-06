//
// Created by jdomi on 31/10/2026.
//

#include "Mascota.h"

#include <cstring>
#include <iomanip>

Mascota::Mascota() {
    nombre=nullptr;
    raza=nullptr;
    codigo=0;
    tipo=0;
}

Mascota::~Mascota() {
    if (nombre!=nullptr) delete nombre;
    if (raza!=nullptr) delete raza;
}

int Mascota::get_codigo() const {
    return codigo;
}

void Mascota::set_codigo(int codigo) {
    this->codigo = codigo;
}

char Mascota::get_tipo() const {
    return tipo;
}

void Mascota::set_tipo(char tipo) {
    this->tipo = tipo;
}

void Mascota::set_nombre(const char *nombre) {
    if (this->nombre) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Mascota::get_nombre(char *nombre) {
    if (this->nombre)
        strcpy(nombre, this->nombre);
}

void Mascota::set_raza(const char *raza) {
    if (this->raza) delete this->raza;
    this->raza = new char[strlen(raza) + 1];
    strcpy(this->raza, raza);
}

void Mascota::get_raza(char *raza) {
    if (this->raza)
        strcpy(raza, this->raza);
}

void Mascota::leerMascota(ifstream &arch) {
    //101,Luna,C,Labrador,1222,20
    char cad[100],c;
    arch>>codigo>>c;
    arch.getline(cad,100,',');
    set_nombre(cad);
    arch>>tipo>>c;
    arch.getline(cad,100,',');
    set_raza(cad);
}


void Mascota::operator=(Mascota &orig) {
    char cadena[100];
    codigo = orig.codigo;
    tipo = orig.tipo;
    orig.get_nombre(cadena);
    set_nombre(cadena);
    orig.get_raza(cadena);
    set_raza(cadena);
}

void Mascota::imprimirMascota(ofstream &arch) {
    arch<<left<<setw(20)<<raza<<setw(20)<<nombre;
}
