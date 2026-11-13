//
// Created by jdomi on 12/11/2026.
//

#include "Nodo.h"

#include <cstring>

#include "DroneEstacionamiento.h"
#include "DroneSemaforo.h"
#include "DroneVelocidad.h"

Nodo::Nodo() {
    dron=nullptr;
    izq=nullptr;
    der=nullptr;
}

Nodo::~Nodo() {
    delete dron;
}

void Nodo::asignaMemoria(char *tipo) {
    if(strcmp(tipo,"Velocidad")==0)
        dron = new DroneVelocidad;
    else{
        if (strcmp(tipo,"Semaforo")==0)
            dron = new DroneSemaforo;
        else
            dron= new DroneEstacionamiento;
    }
}

void Nodo::leeDron(ifstream &arch) {
    dron->leer(arch);
}

int Nodo::cmp(Nodo &nuevo) {
    char cad1[10],cad2[10];
    dron->get_id(cad1);
    nuevo.dron->get_id(cad2);
    if(strcmp(cad1,cad2)>=0) return 1;
    return 0;
}
