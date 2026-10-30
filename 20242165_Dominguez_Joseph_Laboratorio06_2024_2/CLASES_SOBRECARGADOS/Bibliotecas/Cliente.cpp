//
// Created by jdomi on 28/10/2026.
//

#include "Cliente.h"

#include <cstring>
#include <iomanip>

Cliente::Cliente() {
    dni=0;
    nombre=nullptr;
    distrito=nullptr;
    descuento=0;
    totalPagado=0;
}

Cliente::~Cliente() {
    if (nombre!=nullptr) delete nombre;
    if (distrito!=nullptr) delete distrito;
}


int Cliente::get_dni() const {
    return dni;
}

void Cliente::set_dni(int dni) {
    this->dni = dni;
}

double Cliente::get_descuento() const {
    return descuento;
}

void Cliente::set_descuento(double descuento) {
    this->descuento = descuento;
}

double Cliente::get_total_pagado() const {
    return totalPagado;
}

void Cliente::set_total_pagado(double total_pagado) {
    totalPagado = total_pagado;
}

void Cliente::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Cliente::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre,this->nombre);
}

void Cliente::set_distrito(const char *distrito) {
    if (this->distrito!=nullptr) delete this->distrito;
    this->distrito=new char[strlen(distrito)+1];
    strcpy(this->distrito,distrito);
}

void Cliente::get_distrito(char *distrito) {
    if (this->distrito!=nullptr)
        strcpy(distrito,this->distrito);
}

void operator>>(ifstream &arch,Cliente &clie) {
    char nom[100],dist[100],c;
    int dni;
    double descuento;
    arch>>dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nom,100,',');
    arch.getline(dist,100,',');
    arch>>c;
    if (c=='S') {
        arch.get();
        arch>>descuento>>c;
        clie.set_descuento(descuento);
    }
    clie.set_dni(dni);
    clie.set_nombre(nom);
    clie.set_distrito(dist);
}

void Cliente::operator=(Cliente &orig) {
    dni=orig.dni;
    if (orig.nombre!=nullptr)
        set_nombre(orig.nombre);
    if (orig.distrito!=nullptr)
        set_distrito(orig.distrito);
    descuento=orig.descuento;
    totalPagado=orig.totalPagado;
}

void operator<<(ofstream &arch,Cliente &clie) {
    char nom[100],dist[100];
    clie.get_nombre(nom);
    clie.get_distrito(dist);
    arch<<setw(20)<<clie.get_dni()<<"   "<<left<<setw(50)<<nom<<setw(50)<<dist<<right
        <<setw(20)<<clie.get_descuento()<<"%"<<setw(20)<<clie.get_total_pagado()<<endl;
}