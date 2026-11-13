//
// Created by jdomi on 12/11/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_DRONESEMAFORO_H
#define LAB08_ARBOL_DRONES_PARTE1_DRONESEMAFORO_H
#include "Dron.h"
#include <fstream>
using namespace std;

class DroneSemaforo:public Dron{
private:
    int luz_roja;
public:
    int get_luz_roja() const;
    void set_luz_roja(int luz_roja);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    char gettipo();
    void cambia(int valor);
};


#endif //LAB08_ARBOL_DRONES_PARTE1_DRONESEMAFORO_H