//
// Created by jdomi on 29/10/2026.
//

#ifndef CLASES_OBJETOS_EMPRESA_H
#define CLASES_OBJETOS_EMPRESA_H
#include "Multa.h"
#include <fstream>
using namespace std;


class Empresa {
private:
    int dni;
    char *nombre;
    char *placas[10];
    int numPlacas;
    Multa multas[100];
    int numMultas;
public:
    Empresa();
    ~Empresa();

    int get_dni() const;
    void set_dni(int dni);
    int get_num_placas() const;
    void set_num_placas(int num_placas);
    int get_num_multas() const;
    void set_num_multas(int num_multas);
    void set_nombre(const char *nombre);
    void get_nombre(char *nombre);
    void setPlacaI(const char *,int i);
    void getPlacaI(char *, int i);
    void leer(ifstream &);
    bool tieneLaPlaca(const char *pl);
    void operator+=(Multa &);
    void imprimePlacas(ofstream &arch);
    void imprimeMultas(ofstream &arch);
};

void operator>>(ifstream &,Empresa &);
void operator<<(ofstream &,Empresa &);


#endif //CLASES_OBJETOS_EMPRESA_H