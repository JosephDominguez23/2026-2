//
// Created by jdomi on 5/11/2026.
//

#ifndef STREAMERSHERENCIA_METRICACALIDAD_H
#define STREAMERSHERENCIA_METRICACALIDAD_H
#include <fstream>

#include "Metrica.h"
using namespace std;

class MetricaCalidad:public Metrica{
private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedios;
public:
    MetricaCalidad();

    int get_bitrate_promedio_kbps() const;
    void set_bitrate_promedio_kbps(int bitrate_promedio_kbps);
    double get_porcentaje_frames_perdidos() const;
    void set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos);
    int get_fps_promedios() const;
    void set_fps_promedios(int fps_promedios);

    void leerCalidad(ifstream &);
    void imprimirCalidad(ofstream &);
};


#endif //STREAMERSHERENCIA_METRICACALIDAD_H