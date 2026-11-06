//
// Created by jdomi on 5/11/2026.
//

#ifndef STREAMERSHERENCIA_METRICA_H
#define STREAMERSHERENCIA_METRICA_H
#include <iosfwd>
#include <fstream>
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
    ~Metrica();

    int get_id() const;
    void set_id(int id);
    int get_fecha_calculo() const;
    void set_fecha_calculo(int fecha_calculo);
    int get_fecha_expiracion() const;
    void set_fecha_expiracion(int fecha_expiracion);
    bool is_estado() const;
    void set_estado(bool estado);
    void set_descripcion(const char *descripcion);
    void get_descripcion(char *descripcion);

    void leerMetrica(ifstream &);
    void imprimirMetrica(ofstream &);
    void operator=(Metrica &);
};


#endif //STREAMERSHERENCIA_METRICA_H