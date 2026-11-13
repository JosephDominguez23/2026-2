//
// Created by jdomi on 12/11/2026.
//

#include "Central.h"

#include <iosfwd>
#include <fstream>
#include <iostream>
using namespace std;


void Central::carga() {
    ifstream arch("ArchivosDeDatos/Drones.csv",ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo drones "<<endl;
        exit(1);
    }
    while (true) {
        ADrones.inserta(arch);
        if (arch.eof()) break;
    }
}

void Central::muestra() {
    ofstream arch("ArchivosDeReporte/Reporte.txt",ios::out);
    if(!arch){
        cout <<"No se puede abrir el archivo de reporte";
        exit(1);
    }
    ADrones.imprimerep(arch);
}

void Central::actualiza() {
    ADrones.actualiza();
}
