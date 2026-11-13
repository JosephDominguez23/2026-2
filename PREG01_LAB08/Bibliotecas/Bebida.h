//
// Created by jdomi on 12/11/2026.
//

#ifndef PREG01_LAB08_BEBIDA_H
#define PREG01_LAB08_BEBIDA_H
#include <string>

#include "Producto.h"
using namespace std;

class Bebida:public Producto{
private:
    string tamano;
public:
    string get_tamano() const;
    void set_tamano(const string &tamano);
    void leer(ifstream &);
};


#endif //PREG01_LAB08_BEBIDA_H