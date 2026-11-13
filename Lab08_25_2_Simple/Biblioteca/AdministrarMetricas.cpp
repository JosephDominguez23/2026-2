//
// Created by Alan on 17/06/2026.
//

#include "AdministrarMetricas.h"

void AdministrarMetricas::cargarArchivo(const char *nomb) {
    ifstream arch(nomb,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo metricas.csv"<<endl;
        exit(1);
    }
    listaDeMetricas.crearLista(arch);
}

void AdministrarMetricas::generarReporte(const char *nomb) {
    ofstream arch(nomb,ios::out);
    if (not arch) {
        cout<<"No se pudo abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    listaDeMetricas.imprimirLista(arch);
}

void AdministrarMetricas::eliminarLista() {
    listaDeMetricas.eliminar();
}

void AdministrarMetricas::eliminarNodos() {
    listaDeMetricas.eliminarNodosLista();
}
