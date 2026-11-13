//
// Created by jdomi on 12/11/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_DRON_H
#define LAB08_ARBOL_DRONES_PARTE1_DRON_H
#include <fstream>
using namespace std;

class Dron {
private:
    char *id;
    char *ubicacion;
    int capacidad;
public:
    Dron();
    virtual ~Dron();

    int get_capacidad() const;
    void set_capacidad(int capacidad);
    void set_id(const char *id);
    void get_id(char *id);
    void set_ubicacion(const char *ubicacion);
    void get_ubicacion(char *ubicacion);
    virtual void leer(ifstream &arch);
    virtual void imprimir(ofstream &arch);
};


#endif //LAB08_ARBOL_DRONES_PARTE1_DRON_H