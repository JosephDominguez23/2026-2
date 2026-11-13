//
// Created by Alan on 11/06/2026.
//

#ifndef LAB08_25_2_METRICA_H
#define LAB08_25_2_METRICA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Metrica {
private:
    int id;
    char *descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;

public:
    Metrica();
    virtual ~Metrica();
    Metrica(const Metrica &obj);
    int get_id() const;
    void set_id(int id);
    int get_fecha_calculo() const;
    void set_fecha_calculo(int fecha_calculo);
    void get_descripcion(char *cad) const;
    void set_descripcion(const char *cad);
    int get_fecha_expiracion() const;
    void set_fecha_expiracion(int fecha_expiracion);
    bool is_estado() const;
    void set_estado(bool estado);
    virtual void leer(ifstream &arch);
    virtual void imprimir(ofstream &arch);
    virtual const char* tipoMetrica() const = 0;
};


#endif //LAB08_25_2_METRICA_H
