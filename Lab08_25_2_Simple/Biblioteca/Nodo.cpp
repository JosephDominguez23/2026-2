//
// Created by Alan on 17/06/2026.
//

#include "Nodo.h"

#include "MetricaBasica.h"
#include "MetricaCalidad.h"
#include "MetricaEngagement.h"

Nodo::Nodo() {
    metrica=nullptr;
    siguiente=nullptr;
}

void Nodo::cargarNodo(ifstream &arch) {
    char cad[50]{};

    arch.getline(cad,50,',');
    if (arch.eof()) return;
    if (strcmp(cad,"ENGAGEMENT")==0) {
        metrica = new MetricaEngagement;
    }
    if (strcmp(cad,"BASIC")==0) {
        metrica = new MetricaBasica;
    }
    if (strcmp(cad,"QUALITY")==0) {
        metrica = new MetricaCalidad;
    }
    metrica->leer(arch);
    arch.get();
}

int Nodo::cmp(Nodo &nuevo) {
    if (metrica->get_id() > nuevo.metrica->get_id())
        return 1;
    return 0;
}

void Nodo::imprimirNodo(ofstream &arch) {
    metrica->imprimir(arch);
}

const char *Nodo::obtenerTipo() {
    return metrica->tipoMetrica();
}

bool Nodo::esActiva() {
    if (metrica->is_estado())
        return true;
    return false;
}

