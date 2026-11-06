//
// Created by jdomi on 31/10/2026.
//

#ifndef LABORATORIO06_VETERINARIA_H
#define LABORATORIO06_VETERINARIA_H
#include "Control.h"
#include "Operacion.h"
#include "Vacuna.h"
#include <fstream>
using namespace std;

class Veterinaria {
private:
    Control *arrControl;
    Vacuna arrVacuna[30];
    Operacion arrOperacion[80];
    int numdatControl;
    int capaControl;
    int numdatVacuna;
    int numdatOperacion;
public:
    Veterinaria();
    ~Veterinaria();

    int get_numdat_control() const;
    void set_numdat_control(int numdat_control);
    int get_capa_control() const;
    void set_capa_control(int capa_control);
    void cargacitas();
    void llenarControl(ifstream &);
    void incrementarEspacio();
    void muestracitas();
    void elaborarLinea(ofstream &,int ,char);
    void imprimeOperacion(ofstream &,double &);
    void imprimeVacuna(ofstream &,int &);
    void imprimeControl(ofstream &,double &);
    int get_numdat_vacuna() const;
    void set_numdat_vacuna(int numdat_vacuna);
    int get_numdat_operacion() const;
    void set_numdat_operacion(int numdat_operacion);
};


#endif //LABORATORIO06_VETERINARIA_H