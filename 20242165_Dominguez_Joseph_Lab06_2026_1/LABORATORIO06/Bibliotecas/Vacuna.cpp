//
// Created by jdomi on 31/10/2026.
//

#include "Vacuna.h"

#include <iomanip>

Vacuna::Vacuna() {
    dosis=0;
    meses=0;
}

int Vacuna::get_dosis() const {
    return dosis;
}

void Vacuna::set_dosis(int dosis) {
    this->dosis = dosis;
}

int Vacuna::get_meses() const {
    return meses;
}

void Vacuna::set_meses(int meses) {
    this->meses = meses;
}

void Vacuna::leeVacuna(ifstream &arch) {
    //V,8/04/2026,10,101,Luna,C,Labrador,1,12
    Cita::leercita(arch);
    arch>>dosis;
    arch.get();
    arch>>meses;
    arch.get();
}

void Vacuna::imprimirVacuna(ofstream &arch) {
    Cita::imprimirCita(arch);
    arch<<right<<setw(10)<<dosis<<setw(25)<<meses<<endl;
}
