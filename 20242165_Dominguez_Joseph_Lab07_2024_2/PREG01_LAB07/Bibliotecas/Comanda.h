//
// Created by jdomi on 31/10/2026.
//

#ifndef PREG01_LAB07_COMANDA_H
#define PREG01_LAB07_COMANDA_H
#include <iosfwd>

#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"
#include <fstream>
using namespace std;

class Comanda {
private:
    int id;
    Bebida bebidas[20];
    Entrada entradas[20];
    PlatoFondo plato_fondo[20];
    int cantidad_bebidas;
    int cantidad_entradas;
    int cantidad_plato_fondo;
    int hora_atencion;
    int hora_servicio;
    int tiempo_preparacion;
    double total;
    char *estado;
public:
    Comanda();
    ~Comanda();

    int get_id() const;
    void set_id(int id);
    int get_cantidad_bebidas() const;
    void set_cantidad_bebidas(int cantidad_bebidas);
    int get_cantidad_entradas() const;
    void set_cantidad_entradas(int cantidad_entradas);
    int get_cantidad_plato_fondo() const;
    void set_cantidad_plato_fondo(int cantidad_plato_fondo);
    int get_hora_atencion() const;
    void set_hora_atencion(int hora_atencion);
    int get_hora_servicio() const;
    void set_hora_servicio(int hora_servicio);
    int get_tiempo_preparacion() const;
    void set_tiempo_preparacion(int tiempo_preparacion);
    double get_total() const;
    void set_total(double total);
    void get_estado(char *estado);
    void set_estado(const char *estado);
    void cargapedido(int,ifstream &);
    void imprimirPedido(ofstream &);
    void imprimirLinea(ofstream &arch,char car,int n);
};


#endif //PREG01_LAB07_COMANDA_H