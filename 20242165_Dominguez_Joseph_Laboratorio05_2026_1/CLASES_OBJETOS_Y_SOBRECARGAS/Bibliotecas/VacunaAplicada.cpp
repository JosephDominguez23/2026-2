//
// Created by jdomi on 8/10/2026.
//

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "VacunaAplicada.h"

VacunaAplicada::VacunaAplicada() {
    nombre=nullptr;
    fecha=0;
    dosis=0;
    colegiatura=nullptr;
}

VacunaAplicada::~VacunaAplicada() {
    if (nombre!=nullptr) delete nombre;
    if (colegiatura!=nullptr) delete colegiatura;
}

int VacunaAplicada::get_fecha() const {
    return fecha;
}

void VacunaAplicada::set_fecha(int fecha) {
    this->fecha = fecha;
}

double VacunaAplicada::get_dosis() const {
    return dosis;
}

void VacunaAplicada::set_dosis(double dosis) {
    this->dosis = dosis;
}

void VacunaAplicada::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}


void VacunaAplicada::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre,this->nombre);
}

void VacunaAplicada::set_colegiatura(const char *colegiatura) {
    if (this->colegiatura!=nullptr) delete this->colegiatura;
    this->colegiatura=new char[strlen(colegiatura)+1];
    strcpy(this->colegiatura,colegiatura);
}

void VacunaAplicada::get_colegiatura(char *colegiatura) {
    if (this->colegiatura!=nullptr)
        strcpy(colegiatura,this->colegiatura);
}

void VacunaAplicada::lee_vacuna(ifstream &arch) {
    char cad[100],c;
    arch.getline(cad,100,',');
    if (arch.eof())return;
    set_nombre(cad);
    arch>>fecha>>c>>dosis>>c;
    arch.getline(cad,100,'\n');
    set_colegiatura(cad);
}

void VacunaAplicada::asigna(VacunaAplicada &aux) {
    fecha=aux.fecha;
    dosis=aux.dosis;
    set_nombre(aux.nombre);
    set_colegiatura(aux.colegiatura);
}

bool VacunaAplicada::esigual(VacunaAplicada &vac) {
    char nom[100],colg[100];
    vac.get_nombre(nom);
    vac.get_colegiatura(colg);
    if (fecha==vac.get_fecha() and dosis==vac.get_dosis()
        and strcmp(nombre,nom)==0 and strcmp(colegiatura,colg)==0) {
        return true;
        }
    return false;
}

void VacunaAplicada::imprime_vacuna(ofstream &arch) {
    arch<<left<<"- "<<nombre<<" : ";
    int dd,mm,aa;
    aa=fecha/10000;
    mm=(fecha%10000)/100;
    dd=(fecha%10000)%100;
    arch<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<aa<<setfill(' ')<<" ("<<
        dosis<<" ml, "<<colegiatura<<")"<<endl;
}





