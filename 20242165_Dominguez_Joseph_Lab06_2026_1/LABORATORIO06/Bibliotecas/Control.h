//
// Created by jdomi on 31/10/2026.
//

#ifndef LABORATORIO06_CONTROL_H
#define LABORATORIO06_CONTROL_H
#include "Cita.h"
#include <fstream>
using namespace std;

class Control:public Cita{
private:
    double costo;
    int codmed;
public:
    Control();

    double get_costo() const;
    void set_costo(double costo);
    int get_codmed() const;
    void set_codmed(int codmed);
    void leerControl(ifstream &);
    void operator=(Control &);
    void imprimeControl(ofstream &);
};


#endif //LABORATORIO06_CONTROL_H