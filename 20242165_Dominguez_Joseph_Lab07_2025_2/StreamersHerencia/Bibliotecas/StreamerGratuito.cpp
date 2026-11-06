//
// Created by jdomi on 5/11/2026.
//

#include "StreamerGratuito.h"


StreamerGratuito::StreamerGratuito() {
    fecha_fin_trial = 0;
    cantidad_metricas_basicas = 0;
    metricas_basicas = nullptr;
}

StreamerGratuito::~StreamerGratuito() {
    if (metricas_basicas!=nullptr) delete []metricas_basicas;
}


int StreamerGratuito::get_fecha_fin_trial() const {
    return fecha_fin_trial;
}

void StreamerGratuito::set_fecha_fin_trial(int fecha_fin_trial) {
    this->fecha_fin_trial = fecha_fin_trial;
}

int StreamerGratuito::get_cantidad_metricas_basicas() const {
    return cantidad_metricas_basicas;
}

void StreamerGratuito::set_cantidad_metricas_basicas(int cantidad_metricas_basicas) {
    this->cantidad_metricas_basicas = cantidad_metricas_basicas;
}

void StreamerGratuito::leerGratuito(ifstream &arch) {
    //2025-10-17
    int dia,mes,ano,fecha;
    char c;
    Streamers::leerStreamer(arch);
    arch>>ano>>c>>mes>>c>>dia;
    arch.get();
    fecha=ano*10000+mes*100+dia;
    fecha_fin_trial=fecha;
}

void StreamerGratuito::operator=(StreamerGratuito &orig) {
    Streamers::operator=(orig);
    fecha_fin_trial = orig.fecha_fin_trial;
    cantidad_metricas_basicas = orig.cantidad_metricas_basicas;
    metricas_basicas = orig.metricas_basicas;
}

void StreamerGratuito::actualizarDatos(ifstream &arch) {
    
}
