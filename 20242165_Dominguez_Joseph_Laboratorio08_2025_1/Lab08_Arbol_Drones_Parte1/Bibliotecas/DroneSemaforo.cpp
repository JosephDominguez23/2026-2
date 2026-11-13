//
// Created by jdomi on 12/11/2026.
//

#include "DroneSemaforo.h"

#include <cstring>
#include <iomanip>

int DroneSemaforo::get_luz_roja() const {
    return luz_roja;
}

void DroneSemaforo::set_luz_roja(int luz_roja) {
    this->luz_roja = luz_roja;
}

void DroneSemaforo::leer(ifstream &arch) {
    Dron::leer(arch);
    char cad[20];
    arch.getline(cad,20,'\n');
    if (strcmp(cad,"true")==0) {
        luz_roja=1;
    } else {
        luz_roja=0;
    }
}

void DroneSemaforo::imprimir(ofstream &arch) {
    Dron::imprimir(arch);
    arch<<setw(10)<<luz_roja<<endl;
}

