//
// Created by Alan on 11/06/2026.
//

#include "MetricaBasica.h"

MetricaBasica::MetricaBasica() {
    horas_transmitidas = 0;
    espectadores_promedio = 0;
}



double MetricaBasica::get_horas_transmitidas() const {
    return horas_transmitidas;
}

void MetricaBasica::set_horas_transmitidas(double horas_transmitidas) {
    this->horas_transmitidas = horas_transmitidas;
}

int MetricaBasica::get_espectadores_promedio() const {
    return espectadores_promedio;
}

void MetricaBasica::set_espectadores_promedio(int espectadores_promedio) {
    this->espectadores_promedio = espectadores_promedio;
}

void MetricaBasica::leer(ifstream &arch) {
    char c;
    Metrica::leer(arch);
    arch>>horas_transmitidas>>c>>espectadores_promedio;
}

void MetricaBasica::imprimir(ofstream &arch) {
    Metrica::imprimir(arch);
    arch<<setw(10)<<right<<horas_transmitidas<<setw(10)<<right<<espectadores_promedio<<endl;
}

const char *MetricaBasica::tipoMetrica() const {
    return "BASIC";
}
