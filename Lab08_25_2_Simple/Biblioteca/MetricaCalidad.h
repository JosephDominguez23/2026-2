//
// Created by Alan on 11/06/2026.
//

#ifndef LAB08_25_2_METRICACALIDAD_H
#define LAB08_25_2_METRICACALIDAD_H
#include "Metrica.h"


class MetricaCalidad:public Metrica {
private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;

public:
    MetricaCalidad();
    int get_bitrate_promedio_kbps() const;
    void set_bitrate_promedio_kbps(int bitrate_promedio_kbps);
    double get_procentaje_frames_perdidos() const;
    void set_procentaje_frames_perdidos(double procentaje_frames_perdidos);
    int get_fps_promedio() const;
    void set_fps_promedio(int fps_promedio);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    const char* tipoMetrica() const;
};


#endif //LAB08_25_2_METRICACALIDAD_H
