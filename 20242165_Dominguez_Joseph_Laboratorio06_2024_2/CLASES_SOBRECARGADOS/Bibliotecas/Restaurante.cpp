//
// Created by jdomi on 28/10/2026.
//

#include "Restaurante.h"

#include <cstring>
#include <iomanip>
#include <iostream>
#define INC 5
#define NO_ENCONTRADO -1
#define LINEA 250


Restaurante::Restaurante() {
    cantidadDeClientes=0;
    cantidadDePlatos=0;
    capacidadDeClientes=0;
    capacidadDePlatos=0;
    clientes=nullptr;
    platos=nullptr;
}

Restaurante::~Restaurante() {
    if (clientes!=nullptr) delete [] clientes;
    if (platos!=nullptr) delete [] platos;
}

void Restaurante::operator<(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    Cliente buffer[200];
    while (true) {
        arch>>buffer[cantidadDeClientes];
        if (arch.eof()) break;
        cantidadDeClientes++;
    }
    clientes=new Cliente[cantidadDeClientes+1];
    for (int i=0;i<cantidadDeClientes;i++)
        clientes[i]=buffer[i];
}

void Restaurante::operator<=(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        Plato aux;
        arch>>aux;
        if (arch.eof()) break;
        if (cantidadDePlatos==capacidadDePlatos) {
            aumentarEspacio();
        }
        platos[cantidadDePlatos-1]=aux;
        cantidadDePlatos++;
    }
}

void Restaurante::aumentarEspacio() {
    Plato *auxPlato;
    capacidadDePlatos+=INC;
    if (cantidadDePlatos==0) {
        platos=new Plato[capacidadDePlatos];
        cantidadDePlatos++;
    } else {
        auxPlato=new Plato[capacidadDePlatos];
        for (int i=0;i<cantidadDePlatos;i++) {
            auxPlato[i]=platos[i];
        }
        delete [] platos;
        platos=auxPlato;
    }
}

void Restaurante::operator<<=(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    int pedido,dni;
    while (true) {
        arch>>pedido;
        if (arch.eof()) break;
        arch.get();
        arch>>dni;
        arch.get();
        int posCli=buscaCliente(dni);
        if (posCli!=NO_ENCONTRADO) {
            procesarPlatos(posCli,arch);
        } else {
            while (arch.get()!='\n');
        }
    }
}

int Restaurante::buscaCliente(int dni) {
    for (int i=0;i<cantidadDeClientes;i++) {
        if (dni==clientes[i].get_dni()) return i;
    }
    return NO_ENCONTRADO;
}

void Restaurante::procesarPlatos(int pos, ifstream &arch) {
    char codPla[10];
    int cant;
    while (true) {
        arch.getline(codPla,10,',');
        arch>>cant;
        int posPla=buscaPlato(codPla);
        if (posPla!=NO_ENCONTRADO) {
            if (platos[posPla].get_preparados()>=platos[posPla].get_atendidos()+cant) {
                actualizaTodo(pos,posPla,cant);
            }
        }
        if (arch.get()=='\n') break;
    }
}

int Restaurante::buscaPlato(char *codPla) {
    char cad[10];
    for (int i=0;i<cantidadDePlatos;i++) {
        platos[i].get_codigo(cad);
        if (strcmp(codPla,cad)==0) return i;
    }
    return NO_ENCONTRADO;
}

void Restaurante::actualizaTodo(int pos,int posPla,int cant) {
    double precio=platos[posPla].get_precio();
    double descCli=clientes[pos].get_descuento();
    double total=precio*cant*(1-descCli/100);
    double totalBruto=cant*precio;
    int preparados=platos[posPla].get_preparados();
    double totalEsp=preparados*precio;
    double descPla=platos[posPla].get_descuento();
    double totalNeto=totalBruto*(1-descPla/100);
    clientes[pos].set_total_pagado(clientes[pos].get_total_pagado()+total);
    platos[posPla].set_total_esperado(totalEsp);
    platos[posPla].set_total_bruto(platos[posPla].get_total_bruto()+totalBruto);
    platos[posPla].set_total_neto(platos[posPla].get_total_neto()+totalNeto);
    platos[posPla].set_atendidos(platos[posPla].get_atendidos()+cant);
    int atendidos=platos[posPla].get_atendidos();
    platos[posPla].set_no_atendidos(preparados-atendidos);
}

void Restaurante::operator>>(const char *nom) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    arch<<setprecision(2)<<fixed;
    arch<<setw(109)<<"RESTAURANTE 1INF25"<<endl;
    arch<<setw(107)<<"VENTAS DEL DIA"<<endl;
    imprimirLinea(LINEA,'=',arch);
    arch<<setw(110)<<"RELACION DE PLATOS VENDIDOS"<<endl;
    imprimirLinea(LINEA,'-',arch);
    for (int i=0;i<cantidadDePlatos;i++) {
        arch<<platos[i];
    }
    imprimirLinea(LINEA,'=',arch);
    arch<<setw(89)<<"RELACION DE CLIENTES VENDIDOS"<<endl;
    imprimirLinea(LINEA,'-',arch);
    for (int i=0;i<cantidadDeClientes;i++) {
        arch<<clientes[i];
    }
    imprimirLinea(LINEA,'=',arch);

}

void Restaurante::imprimirLinea(int n, char car,ofstream &arch) {
    for (int i=0;i<n;i++) arch.put(car);
    arch<<endl;
}

