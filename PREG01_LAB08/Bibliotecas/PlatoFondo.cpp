//
// Created by jdomi on 12/11/2026.
//

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina = 0;
}


int PlatoFondo::get_proteina() const {
    return proteina;
}

void PlatoFondo::set_proteina(int proteina) {
    this->proteina = proteina;
}

void PlatoFondo::leer(ifstream &arch) {
    //Pasta Alfredo,10,4
    Producto::leer(arch);
    arch>>proteina;
}
