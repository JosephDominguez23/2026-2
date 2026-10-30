//
// Created by jdomi on 29/10/2026.
//

#include "MinisterioDeTransporte.h"

#include <iomanip>
#include <iostream>

MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones=nullptr;
    numInf=0;
    numEmp=0;
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
    if (infracciones!=nullptr) delete[] infracciones;
}

int MinisterioDeTransporte::get_num_inf() const {
    return numInf;
}

void MinisterioDeTransporte::set_num_inf(int num_inf) {
    numInf = num_inf;
}

int MinisterioDeTransporte::get_num_emp() const {
    return numEmp;
}

void MinisterioDeTransporte::set_num_emp(int num_emp) {
    numEmp = num_emp;
}

void MinisterioDeTransporte::operator<(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    Infraccion buffer[300];
    while (true) {
        arch>>buffer[numInf];
        if (arch.eof()) break;
        numInf++;
    }
    infracciones = new Infraccion[numInf+1];
    for (int i = 0; i < numInf; i++) {
        infracciones[i]=buffer[i];
    }
}

void MinisterioDeTransporte::operator<=(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        arch>>empresas[numEmp];
        if (arch.eof()) break;
        numEmp++;
    }
}

void MinisterioDeTransporte::operator<<=(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    Multa mul;
    double valorMulta;
    char pl[9];
    while (true) {
        arch>>mul;
        if (arch.eof()) break;
        valorMulta=buscarMulta(mul.get_codigo_infraccion());
        if (valorMulta>0) {
            mul.set_multa(valorMulta);
        }
        mul.get_placa(pl);
        int posEmp=buscarEmpresa(pl);
        if (posEmp!=-1) {
            empresas[posEmp]+=mul;
        }
    }
}

int MinisterioDeTransporte::buscarMulta(int inf) {
    for (int i = 0; i < numInf; i++) {
        if (infracciones[i].get_codigo()==inf)
            return infracciones[i].get_multa();
    }
}

int MinisterioDeTransporte::buscarEmpresa(char *pl) {
    for (int i = 0; i < numEmp; i++) {
        if (empresas[i].tieneLaPlaca(pl)) return i;
    }
    return -1;
}

void MinisterioDeTransporte::operator>>(const char *nom) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    arch<<setw(50)<<"MINISTERIO DE TRANSPORTE"<<endl;
    arch<<setw(50)<<"TABLA DE INFRACCIONES"<<endl;
    for (int i = 0; i < numInf; i++) {
        arch<<infracciones[i];
    }
    arch<<setw(50)<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    for (int i = 0; i < numEmp; i++) {
        arch<<empresas[i];
    }
}

