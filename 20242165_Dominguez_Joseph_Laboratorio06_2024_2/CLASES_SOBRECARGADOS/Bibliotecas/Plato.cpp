//
// Created by jdomi on 28/10/2026.
//

#include "Plato.h"

#include <cstring>
#include <iomanip>


Plato::Plato() {
    codigo=nullptr;
    nombre=nullptr;
    precio=0;
    categoria=nullptr;
    preparados=0;
    descuento=0.0;
    atendidos=0;
    noAtendidos=0;
    totalNeto=0;
}

Plato::~Plato() {
    if (codigo!=nullptr) delete codigo;
    if (nombre!=nullptr) delete nombre;
    if (categoria!=nullptr) delete categoria;
}



double Plato::get_precio() const {
    return precio;
}

void Plato::set_precio(double precio) {
    this->precio = precio;
}

int Plato::get_preparados() const {
    return preparados;
}

void Plato::set_preparados(int preparados) {
    this->preparados = preparados;
}

double Plato::get_descuento() const {
    return descuento;
}

void Plato::set_descuento(double descuento) {
    this->descuento = descuento;
}

int Plato::get_atendidos() const {
    return atendidos;
}

void Plato::set_atendidos(int atendidos) {
    this->atendidos = atendidos;
}

int Plato::get_no_atendidos() const {
    return noAtendidos;
}

void Plato::set_no_atendidos(int no_atendidos) {
    noAtendidos = no_atendidos;
}

double Plato::get_total_neto() const {
    return totalNeto;
}

double Plato::get_total_bruto() const {
    return totalBruto;
}

void Plato::set_total_bruto(double total_bruto) {
    totalBruto = total_bruto;
}

double Plato::get_total_esperado() const {
    return totalEsperado;
}

void Plato::set_total_esperado(double total_esperado) {
    totalEsperado = total_esperado;
}

void Plato::set_total_neto(double total_neto) {
    totalNeto = total_neto;
}

void Plato::set_codigo(const char *codigo) {
    if (this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Plato::get_codigo(char *codigo) {
    if (this->codigo!=nullptr)
        strcpy(codigo,this->codigo);
}

void Plato::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr) delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Plato::get_nombre(char *nombre) {
    if (this->nombre!=nullptr)
        strcpy(nombre,this->nombre);
}

void Plato::set_categoria(const char *categoria) {
    if (this->categoria!=nullptr) delete this->categoria;
    this->categoria=new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}

void Plato::get_categoria(char *categoria) {
    if (this->categoria!=nullptr)
        strcpy(categoria,this->categoria);
}

void operator>>(ifstream& arch, Plato& pla) {
    char cod[100],nom[100],cat[100],c;
    double precio,descuento;
    int cant;
    arch.getline(cod,100,',');
    arch.getline(nom,100,',');
    arch>>precio>>c;
    arch.getline(cat,100,',');
    arch>>cant;
    if (arch.get()!='\n') {
        arch>>descuento>>c;
        arch.get();
    }
    pla.set_codigo(cod);
    pla.set_nombre(nom);
    pla.set_precio(precio);
    pla.set_categoria(cat);
    pla.set_preparados(cant);
    pla.set_descuento(descuento);
}

void Plato::operator=(Plato &orig) {
    if (orig.codigo!=nullptr)
        set_codigo(orig.codigo);
    if (orig.nombre!=nullptr)
        set_nombre(orig.nombre);
    precio=orig.precio;
    if (orig.categoria!=nullptr)
        set_categoria(orig.categoria);
    preparados=orig.preparados;
    descuento=orig.descuento;
    atendidos=orig.atendidos;
    noAtendidos=orig.noAtendidos;
    totalNeto=orig.totalNeto;
}

void operator<<(ofstream &arch,Plato &pla) {
    char codigo[100],nom[100],cat[100];
    pla.get_codigo(codigo);
    pla.get_nombre(nom);
    pla.get_categoria(cat);
    arch<<right<<setw(19)<<codigo<<"    "<<left<<setw(50)<<nom<<right<<setw(10)<<pla.get_precio()<<"   "
        <<left<<setw(10)<<cat<<right<<setw(20)<<pla.get_preparados()<<setw(20)
        <<pla.get_descuento()<<"%"<<setw(20)<<pla.get_atendidos()<<setw(20)
        <<pla.get_no_atendidos()<<setw(20)<<pla.get_total_esperado()<<setw(20)
        <<pla.get_total_bruto()<<setw(20)<<pla.get_total_neto()<<endl;
}


