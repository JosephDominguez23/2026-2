//
// Created by jdomi on 8/10/2026.
//

#ifndef CLASES_OBJETOS_RESTAURANTE_H
#define CLASES_OBJETOS_RESTAURANTE_H

#include "Cliente.h"
#include "Plato.h"

#include <fstream>
using namespace std;

class Restaurante {
    private:
        Cliente clientes[200];
        int cantDeClientes;
        Plato plato[200];
        int cantDePlatos;
        int buscacliente(int);
        void procesaplatos(int,ifstream &);
        int buscaplato(char *);
        void actualizatodo(int ,int ,int );
    public:
        Restaurante();
        void cargaclientes(const char *);
        void borracliente();
        void cargaplato(const char *);
        void imprimeclientes(const char *);
        void procesapedidos(const char *);
};


#endif //CLASES_OBJETOS_RESTAURANTE_H