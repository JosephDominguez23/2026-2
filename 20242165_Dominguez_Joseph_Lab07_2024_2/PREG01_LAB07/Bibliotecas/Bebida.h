//
// Created by jdomi on 31/10/2026.
//

#ifndef PREG01_LAB07_BEBIDA_H
#define PREG01_LAB07_BEBIDA_H
#include <fstream>

#include "Producto.h"
using namespace std;

class Bebida:public Producto{
private:
    char *tamano;
public:
    Bebida();
    ~Bebida();

    void set_tamano(const char *tamano);
    void get_tamano(char *tamano);
    void leebebida(ifstream &);
    void imprimirbebida(ofstream &);
};


#endif //PREG01_LAB07_BEBIDA_H