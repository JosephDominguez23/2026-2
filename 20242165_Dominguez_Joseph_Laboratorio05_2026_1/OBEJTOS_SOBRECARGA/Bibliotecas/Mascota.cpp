//
// Created by jdomi on 29/10/2026.
//

#include "Mascota.h"

#include <cstring>
#include <iomanip>
using namespace std;

Mascota::Mascota() {
    nombre=nullptr;
    especie=nullptr;
    colegiatura=nullptr;
    dni=0;
    edad=0;
    peso=0;
    numVacunas=0;
}

Mascota::~Mascota() {
    if (nombre!=nullptr) delete nombre;
    if (especie!=nullptr) delete especie;
    if (colegiatura!=nullptr) delete colegiatura;
}

Mascota::Mascota(const Mascota &orig) {
    nombre=nullptr;
    especie=nullptr;
    colegiatura=nullptr;
    *this=orig;
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
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Mascota::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre, this->nombre);
}

void Mascota::set_especie(const char *especie) {
    if (this->especie!=nullptr) delete this->especie;
    this->especie = new char[strlen(especie)+1];
    strcpy(this->especie, especie);
}

void Mascota::get_especie(char *especie) {
    if (this->especie!=nullptr)
        strcpy(especie, this->especie);
}

void Mascota::set_colegiatura(const char *colegiatura) {
    if (this->colegiatura!=nullptr) delete this->colegiatura;
    this->colegiatura = new char[strlen(colegiatura)+1];
    strcpy(this->colegiatura, colegiatura);
}

void Mascota::get_colegiatura(char *colegiatura) {
    if (this->colegiatura!=nullptr)
        strcpy(colegiatura, this->colegiatura);
}

void Mascota::operator=(const Mascota &orig) {
    if (orig.nombre!=nullptr)
        set_nombre(orig.nombre);
    if (orig.especie!=nullptr)
        set_especie(orig.especie);
    if (orig.colegiatura!=nullptr)
        set_colegiatura(orig.colegiatura);
    dni=orig.dni;
    edad=orig.edad;
    peso=orig.peso;
    numVacunas=orig.numVacunas;
}

void operator>>(ifstream &arch, Mascota &pet) {
    //11223344,Michi,Gato,4,5.1,CMVP-6002
    int dni,edad;
    double peso;
    char nombre[100],especie[100],colegiatura[100],c;
    arch>>dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(nombre,100,',');
    arch.getline(especie,100,',');
    arch>>edad>>c>>peso>>c;
    arch.getline(colegiatura,100,'\n');
    pet.set_dni(dni);
    pet.set_nombre(nombre);
    pet.set_especie(especie);
    pet.set_edad(edad);
    pet.set_peso(peso);
    pet.set_colegiatura(colegiatura);
}

void Mascota::operator+=(const VacunaAplicada &vacuna) {
    listaVacunas[numVacunas]=vacuna;
    numVacunas++;
}

bool Mascota::operator~() {
    for (int i = 0; i < numVacunas-1; i++) {
        for (int j = i+1; j < numVacunas; j++) {
            if (listaVacunas[i]==listaVacunas[j]) return true;
        }
    }
    return false;
}

void operator<<(ofstream &arch, Mascota &pet) {
    char nom[100],esp[100];
    pet.get_nombre(nom);
    pet.get_especie(esp);
    arch<<"Mascota : "<<left<<nom<<" ("<<esp<<", "<<right<<pet.get_edad()<<" años, "
        <<pet.get_peso()<<" kg)"<<endl;
}

void Mascota::imprimirVacuna(ofstream &arch) {
    arch<<"Vacunas:"<<endl;
    for (int i = 0; i < numVacunas; i++) {
        arch<<listaVacunas[i];
    }
}
