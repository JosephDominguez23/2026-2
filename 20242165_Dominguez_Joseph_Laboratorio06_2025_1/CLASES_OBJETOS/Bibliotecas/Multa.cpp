//
// Created by jdomi on 29/10/2026.
//

#include "Multa.h"

#include <cstring>
#include <iomanip>


Multa::Multa() {
    placa=nullptr;
    fechaDeInfraccion=0;
    fechaDePago=0;
    codigoInfraccion=0;
    multa=0;
}

Multa::~Multa() {
    if (placa!=nullptr) delete placa;
}

Multa::Multa(const Multa &orig) {
    placa=nullptr;
    *this=orig;
}

void Multa::set_fecha_de_infraccion(int fecha_de_infraccion) {
    fechaDeInfraccion = fecha_de_infraccion;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

void Multa::set_codigo_infraccion(int codigo_infraccion) {
    codigoInfraccion = codigo_infraccion;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}


int Multa::get_fecha_de_infraccion() const {
    return fechaDeInfraccion;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

int Multa::get_codigo_infraccion() const {
    return codigoInfraccion;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_placa(const char *placa) {
    if (this->placa!=nullptr) delete this->placa;
    this->placa=new char[strlen(placa)+1];
    strcpy(this->placa,placa);
}

void Multa::get_placa(char *placa) {
    if (this->placa!=nullptr)
        strcpy(placa,this->placa);
}

void Multa::operator=(const Multa &orig) {
    if (orig.placa!=nullptr)
        set_placa(orig.placa);
    fechaDeInfraccion=orig.fechaDeInfraccion;
    fechaDePago=orig.fechaDePago;
    codigoInfraccion=orig.codigoInfraccion;
    multa=orig.multa;
}

void operator>>(ifstream &arch,Multa &mul) {
    //23/7/2023,P474-593,2060,P,22/8/2023
    int dd,mm,aa,fecha,dP,mP,aP,fechaP,infraccion;
    char placa[20],pago,c;
    arch>>dd;
    if (arch.eof()) return;
    arch>>c>>mm>>c>>dd>>c;
    arch.getline(placa,20,',');
    arch>>infraccion;
    if (arch.get()!='\n') {
        arch>>pago>>c>>dP>>c>>mP>>c>>aP;
        fechaP=aP*10000+mP*100+dP;
        mul.set_fecha_de_pago(fechaP);
    }
    fecha=aa*10000+mm*100+dd;
    mul.set_placa(placa);
    mul.set_codigo_infraccion(infraccion);
    mul.set_fecha_de_infraccion(fecha);
}

void operator<<(ofstream &arch,Multa &mul) {
    int fecha;
    fecha=mul.get_fecha_de_pago();
    char placa[20];
    mul.get_placa(placa);
    arch<<left<<setw(15)<<placa<<right<<setw(15)<<mul.get_fecha_de_infraccion()
        <<setw(15)<<mul.get_codigo_infraccion()<<setw(15)<<mul.get_multa();
    if (fecha>0) {
        arch<<setw(25)<<fecha;
    }
    arch<<endl;
}
