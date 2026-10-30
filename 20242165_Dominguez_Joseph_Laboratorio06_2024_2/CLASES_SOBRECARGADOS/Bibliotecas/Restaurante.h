//
// Created by jdomi on 28/10/2026.
//

#ifndef CLASES_SOBRECARGADOS_RESTAURANTE_H
#define CLASES_SOBRECARGADOS_RESTAURANTE_H
#include "Cliente.h"
#include "Plato.h"


class Restaurante {
private:
    Cliente *clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    Plato *platos;
    int cantidadDePlatos;
    int capacidadDePlatos;
public:
    Restaurante();
    ~Restaurante();
    void operator<(const char *);
    void operator<=(const char *);
    void aumentarEspacio();
    void operator<<=(const char *);
    int buscaCliente(int );
    void procesarPlatos(int,ifstream &);
    int buscaPlato(char *codPla);
    void actualizaTodo(int,int,int);
    void operator>>(const char*);
    void imprimirLinea(int,char,ofstream &);
};


#endif //CLASES_SOBRECARGADOS_RESTAURANTE_H