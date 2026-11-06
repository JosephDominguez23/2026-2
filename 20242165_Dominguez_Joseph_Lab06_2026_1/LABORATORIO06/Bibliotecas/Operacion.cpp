//
// Created by jdomi on 31/10/2026.
//

#include "Operacion.h"

#include <iomanip>

Operacion::Operacion() {
    nummedicos=0;
    total=0;
    anesteciageneral=false;
}

bool Operacion::is_anesteciageneral() const {
    return anesteciageneral;
}

void Operacion::set_anesteciageneral(bool anesteciageneral) {
    this->anesteciageneral = anesteciageneral;
}

int Operacion::get_nummedicos() const {
    return nummedicos;
}

void Operacion::set_nummedicos(int nummedicos) {
    this->nummedicos = nummedicos;
}

double Operacion::get_total() const {
    return total;
}

void Operacion::set_total(double total) {
    this->total = total;
}

void Operacion::leerOperacion(ifstream &arch) {
    //100,0,1
    Cita::leercita(arch);
    arch>>total;
    arch.get();
    int valor;
    arch>>valor;
    arch.get();
    arch>>nummedicos;
    arch.get();
    if (valor) anesteciageneral = true;
}

void Operacion::imprimeOperacion(ofstream &arch) {
    Cita::imprimirCita(arch);
    arch<<right<<setw(10);
    if (anesteciageneral) arch<<"General";
    else arch<<"Parcial";
    arch<<setw(21)<<nummedicos<<endl;
}
