//
// Created by jdomi on 29/10/2026.
//

#include "Infraccion.h"

#include <cstring>
#include <iomanip>

Infraccion::Infraccion() {
    descripcion=nullptr;
    gravedad=nullptr;
    codigo=0;
    multa=0;
}

Infraccion::~Infraccion() {
    if (descripcion!=nullptr) delete descripcion;
    if (gravedad!=nullptr) delete gravedad;
}

Infraccion::Infraccion(const Infraccion &orig) {
    descripcion=nullptr;
    gravedad=nullptr;
    *this=orig;
}


int Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(int codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

void Infraccion::set_descripcion(const char *descripcion) {
    if (this->descripcion!=nullptr) delete this->descripcion;
    this->descripcion=new char[strlen(descripcion)+1];
    strcpy(this->descripcion, descripcion);
}

void Infraccion::get_descripcion(char *descripcion) {
    if (this->descripcion!=nullptr)
        strcpy(descripcion,this->descripcion);
}

void Infraccion::set_gravedad(const char *gravedad) {
    if (this->gravedad!=nullptr) delete this->gravedad;
    this->gravedad=new char[strlen(gravedad)+1];
    strcpy(this->gravedad, gravedad);
}

void Infraccion::get_gravedad(char *gravedad) {
    if (this->gravedad!=nullptr)
        strcpy(gravedad,this->gravedad);
}

void Infraccion::operator=(const Infraccion &orig) {
    if (orig.descripcion!=nullptr)
        set_descripcion(orig.descripcion);
    if (orig.gravedad!=nullptr)
        set_gravedad(orig.gravedad);
    codigo=orig.codigo;
    multa=orig.multa;
}

void operator>>(ifstream &arch,Infraccion &inf) {
    //3001,214.55,Leve,Dejar mal estacionado el vehiculo en lugares permitidos.
    int infraccion;
    double multa;
    char gravedad[100],descripcion[300],c;
    arch >> infraccion;
    if (arch.eof()) return;
    arch>>c>>multa>>c;
    arch.getline(gravedad,100,',');
    arch.getline(descripcion,300,'\n');
    inf.set_codigo(infraccion);
    inf.set_gravedad(gravedad);
    inf.set_multa(multa);
    inf.set_descripcion(descripcion);
}

void operator<<(ofstream &arch,Infraccion &inf) {
    char descripcion[300],gravedad[100];
    inf.get_gravedad(gravedad);
    inf.get_descripcion(descripcion);
    arch<<inf.get_codigo()<<setw(15)<<inf.get_multa()<<"  "<<left
        <<setw(30)<<gravedad<<descripcion<<right<<endl;
}
