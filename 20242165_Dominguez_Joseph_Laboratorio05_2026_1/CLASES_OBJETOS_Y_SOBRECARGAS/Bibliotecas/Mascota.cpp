//
// Created by jdomi on 8/10/2026.
//

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "Mascota.h"
#include "VacunaAplicada.h"


Mascota::Mascota() {
    dni=0;
    nombre=nullptr;
    especie=nullptr;
    edad=0;
    peso=0;
    colegiatura=nullptr;
    numVacunas=0;
}

Mascota::~Mascota() {
    if (nombre!=nullptr) delete nombre;
    if (especie!=nullptr) delete especie;
    if (colegiatura!=nullptr) delete colegiatura;
}

int Mascota::get_dni() const {
    return dni;
}

void Mascota::set_dni(int dni) {
    this->dni = dni;
}

int Mascota::get_edad() const {
    return edad;
}

void Mascota::set_edad(int edad) {
    this->edad = edad;
}

double Mascota::get_peso() const {
    return peso;
}

void Mascota::set_peso(double peso) {
    this->peso = peso;
}

int Mascota::get_num_vacunas() const {
    return numVacunas;
}

void Mascota::set_num_vacunas(int num_vacunas) {
    numVacunas = num_vacunas;
}

void Mascota::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Mascota::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre,this->nombre);
}

void Mascota::set_especie(const char *especie) {
    if (this->especie!=nullptr) delete this->especie;
    this->especie=new char[strlen(especie)+1];
    strcpy(this->especie,especie);
}

void Mascota::get_especie(char *especie) {
    if (this->especie!=nullptr)
        strcpy(especie,this->especie);
}

void Mascota::set_colegiatura(const char *colegiatura) {
    if (this->colegiatura!=nullptr) delete this->colegiatura;
    this->colegiatura=new char[strlen(colegiatura)+1];
    strcpy(this->colegiatura,colegiatura);
}

void Mascota::get_colegiatura(char *colegiatura) {
    if (this->colegiatura!=nullptr)
        strcpy(colegiatura,this->colegiatura);
}

void Mascota::lee_mascota(ifstream &arch) {
    //11223344,Dali,Gato,3,4.2,CMVP-1500
    char cad[50],c;
    arch>>dni;
    if (arch.eof()) return;
    arch>>c;
    arch.getline(cad,50,',');
    set_nombre(cad);
    arch.getline(cad,50,',');
    set_especie(cad);
    arch>>edad>>c>>peso>>c;
    arch.getline(cad,50,'\n');
    set_colegiatura(cad);
}

void Mascota::asigna(Mascota &aux) {
    dni=aux.dni;
    edad=aux.edad;
    peso=aux.peso;
    set_nombre(aux.nombre);
    set_especie(aux.especie);
    set_colegiatura(aux.colegiatura);
}

void Mascota::agrega_vacuna(VacunaAplicada &aux) {
    if (numVacunas<20) {
        listaVacunas[numVacunas].asigna(aux);
        numVacunas++;
    }
}

void Mascota::imprime_mascota(ofstream &arch) {
    arch<<left<<"Mascota : "<<setw(15)
        <<nombre<<" ("<<especie<<", "<<edad
        <<" años, "<<peso<<" kg)"<<endl;
}



bool Mascota::tiene_duplicados() {
    for (int i=0;i<numVacunas;i++) {
        for (int j=i+1;j<numVacunas;j++) {
            if (listaVacunas[i].esigual(listaVacunas[j])) {
                return true;
            }
        }
    }
    return false;
}



void Mascota::imprime_cartilla(ofstream &arch) {
    arch<<endl;
    imprime_mascota(arch);
    if (tiene_duplicados()==true) {
        arch<<"** ALERTA: cartilla con registros duplicados**"<<endl;
    }
    arch<<"Vacunas:"<<endl;
    for (int i=0;i<numVacunas;i++) {
        listaVacunas[i].imprime_vacuna(arch);
    }
}





