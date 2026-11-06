//
// Created by jdomi on 5/11/2026.
//

#include "MetricaCalidad.h"


int MetricaCalidad::get_bitrate_promedio_kbps() const {
    return bitrate_promedio_kbps;
}

void MetricaCalidad::set_bitrate_promedio_kbps(int bitrate_promedio_kbps) {
    this->bitrate_promedio_kbps = bitrate_promedio_kbps;
}

double MetricaCalidad::get_porcentaje_frames_perdidos() const {
    return porcentaje_frames_perdidos;
}

void MetricaCalidad::set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos) {
    this->porcentaje_frames_perdidos = porcentaje_frames_perdidos;
}

int MetricaCalidad::get_fps_promedios() const {
    return fps_promedios;
}

void MetricaCalidad::set_fps_promedios(int fps_promedios) {
    this->fps_promedios = fps_promedios;
}

void MetricaCalidad::leerCalidad(ifstream &arch) {
    //7586,0.063,48
    char c;
    leerMetrica(arch);
    arch>>bitrate_promedio_kbps>>c>>porcentaje_frames_perdidos>>c>>fps_promedios;
    arch.get();
}

void MetricaCalidad::imprimirCalidad(ofstream &arch) {

}
