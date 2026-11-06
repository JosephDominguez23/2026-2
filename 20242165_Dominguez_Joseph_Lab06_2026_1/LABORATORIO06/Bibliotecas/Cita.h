//
// Created by jdomi on 31/10/2026.
//

#ifndef LABORATORIO06_CITA_H
#define LABORATORIO06_CITA_H
#include "Mascota.h"
#include <fstream>
using namespace std;

class Cita {
private:
    int fecha;
    int hora;
    Mascota Amascota;
public:
    Cita();

    int get_fecha() const;
    void set_fecha(int fecha);
    int get_hora() const;
    void set_hora(int hora);
    void leercita(ifstream &);
    void operator=(Cita &);
    void imprimirCita(ofstream &);
};


#endif //LABORATORIO06_CITA_H