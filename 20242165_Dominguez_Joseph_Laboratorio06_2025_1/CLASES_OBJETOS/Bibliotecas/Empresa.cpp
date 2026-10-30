//
// Created by jdomi on 29/10/2026.
//

#include "Empresa.h"

#include <cstring>
#include <iomanip>

Empresa::Empresa() {
    nombre=nullptr;
    numMultas=0;
    numPlacas=0;
    for(int i=0; i< 10; i++) placas[i]=nullptr;
}

Empresa::~Empresa() {
    if (nombre!=nullptr) delete nombre;
    for (int i = 0; i < 10; i++) {
        if (placas[i]!=nullptr)
            delete placas[i];
    }
}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

int Empresa::get_num_placas() const {
    return numPlacas;
}

void Empresa::set_num_placas(int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_num_multas() const {
    return numMultas;
}

void Empresa::set_num_multas(int num_multas) {
    numMultas = num_multas;
}

void Empresa::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Empresa::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre, this->nombre);
}

void Empresa::setPlacaI(const char *pl, int i) {
    if (placas[i]!=nullptr) delete placas[i];
    placas[i] = new char[strlen(pl)+1]();
    strcpy(placas[i], pl);
}

void Empresa::getPlacaI(char *pl, int i) {
    if (placas[i]==nullptr) pl[0]=0;
    else strcpy(pl, placas[i]);
}

void operator>>(ifstream &arch,Empresa &emp) {
    //87282766,Suarez Chang Gloria,M440-802
    emp.leer(arch);
}

void Empresa::leer(ifstream &arch) {
    char aux[60], pl[9];
    arch>>dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(aux, 60,',');
    set_nombre(aux);
    while (true){
        arch.get(pl,9);
        setPlacaI(pl,numPlacas);
        numPlacas++;
        if (arch.get() == '\n') break;
        }
}

bool Empresa::tieneLaPlaca(const char *pl) {
    for (int i = 0; i < numPlacas; i++) {
        if (strcmp(placas[i],pl)==0) return true;
    }
    return false;
}

void Empresa::operator+=(Multa &mul) {
    multas[numMultas]=mul;
    numMultas++;
}

void operator<<(ofstream &arch,Empresa &emp) {
    char nombre[100];
    emp.get_nombre(nombre);
    arch<<setw(10)<<emp.get_dni()<<"  "
        <<left<<setw(50)<<nombre;
    emp.imprimePlacas(arch);
    arch<<endl;
    emp.imprimeMultas(arch);
}

void Empresa::imprimePlacas(ofstream &arch) {
    for (int i = 0; i < numPlacas; i++) {
        arch<<setw(20)<<placas[i];
    }
}

void Empresa::imprimeMultas(ofstream &arch) {
    for (int i = 0; i < numMultas; i++) {
        arch<<multas[i];
    }
}


