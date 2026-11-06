//
// Created by jdomi on 31/10/2026.
//

#ifndef PREG01_LAB07_ENTRADA_H
#define PREG01_LAB07_ENTRADA_H
#include <fstream>

#include "Producto.h"
using namespace std;

class Entrada:public  Producto {
private:
    bool picante;
public:
    Entrada();

    bool is_picante() const;
    void set_picante(bool picante);
    void leeentrada(ifstream &);
    void imprimeentrada(ofstream &);
};


#endif //PREG01_LAB07_ENTRADA_H