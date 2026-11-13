//
// Created by jdomi on 12/11/2026.
//

#ifndef PREG01_LAB08_ENTRADA_H
#define PREG01_LAB08_ENTRADA_H
#include "Producto.h"


class Entrada:public Producto {
private:
    bool picante;
public:
    Entrada();

    bool is_picante() const;
    void set_picante(bool picante);
    void leer(ifstream &);
};


#endif //PREG01_LAB08_ENTRADA_H