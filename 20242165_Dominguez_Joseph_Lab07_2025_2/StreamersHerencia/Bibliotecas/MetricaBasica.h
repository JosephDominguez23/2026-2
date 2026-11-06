//
// Created by jdomi on 5/11/2026.
//

#ifndef STREAMERSHERENCIA_METRICABASICA_H
#define STREAMERSHERENCIA_METRICABASICA_H
#include "Metrica.h"
#include <fstream>
using namespace std;

class MetricaBasica:public Metrica{
private:
    double horas_transmitidas;
    int espectadores_promedio;
public:
    MetricaBasica();

    double get_horas_transmitidas() const;
    void set_horas_transmitidas(double horas_transmitidas);
    int get_espectadores_promedio() const;
    void set_espectadores_promedio(int espectadores_promedio);

    void leerBasica(ifstream &);
    void imprimirBasica(ofstream &);
    void operator=(MetricaBasica &);
};


#endif //STREAMERSHERENCIA_METRICABASICA_H