//
// Created by jdomi on 12/11/2026.
//

#include "DroneVelocidad.h"

#include <iomanip>

double DroneVelocidad::get_velocidad_maxima_permitida() const {
    return velocidad_maxima_permitida;
}

void DroneVelocidad::set_velocidad_maxima_permitida(double velocidad_maxima_permitida) {
    this->velocidad_maxima_permitida = velocidad_maxima_permitida;
}

void DroneVelocidad::leer(ifstream &arch) {
    Dron::leer(arch);
    arch>>velocidad_maxima_permitida;
    arch.get();
}

void DroneVelocidad::imprimir(ofstream &arch) {
    Dron::imprimir(arch);
    arch<<setw(10)<<velocidad_maxima_permitida<<endl;
}

