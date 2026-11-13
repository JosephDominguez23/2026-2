//
// Created by jdomi on 12/11/2026.
//

#ifndef PREG01_LAB08_DETALLECOMANDA_H
#define PREG01_LAB08_DETALLECOMANDA_H
#include "Producto.h"


class DetalleComanda {
private:
    int id;
    Producto *pedido;
public:
    DetalleComanda();

    int get_id() const;
    void set_id(int id);
    void leerComanda(ifstream &,int);
    void operator =(DetalleComanda &);
};


#endif //PREG01_LAB08_DETALLECOMANDA_H