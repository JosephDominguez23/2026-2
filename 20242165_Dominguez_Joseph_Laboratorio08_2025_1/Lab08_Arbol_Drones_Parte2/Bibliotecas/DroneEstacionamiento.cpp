//
// Created by jdomi on 12/11/2026.
//

#include "DroneEstacionamiento.h"

#include <cstring>
#include <iomanip>

int DroneEstacionamiento::get_zona_carga() const {
    return zona_carga;
}

void DroneEstacionamiento::set_zona_carga(int zona_carga) {
    this->zona_carga = zona_carga;
}

void DroneEstacionamiento::leer(ifstream &arch) {
    Dron::leer(arch);
    char cad[20];
    arch.getline(cad,20,'\n');
    if (strcmp(cad,"true")==0) {
        zona_carga=1;
    } else {
        zona_carga=0;
    }
}

void DroneEstacionamiento::imprimir(ofstream &arch) {
    Dron::imprimir(arch);
    arch<<setw(10)<<zona_carga<<endl;
}

char DroneEstacionamiento::gettipo() {
    return'E';
}

void DroneEstacionamiento::cambia(int valor) {
    zona_carga=valor;
}
