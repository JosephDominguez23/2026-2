//
// Created by jdomi on 28/10/2026.
//

#ifndef CLASES_SOBRECARGADOS_CLIENTE_H
#define CLASES_SOBRECARGADOS_CLIENTE_H
#include <iosfwd>
#include <fstream>
using namespace std;


class Cliente {
private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;
public:
    Cliente();
    ~Cliente();

    int get_dni() const;
    void set_dni(int dni);
    double get_descuento() const;
    void set_descuento(double descuento);
    double get_total_pagado() const;
    void set_total_pagado(double total_pagado);
    void set_nombre(const char *nombre);
    void get_nombre(char *nombre);
    void set_distrito(const char *distrito);
    void get_distrito(char *distrito);
    void operator=(Cliente &);
};

void operator>>(ifstream &,Cliente &);
void operator<<(ofstream &,Cliente &);


#endif //CLASES_SOBRECARGADOS_CLIENTE_H