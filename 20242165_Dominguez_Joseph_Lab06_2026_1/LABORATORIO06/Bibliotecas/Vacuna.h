//
// Created by jdomi on 31/10/2026.
//

#ifndef LABORATORIO06_VACUNA_H
#define LABORATORIO06_VACUNA_H
#include "Cita.h"
#include <fstream>
using namespace std;

class Vacuna: public Cita{
private:
    int dosis;
    int meses;
public:
    Vacuna();

    int get_dosis() const;
    void set_dosis(int dosis);
    int get_meses() const;
    void set_meses(int meses);
    void leeVacuna(ifstream &);
    void imprimirVacuna(ofstream &);
};


#endif //LABORATORIO06_VACUNA_H