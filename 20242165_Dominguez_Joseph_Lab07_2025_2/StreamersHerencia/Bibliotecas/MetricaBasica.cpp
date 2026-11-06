//
// Created by jdomi on 5/11/2026.
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

void MetricaBasica::leerBasica(ifstream &arch) {
    //6.5,1116
    char c;
    leerMetrica(arch);
    arch>>horas_transmitidas>>c>>espectadores_promedio;
    arch.get();
}

void MetricaBasica::imprimirBasica(ofstream &arch) {

}

void MetricaBasica::operator=(MetricaBasica &orig) {
    Metrica::operator=(orig);
    horas_transmitidas = orig.horas_transmitidas;
    espectadores_promedio = orig.espectadores_promedio;
}

