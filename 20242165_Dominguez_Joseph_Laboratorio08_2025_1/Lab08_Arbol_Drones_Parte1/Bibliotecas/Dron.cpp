//
// Created by jdomi on 12/11/2026.
//

#include "Dron.h"

#include <cstring>
#include <iomanip>

Dron::Dron() {
    capacidad = 0;
    id=nullptr;
    ubicacion=nullptr;
}

Dron::~Dron() {
    if (id!=nullptr) delete id;
    if (ubicacion!=nullptr) delete ubicacion;
}


int Dron::get_capacidad() const {
    return capacidad;
}

void Dron::set_capacidad(int capacidad) {
    this->capacidad = capacidad;
}

void Dron::set_id(const char *id) {
    if (this->id != nullptr) delete id;
    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);
}

void Dron::get_id(char *id) {
    if (this->id != nullptr)
        strcpy(id, this->id);
}

void Dron::set_ubicacion(const char *ubicacion) {
    if (this->ubicacion != nullptr) delete ubicacion;
    this->ubicacion = new char[strlen(ubicacion) + 1];
    strcpy(this->ubicacion, ubicacion);
}

void Dron::get_ubicacion(char *ubicacion) {
    if (this->ubicacion != nullptr)
        strcpy(ubicacion, this->ubicacion);
}


void Dron::leer(ifstream &arch) {
    char cad[50];
    //DV001,Avenida A,5,60
    arch.getline(cad,50,',');
    if (arch.eof()) return;
    set_id(cad);
    arch.getline(cad,50,',');
    set_ubicacion(cad);
    arch>>capacidad;
    arch.get();
}

void Dron::imprimir(ofstream &arch) {
    arch << setw(10) << id << setw(10) << ubicacion << setw(5) << capacidad;
}
