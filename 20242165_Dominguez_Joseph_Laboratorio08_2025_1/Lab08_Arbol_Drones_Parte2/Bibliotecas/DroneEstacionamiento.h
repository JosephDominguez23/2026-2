//
// Created by jdomi on 12/11/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_DRONEESTACIONAMIENTO_H
#define LAB08_ARBOL_DRONES_PARTE1_DRONEESTACIONAMIENTO_H
#include "Dron.h"
#include <fstream>
using namespace std;

class DroneEstacionamiento:public Dron{
private:
    int zona_carga;
public:
    int get_zona_carga() const;
    void set_zona_carga(int zona_carga);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    char gettipo();
    void cambia(int valor);
};


#endif //LAB08_ARBOL_DRONES_PARTE1_DRONEESTACIONAMIENTO_H