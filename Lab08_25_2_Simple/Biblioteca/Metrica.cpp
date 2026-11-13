//
// Created by Alan on 11/06/2026.
//

#include <cstring>
using namespace std;
#include "Metrica.h"

Metrica::Metrica() {
    id=0;
    descripcion=nullptr;
    fecha_calculo=0;
    fecha_expiracion=0;
    estado=true;
}
Metrica::~Metrica() {
    if (descripcion!=nullptr)
        delete descripcion;
}
Metrica::Metrica(const Metrica &obj) {
    id=obj.id;
    if (obj.descripcion!=nullptr) {
        descripcion = new char[strlen(obj.descripcion)+1];
        strcpy(descripcion,obj.descripcion);
    }
    else
        descripcion=nullptr;
    fecha_calculo = obj.fecha_calculo;
    fecha_expiracion = obj.fecha_expiracion;
    estado = obj.estado;
}
int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}

void Metrica::set_fecha_calculo(int fecha_calculo) {
    this->fecha_calculo = fecha_calculo;
}

int Metrica::get_id() const {
    return id;
}

void Metrica::set_id(int id) {
    this->id = id;
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

void Metrica::get_descripcion(char *cad) const {
    if (descripcion==nullptr)
        cad[0]=0;
    else
        strcpy(cad, descripcion);
}

void Metrica::set_descripcion(const char *cad) {
    if (descripcion!=nullptr)
        delete descripcion;
    descripcion = new char[strlen(cad)+1];
    strcpy(descripcion,cad);
}

void Metrica::leer(ifstream &arch) {
    int id_stream,dd,mm,aa,de,me,ae;
    char c, desc[60]{};

    arch>>id_stream>>c>>id>>c;
    arch.getline(desc,60,',');
    set_descripcion(desc);
    arch>>aa>>c>>mm>>c>>dd>>c;
    set_fecha_calculo(aa*10000+mm*100+dd);
    arch>>ae>>c>>me>>c>>de>>c;
    set_fecha_expiracion(ae*10000+me*100+de);
    if (fecha_calculo>=fecha_expiracion)
        estado = false;
}

void Metrica::imprimir(ofstream &arch) {
    arch.fill('0');
    arch<<setw(4)<<id;
    arch.fill(' ');
    arch<<" "<<setw(30)<<left<<descripcion<<setw(15)<<left<<fecha_calculo
        <<setw(15)<<left<<fecha_expiracion;
    if (estado)
        arch<<setw(10)<<left<<"ACTIVA";
    else
        arch<<setw(10)<<left<<"EXPIRADA";
}
