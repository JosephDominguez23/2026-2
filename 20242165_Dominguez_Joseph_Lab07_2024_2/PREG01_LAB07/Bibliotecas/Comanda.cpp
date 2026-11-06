//
// Created by jdomi on 31/10/2026.
//

#include "Comanda.h"

#include <cstring>

Comanda::Comanda() {
    estado=nullptr;
    id=0;
    cantidad_bebidas=0;
    cantidad_entradas=0;
    cantidad_plato_fondo=0;
    hora_atencion=0;
    hora_servicio=0;
    tiempo_preparacion=0;
    total=0;
}

Comanda::~Comanda() {
    if (estado!=nullptr) delete estado;
}

int Comanda::get_id() const {
    return id;
}

void Comanda::set_id(int id) {
    this->id = id;
}

int Comanda::get_cantidad_bebidas() const {
    return cantidad_bebidas;
}

void Comanda::set_cantidad_bebidas(int cantidad_bebidas) {
    this->cantidad_bebidas = cantidad_bebidas;
}

int Comanda::get_cantidad_entradas() const {
    return cantidad_entradas;
}

void Comanda::set_cantidad_entradas(int cantidad_entradas) {
    this->cantidad_entradas = cantidad_entradas;
}

int Comanda::get_cantidad_plato_fondo() const {
    return cantidad_plato_fondo;
}

void Comanda::set_cantidad_plato_fondo(int cantidad_plato_fondo) {
    this->cantidad_plato_fondo = cantidad_plato_fondo;
}

int Comanda::get_hora_atencion() const {
    return hora_atencion;
}

void Comanda::set_hora_atencion(int hora_atencion) {
    this->hora_atencion = hora_atencion;
}

int Comanda::get_hora_servicio() const {
    return hora_servicio;
}

void Comanda::set_hora_servicio(int hora_servicio) {
    this->hora_servicio = hora_servicio;
}

int Comanda::get_tiempo_preparacion() const {
    return tiempo_preparacion;
}

void Comanda::set_tiempo_preparacion(int tiempo_preparacion) {
    this->tiempo_preparacion = tiempo_preparacion;
}

double Comanda::get_total() const {
    return total;
}

void Comanda::set_total(double total) {
    this->total = total;
}

void Comanda::set_estado(const char *estado) {
    if (this->estado!=nullptr) delete this->estado;
    this->estado = new char[strlen(estado) + 1];
    strcpy(this->estado, estado);
}

void Comanda::get_estado(char *estado) {
    if (this->estado!=nullptr)
        strcpy(estado, this->estado);
}

void Comanda::cargapedido(int nid, ifstream &arch) {
    //142,B,Cafe,2,grande
    char tipo;
    id=nid;
    arch >> tipo;
    arch.get();
    if (tipo=='B') {
        bebidas[cantidad_bebidas].leebebida(arch);
        cantidad_bebidas++;
    }
    if (tipo=='E') {
        entradas[cantidad_entradas].leeentrada(arch);
        cantidad_entradas++;
    }
    if (tipo=='P') {
        plato_fondo[cantidad_plato_fondo].leeplato(arch);
        cantidad_plato_fondo++;
    }
}

void Comanda::imprimirPedido(ofstream &arch) {
    imprimirLinea(arch,'=',140);
    arch<<"PEDIDOS SOLICITADOS"<<endl;
    imprimirLinea(arch,'-',140);
    arch<<"ENTRADAS"<<endl;
    if (cantidad_entradas==0)
        arch<<"No solicito entrada"<<endl;
    for (int i = 0; i < cantidad_entradas; i++) {
        entradas[i].imprimeentrada(arch);
    }
    imprimirLinea(arch,'-',140);
    arch<<"BEBIDAS"<<endl;
    if (cantidad_bebidas==0)
        arch<<"No solicito bebida"<<endl;
    for (int i = 0; i < cantidad_bebidas; i++) {
        bebidas[i].imprimirbebida(arch);
    }
    imprimirLinea(arch,'-',140);
    arch<<"PLATOS DE FONDO"<<endl;
    if (cantidad_plato_fondo==0)
        arch<<"No solicito plato de fondo"<<endl;
    for (int i = 0; i < cantidad_plato_fondo; i++) {
        plato_fondo[i].imprimeplato(arch);
    }

}

void Comanda::imprimirLinea(ofstream &arch, char car, int n) {
    for (int i = 0; i < n; i++) arch.put(car);
    arch<<endl;
}
