//
// Created by jdomi on 31/10/2026.
//

#ifndef PREG01_LAB07_RESTAURANTE_H
#define PREG01_LAB07_RESTAURANTE_H
#include "Comanda.h"


class Restaurante {
private:
    Comanda comandas[300];
    int cantidad_comandas;
    int buscomandas(int);
public:
    Restaurante();

    int get_cantidad_comandas() const;
    void set_cantidad_comandas(int cantidad_comandas);
    void cargar_comandas();
    void imprimir_comandas();
};


#endif //PREG01_LAB07_RESTAURANTE_H