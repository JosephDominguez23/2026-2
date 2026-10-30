//
// Created by jdomi on 29/10/2026.
//

#include "VacunaAplicada.h"

#include <cstring>

VacunaAplicada::VacunaAplicada() {
    nombre=nullptr;
    colegiatura=nullptr;
    fecha=0;
    dosis=0;
}

VacunaAplicada::~VacunaAplicada() {
    if (nombre!=nullptr) delete nombre;
    if (colegiatura!=nullptr) delete colegiatura;
}

VacunaAplicada::VacunaAplicada(const VacunaAplicada &orig) {
    nombre=nullptr;
    colegiatura=nullptr;
    *this=orig;
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
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void VacunaAplicada::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre, this->nombre);
}

void VacunaAplicada::set_colegiatura(const char *colegiatura) {
    if (this->colegiatura!=nullptr) delete this->colegiatura;
    this->colegiatura = new char[strlen(colegiatura) + 1];
    strcpy(this->colegiatura, colegiatura);
}

void VacunaAplicada::get_colegiatura(char *colegiatura) {
    if (this->colegiatura!=nullptr)
        strcpy(colegiatura, this->colegiatura);
}

void VacunaAplicada::operator=(const VacunaAplicada &orig) {
    if (orig.nombre!=nullptr)
        set_nombre(orig.nombre);
    if (orig.colegiatura!=nullptr)
        set_colegiatura(orig.colegiatura);
    fecha=orig.fecha;
    dosis=orig.dosis;
}

void operator>>(ifstream &arch,VacunaAplicada &vacuna) {
    //Rabia,20250208,1.5,CMVP-5003
    char nomVac[100],colegiatura[100],c;
    int fecha;
    double dosis;
    arch.getline(nomVac,100,',');
    if (arch.eof()) return;
    vacuna.set_nombre(nomVac);
    arch>>fecha>>c>>dosis>>c;
    arch.getline(colegiatura,100,'\n');
    vacuna.set_colegiatura(colegiatura);
    vacuna.set_fecha(fecha);
    vacuna.set_dosis(dosis);
}

bool VacunaAplicada::operator==(const VacunaAplicada &registro) {
    return (strcmp(nombre,registro.nombre)==0 and
            strcmp(colegiatura,registro.colegiatura)==0 and
            fecha==registro.fecha and
            dosis==registro.dosis);
}

void operator<<(ofstream &arch,VacunaAplicada &vacuna) {
    char nom[100],colegiatura[100];
    vacuna.get_nombre(nom);
    vacuna.get_colegiatura(colegiatura);
    arch<<" - "<<left<<nom<<" : "<<right<<vacuna.get_fecha()<<" ("
        <<vacuna.get_dosis()<<" ml, "<<left<<colegiatura<<")"<<right<<endl;
}

