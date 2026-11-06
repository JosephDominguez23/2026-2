//
// Created by jdomi on 31/10/2026.
//

#ifndef PREG01_LAB07_PLATOFONDO_H
#define PREG01_LAB07_PLATOFONDO_H
#include <fstream>

#include "Producto.h"
using namespace std;

class PlatoFondo:public Producto{
private:
    int *proteina;
public:
    PlatoFondo();
    ~PlatoFondo();

    void leeplato(ifstream &);
    void imprimeplato(ofstream &);
};


#endif //PREG01_LAB07_PLATOFONDO_H