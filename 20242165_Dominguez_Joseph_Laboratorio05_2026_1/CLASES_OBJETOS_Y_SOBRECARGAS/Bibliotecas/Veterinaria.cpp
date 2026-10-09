//
// Created by jdomi on 8/10/2026.
//

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "Veterinaria.h"

Veterinaria::Veterinaria() {
    numMascotas = 0;
}

void Veterinaria::cargarMascota(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        Mascota aux;
        aux.lee_mascota(arch);
        if (arch.eof()) break;
        listaDeMascotas[numMascotas].asigna(aux);
        numMascotas++;
    }
}

void Veterinaria::cargaVacunas(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    char nommascota[100],c;
    int dni;
    while (true) {
        arch.getline(nommascota,100,',');
        if (arch.eof())break;
        arch>>dni>>c;
        VacunaAplicada aux;
        aux.lee_vacuna(arch);
        int posmascota=buscaMascota(dni,nommascota);
        if (posmascota!=-1) {
            asignavacuna(posmascota,aux);
        }
    }
}

int Veterinaria::buscaMascota(int dni, char *nombre) {
    char auxmascota[100];
    for (int i = 0; i < numMascotas; i++) {
        if (listaDeMascotas[i].get_dni()==dni) {
            listaDeMascotas[i].get_nombre(auxmascota);
            if (strcmp(auxmascota, nombre)==0) return i;
        }
    }
    return -1;
}


void Veterinaria::asignavacuna(int pos, VacunaAplicada &aux) {
    listaDeMascotas[pos].agrega_vacuna(aux);
}

void Veterinaria::imprime_reporte(const char *nom) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    imprimirLinea(arch,'=');
    arch<<"REPORTE DE CARTILLAS - VETERINARIA HUELLITAS Y PLUMITAS"<<endl;
    imprimirLinea(arch,'=');
    int dniactual=-1,deni;
    for (int i=0;i<numMascotas;i++) {
        deni=listaDeMascotas[i].get_dni();
        if (deni!=dniactual) {
            if (i>0)imprimirLinea(arch,'-');
            dniactual=deni;
            arch<<"DNI : "<<deni<<endl;
        }
        listaDeMascotas[i].imprime_cartilla(arch);
    }
    imprimirLinea(arch,'=');
}

void Veterinaria::imprimirLinea(ofstream &arch, char car) {
    for (int i = 0; i < 120; i++) arch.put(car);
    arch<<endl;
}
