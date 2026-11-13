//
// Created by jdomi on 12/11/2026.
//

#include "Restaurante.h"

#include <iostream>

void Restaurante::carga() {
    int id;
    ifstream arch("ArchivosDeDatos/comandas2.csv", ios::in);
    if (!arch) {
        cout <<"No se puede leer comandas"<<endl;
        exit(1);
    }
    while (true) {
        arch >> id;
        if (arch.eof())break;
        arch.get();
        DetalleComanda aux;
        aux.leerComanda(arch,id);
        Ccomanda.encolar(aux);
    }
}
