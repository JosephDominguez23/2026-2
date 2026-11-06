//
// Created by jdomi on 5/11/2026.
//

#include "StreamerPago.h"

StreamerPago::StreamerPago() {
    metricas_basicas=nullptr;
    metricas_calidades=nullptr;
    metricas_engagements=nullptr;
    fecha_inicio_plan=0;
    cantidad_metricas_basicas=0;
    cantidad_metricas_calidades=0;
    cantidad_metricas_engagements=0;
}

StreamerPago::~StreamerPago() {
    if (metricas_basicas != nullptr) delete []metricas_basicas;
    if (metricas_calidades != nullptr) delete []metricas_calidades;
    if (metricas_engagements != nullptr) delete []metricas_engagements;
}


int StreamerPago::get_fecha_inicio_plan() const {
    return fecha_inicio_plan;
}

void StreamerPago::set_fecha_inicio_plan(int fecha_inicio_plan) {
    this->fecha_inicio_plan = fecha_inicio_plan;
}

int StreamerPago::get_cantidad_metricas_basicas() const {
    return cantidad_metricas_basicas;
}

void StreamerPago::set_cantidad_metricas_basicas(int cantidad_metricas_basicas) {
    this->cantidad_metricas_basicas = cantidad_metricas_basicas;
}

int StreamerPago::get_cantidad_metricas_engagements() const {
    return cantidad_metricas_engagements;
}

void StreamerPago::set_cantidad_metricas_engagements(int cantidad_metricas_engagements) {
    this->cantidad_metricas_engagements = cantidad_metricas_engagements;
}

int StreamerPago::get_cantidad_metricas_calidades() const {
    return cantidad_metricas_calidades;
}

void StreamerPago::set_cantidad_metricas_calidades(int cantidad_metricas_calidades) {
    this->cantidad_metricas_calidades = cantidad_metricas_calidades;
}

void StreamerPago::leerPago(ifstream &arch) {
    int dia,mes,ano,fecha;
    char c;
    Streamers::leerStreamer(arch);
    arch>>ano>>c>>mes>>c>>dia;
    arch.get();
    fecha=ano*10000+mes*100+dia;
    fecha_inicio_plan=fecha;
}

void StreamerPago::operator=(StreamerPago &orig) {
    Streamers::operator=(orig);
    metricas_basicas=orig.metricas_basicas;
    metricas_calidades=orig.metricas_calidades;
    metricas_engagements=orig.metricas_engagements;
    fecha_inicio_plan=orig.fecha_inicio_plan;
    cantidad_metricas_basicas=orig.cantidad_metricas_basicas;
    cantidad_metricas_calidades=orig.cantidad_metricas_calidades;
    cantidad_metricas_engagements=orig.cantidad_metricas_engagements;
}

void StreamerPago::actualizarEngage(ifstream &arch) {

}

void StreamerPago::actualizarDatosBasic(ifstream &arch) {

}

void StreamerPago::actualizarDatosQualities(ifstream &arch) {

}

