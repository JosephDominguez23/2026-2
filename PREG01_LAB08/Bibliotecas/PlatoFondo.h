//
// Created by jdomi on 12/11/2026.
//

#ifndef PREG01_LAB08_PLATOFONDO_H
#define PREG01_LAB08_PLATOFONDO_H
#include "Producto.h"


class PlatoFondo: public Producto{
private:
    int proteina;
public:
    PlatoFondo();

    int get_proteina() const;
    void set_proteina(int proteina);
    void leer(ifstream &);
};


#endif //PREG01_LAB08_PLATOFONDO_H