//
// Created by jdomi on 12/11/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_DRONEVELOCIDAD_H
#define LAB08_ARBOL_DRONES_PARTE1_DRONEVELOCIDAD_H
#include "Dron.h"
#include <fstream>
using namespace std;

class DroneVelocidad: public Dron{
private:
    double velocidad_maxima_permitida;
public:
    double get_velocidad_maxima_permitida() const;
    void set_velocidad_maxima_permitida(double velocidad_maxima_permitida);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
};


#endif //LAB08_ARBOL_DRONES_PARTE1_DRONEVELOCIDAD_H