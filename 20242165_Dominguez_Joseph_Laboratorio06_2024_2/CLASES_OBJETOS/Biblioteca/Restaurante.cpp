//
// Created by jdomi on 8/10/2026.
//

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Restaurante.h"

Restaurante::Restaurante() {
    cantDeClientes=0;
    cantDePlatos=0;
}

void Restaurante::cargaclientes(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se pudo abrir el arhcivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        Cliente aux;
        aux.lee_cliente(arch);
        if (arch.eof()) break;
        clientes[cantDeClientes].asigna(aux);
        cantDeClientes++;
    }
}

void Restaurante::borracliente() {
    for (int i = 0; i < cantDeClientes; i++) {
        if (clientes[i].get_descuento()==0) {
            clientes[i].libera();
            for (int j=i; j<cantDeClientes-1; j++) {
                clientes[j].asigna(clientes[j+1]);
            }
            cantDeClientes--;
            i--;
        }
    }
    // clientes[cantDeClientes-1].libera();
    // cantDeClientes--;
}

void Restaurante::cargaplato(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se pudo abrir el arhcivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        plato[cantDePlatos].lee_plato(arch);
        if (arch.eof()) break;
        cantDePlatos++;
    }
}


void Restaurante::imprimeclientes(const char *nom) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout << "No se pudo abrir el arhcivo "<<nom<<endl;
        exit(1);
    }
    for (int i = 0; i < cantDeClientes; i++) {
        clientes[i].imprime_cliente(arch);
    }
}

void Restaurante::procesapedidos(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se pudo abrir el arhcivo "<<nom<<endl;
        exit(1);
    }
    int numped,dni;
    char c;
    while (true) {
        arch>>numped;
        if (arch.eof()) break;
        arch>>c>>dni>>c;
        int poscli=buscacliente(dni);
        if (poscli!=-1)
            procesaplatos(poscli,arch);
        else
            while (arch.get()!='\n');
    }
}

int Restaurante::buscacliente(int dni) {
    for (int i = 0; i < cantDeClientes; i++)
        if (clientes[i].get_dni()==dni) return i;
    return -1;
}

void Restaurante::procesaplatos(int pos, ifstream &arch) {
    char codpla[10];
    int cant;
    while (true) {
        arch.getline(codpla,10,',');
        arch>>cant;
        int pospla=buscaplato(codpla);
        if (pospla!=-1) {
            if (plato[pospla].get_preparados()>=plato[pospla].get_atendidos()+cant) {
                actualizatodo(pos,pospla,cant);
            }
        }
        if (arch.get()=='\n') break;
    }
}

int Restaurante::buscaplato(char *codigo) {
    for (int i = 0; i < cantDePlatos; i++) {
        char cad[10];
        plato[i].get_codigo(cad);
        if (strcmp(codigo,cad)==0) return i;
    }
    return -1;
}

void Restaurante::actualizatodo(int poscli, int pospla, int cant) {
    double precio=plato[pospla].get_precio();
    double descli=clientes[poscli].get_descuento();
    double total=precio*cant*(1-descli/100);
    clientes[poscli].set_totalpagado(clientes[poscli].get_totalpagado()+total);
    plato[poscli].set_atendidos(plato[poscli].get_atendidos()+cant);
}


