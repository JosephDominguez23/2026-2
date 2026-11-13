//
// Created by Alan on 17/06/2026.
//

#include "Lista.h"


Lista::Lista() {
    ini=nullptr;
    longitud=0;
}

int Lista::get_longitud() const {
    return longitud;
}

void Lista::set_longitud(int longitud) {
    this->longitud = longitud;
}

void Lista::crearLista(ifstream &arch) {
    while (true) {
        Nodo *nuevo = new Nodo();
        nuevo->cargarNodo(arch);
        if (arch.eof()) break;
        insertarEnOrden(nuevo);
    }
}

void Lista::insertarEnOrden(Nodo *nuevo) {
    Nodo *rec = ini, *ant=nullptr;

    while (rec != nullptr) {
        if (rec->cmp(*nuevo))
            break;
        ant=rec;
        rec = rec->siguiente;
    }
    nuevo->siguiente = rec;
    if (ant == nullptr) {
        ini = nuevo;
    }
    else {
        ant->siguiente = nuevo;
    }
    longitud++;
}

void Lista::imprimirLista(ofstream &arch) {
    //para imprimir todo
    // Nodo *rec = ini;
    // while (rec != nullptr) {
    //     rec->imprimirNodo(arch);
    //     rec = rec->siguiente;
    // }
    //por partes
    int totalActivas = 0, totalExpiradas = 0;
    arch << "==========================================================================" << endl;
    arch << "                           REPORTE DE METRICAS                            " << endl;
    arch << "==========================================================================" << endl;
    imprimirBloque(arch, "BASIC", totalActivas, totalExpiradas);
    imprimirBloque(arch, "ENGAGEMENT", totalActivas, totalExpiradas);
    imprimirBloque(arch, "QUALITY", totalActivas, totalExpiradas);
    arch << "--------------------------------------------------------------------------" << endl;
    arch << "[TOTAL] METRICAS ACTIVAS: " << totalActivas
         << " | METRICAS EXPIRADAS: " << totalExpiradas
         << " | FECHA DE REPORTE: 2025-11-14" << endl;
    arch << "==========================================================================" << endl;
}
void Lista::imprimirBloque(ofstream &arch, const char* tipo, int &activas, int &expiradas) {
    arch << "[METRICAS " << tipo << "]" << endl;

    Nodo *rec = ini;
    while (rec != nullptr) {
        // Por ejemplo, que rec->obtenerTipo() devuelva "BASIC", "ENGAGEMENT" o "QUALITY"
        if (strcmp(rec->obtenerTipo(), tipo) == 0) {
            rec->imprimirNodo(arch);

            if (rec->esActiva())
                activas++;
            else
                expiradas++;
        }
        rec = rec->siguiente;
    }
    arch << endl;
}

void Lista::eliminar() {
    Nodo *sale;
    while (ini != nullptr) {
        sale = ini;
        ini = ini->siguiente;
        delete sale;
        longitud--;
    }
    ini = nullptr;
}

void Lista::eliminarNodosLista() {
    Nodo *rec = ini; // Cambiar 'ini' por el nombre de tu puntero al primer nodo
    Nodo *ant = nullptr;

    while (rec != nullptr) {
        // Evaluamos si la métrica está expirada (estado == false)
        if (not rec->esActiva()) {
            Nodo *eliminar = rec;
            rec = rec->siguiente; // Avanzamos antes de destruir el nodo
            eliminar->siguiente = nullptr;

            if (ant == nullptr) {
                ini = rec; // Si era el primer nodo, reubicamos el inicio
            } else {
                ant->siguiente = rec; // Si estaba al medio/final, puenteamos
            }
            delete eliminar;
        } else {
            ant = rec;       // Si no se elimina, el actual pasa a ser el anterior
            rec = rec->siguiente; // Avanzamos normalmente
        }
    }
}
