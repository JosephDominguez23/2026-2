//
// Created by jdomi on 29/10/2026.
//

#include "Veterinaria.h"

#include <cstring>
#include <iomanip>
#include <iostream>
#define LINEA 60

Veterinaria::Veterinaria() {
    listaDeMascotas=nullptr;
    numMascotas=0;
}

Veterinaria::~Veterinaria() {
    if (listaDeMascotas!=nullptr) delete [] listaDeMascotas;
}

int Veterinaria::get_num_mascotas() const {
    return numMascotas;
}

void Veterinaria::set_num_mascotas(int num_mascotas) {
    numMascotas = num_mascotas;
}

void Veterinaria::operator<=(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    Mascota buffer[200];
    while (true) {
        arch>>buffer[numMascotas];
        if (arch.eof()) break;
        numMascotas++;
    }
    listaDeMascotas=new Mascota[numMascotas+1];
    for (int i=0;i<numMascotas;i++)
        listaDeMascotas[i]=buffer[i];
}

void Veterinaria::operator<<=(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    char mascota[100],c;
    int dni;
    VacunaAplicada vacuna{};
    while (true) {
        arch.getline(mascota,100,',');
        if (arch.eof()) break;
        arch>>dni>>c;
        arch>>vacuna;
        int pos=buscaMascota(dni,mascota);
        if (pos!=-1) {
            listaDeMascotas[pos]+=vacuna;
        } else {
            while (arch.get()!='\n');
        }
    }
}

int Veterinaria::buscaMascota(int dni, char *mascota) {
    char nomPet[100];
    for (int i=0;i<numMascotas;i++) {
        listaDeMascotas[i].get_nombre(nomPet);
        if (dni==listaDeMascotas[i].get_dni() and (strcmp(mascota,nomPet)==0)) return i;
    }
    return -1;
}

void Veterinaria::operator<<(const char *nom) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    int dniPrev=0;
    arch<<setprecision(2)<<fixed;
    imprimirLinea(arch,'=',LINEA);
    arch<<"REPORTE DE CARTILLAS - VETERINARIA HUELLITAS Y PLUMITAS"<<endl;
    imprimirLinea(arch,'=',LINEA);
    for (int i=0;i<numMascotas;i++) {
        int dniActual=listaDeMascotas[i].get_dni();
        if (dniActual!=dniPrev) {
            if (dniPrev)imprimirLinea(arch,'-',LINEA);
            arch<<"DNI : "<<dniActual<<endl;
            dniPrev=dniActual;
        }
        arch<<listaDeMascotas[i];
        if (~listaDeMascotas[i])
            arch<<"** ALERTA: cartilla con registros duplicados**"<<endl;
        listaDeMascotas[i].imprimirVacuna(arch);
    }
    imprimirLinea(arch,'=',LINEA);
}

void Veterinaria::imprimirLinea(ofstream &arch,char car,int n) {
    for (int i=0;i<n;i++) arch.put(car);
    arch<<endl;
}

