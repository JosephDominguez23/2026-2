//
// Created by jdomi on 31/10/2026.
//

#ifndef LABORATORIO06_OPERACION_H
#define LABORATORIO06_OPERACION_H
#include "Cita.h"
#include <fstream>
using namespace std;

class Operacion:public Cita{
private:
    bool anesteciageneral;
    int nummedicos;
    double total;
public:
    Operacion();

    bool is_anesteciageneral() const;
    void set_anesteciageneral(bool anesteciageneral);
    int get_nummedicos() const;
    void set_nummedicos(int nummedicos);
    double get_total() const;
    void set_total(double total);
    void leerOperacion(ifstream &);
    void imprimeOperacion(ofstream &);
};


#endif //LABORATORIO06_OPERACION_H