//
// Created by Alan on 17/06/2026.
//

#ifndef LAB08_25_2_SIMPLE_ADMINISTRARMETRICAS_H
#define LAB08_25_2_SIMPLE_ADMINISTRARMETRICAS_H
#include "Lista.h"


class AdministrarMetricas {
private:
    Lista listaDeMetricas;
public:
    void cargarArchivo(const char *nomb);
    void generarReporte(const char *nomb);
    void eliminarLista();
    void eliminarNodos();
};


#endif //LAB08_25_2_SIMPLE_ADMINISTRARMETRICAS_H
