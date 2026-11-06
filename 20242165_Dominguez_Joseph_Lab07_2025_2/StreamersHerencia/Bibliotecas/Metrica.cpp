//
// Created by jdomi on 5/11/2026.
//

#include "Metrica.h"

#include <cstring>

Metrica::Metrica() {
    descripcion=nullptr;
    id=0;
    fecha_calculo=0;
    fecha_expiracion=0;
    estado=true;
}

Metrica::~Metrica() {
    if (descripcion != nullptr) delete descripcion;
}

int Metrica::get_id() const {
    return id;
}

void Metrica::set_id(int id) {
    this->id = id;
}

int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}

void Metrica::set_fecha_calculo(int fecha_calculo) {
    this->fecha_calculo = fecha_calculo;
}

int Metrica::get_fecha_expiracion() const {
    return fecha_expiracion;
}

void Metrica::set_fecha_expiracion(int fecha_expiracion) {
    this->fecha_expiracion = fecha_expiracion;
}

bool Metrica::is_estado() const {
    return estado;
}

void Metrica::set_estado(bool estado) {
    this->estado = estado;
}

void Metrica::set_descripcion(const char *descripcion) {
    if (this->descripcion != nullptr) delete this->descripcion;
    this->descripcion=new char[strlen(descripcion)+1];
    strcpy(this->descripcion,descripcion);
}

void Metrica::get_descripcion(char *descripcion) {
    if (this->descripcion != nullptr)
        strcpy(descripcion,this->descripcion);
}


void Metrica::leerMetrica(ifstream &arch) {
    //121,Maratón de chat,2025-10-17,2025-10-31,
    char cad[100],c;
    int dia,mes,ano;
    arch>>id>>c;
    arch.getline(cad,100,',');
    arch>>ano>>c>>mes>>c>>dia>>c;
    fecha_calculo=ano*10000+mes*100+dia;
    arch>>ano>>c>>mes>>c>>dia;
    arch.get();
    fecha_expiracion=ano*10000+mes*100+dia;
    if (fecha_calculo>fecha_expiracion) {
        estado=false;
    }
}

void Metrica::imprimirMetrica(ofstream &arch) {

}

void Metrica::operator=(Metrica &orig) {
    if (orig.descripcion != nullptr)
        set_descripcion(orig.descripcion);
    id=orig.id;
    fecha_calculo=orig.fecha_calculo;
    fecha_expiracion=orig.fecha_expiracion;
    estado=orig.estado;
}



