//
// Created by Alan on 11/06/2026.
//

#ifndef LAB08_25_2_METRICABASICA_H
#define LAB08_25_2_METRICABASICA_H
#include "Metrica.h"


class MetricaBasica:public Metrica {
private:
    double horas_transmitidas;
    int espectadores_promedio;

public:
    MetricaBasica();
    double get_horas_transmitidas() const;
    void set_horas_transmitidas(double horas_transmitidas);
    int get_espectadores_promedio() const;
    void set_espectadores_promedio(int espectadores_promedio);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    const char* tipoMetrica() const;
};


#endif //LAB08_25_2_METRICABASICA_H
