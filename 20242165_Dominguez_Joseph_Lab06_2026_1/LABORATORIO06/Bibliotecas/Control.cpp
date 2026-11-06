//
// Created by jdomi on 31/10/2026.
//

#include "Control.h"

#include <iomanip>

Control::Control() {
    costo=0;
    codmed=0;
}

double Control::get_costo() const {
    return costo;
}

void Control::set_costo(double costo) {
    this->costo = costo;
}

int Control::get_codmed() const {
    return codmed;
}

void Control::set_codmed(int codmed) {
    this->codmed = codmed;
}

void Control::leerControl(ifstream &arch) {
    //1222,20
    Cita::leercita(arch);
    char c;
    arch>>codmed>>c>>costo;
    arch.get();
}

void Control::operator=(Control &orig) {
    Cita::operator=(orig);
    costo=orig.costo;
    codmed=orig.codmed;
}

void Control::imprimeControl(ofstream &arch) {
    Cita::imprimirCita(arch);
    arch<<right<<setw(10)<<codmed<<setw(10)<<costo<<endl;
}
