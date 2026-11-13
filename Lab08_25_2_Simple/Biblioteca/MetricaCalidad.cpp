//
// Created by Alan on 11/06/2026.
//

#include "MetricaCalidad.h"


MetricaCalidad::MetricaCalidad() {
    bitrate_promedio_kbps=0;
    porcentaje_frames_perdidos=0;
    fps_promedio=0;
}

int MetricaCalidad::get_bitrate_promedio_kbps() const {
    return bitrate_promedio_kbps;
}

void MetricaCalidad::set_bitrate_promedio_kbps(int bitrate_promedio_kbps) {
    this->bitrate_promedio_kbps = bitrate_promedio_kbps;
}

double MetricaCalidad::get_procentaje_frames_perdidos() const {
    return porcentaje_frames_perdidos;
}

void MetricaCalidad::set_procentaje_frames_perdidos(double procentaje_frames_perdidos) {
    this->porcentaje_frames_perdidos = procentaje_frames_perdidos;
}

int MetricaCalidad::get_fps_promedio() const {
    return fps_promedio;
}

void MetricaCalidad::set_fps_promedio(int fps_promedio) {
    this->fps_promedio = fps_promedio;
}

void MetricaCalidad::leer(ifstream &arch) {
    char c;
    Metrica::leer(arch);
    arch>>bitrate_promedio_kbps>>c>>porcentaje_frames_perdidos>>c>>fps_promedio;
}
void MetricaCalidad::imprimir(ofstream &arch) {
    Metrica::imprimir(arch);
    arch<<setw(10)<<right<<bitrate_promedio_kbps
        <<setw(10)<<porcentaje_frames_perdidos<<setw(10)<<right<<fps_promedio<<endl;
}

const char *MetricaCalidad::tipoMetrica() const {
    return "QUALITY";
}
