//
// Created by jdomi on 31/10/2026.
//

#include "Restaurante.h"

#include <iosfwd>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

Restaurante::Restaurante() {
    cantidad_comandas = 0;
}

int Restaurante::get_cantidad_comandas() const {
    return cantidad_comandas;
}

void Restaurante::set_cantidad_comandas(int cantidad_comandas) {
    this->cantidad_comandas = cantidad_comandas;
}

void Restaurante::cargar_comandas() {
    ifstream arch("ArchivosDeDatos/comandas.csv",ios::in);
    if (not arch) {
        cout << "No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    int id;
    while (true) {
        arch >> id;
        if (arch.eof()) break;
        arch.get();
        int pos=buscomandas(id);
        if (pos == -1) {
            comandas[cantidad_comandas].cargapedido(id,arch);
            cantidad_comandas++;
        } else {
            comandas[pos].cargapedido(id,arch);
        }
    }
}

int Restaurante::buscomandas(int id) {
    for (int i = 0; i < cantidad_comandas; i++) {
        if (id==comandas[i].get_id()) return i;
    }
    return -1;
}

void Restaurante::imprimir_comandas() {
    ofstream arch("ArchivosDeReporte/reporteComanda.txt",ios::out);
    if (not arch) {
        cout << "No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    arch<<setw(79)<<"LISTA DE COMANDAS"<<endl;
    arch<<setprecision(2)<<fixed;
    for (int i = 0; i < cantidad_comandas; i++) {
        comandas[i].imprimirPedido(arch);
    }
}

