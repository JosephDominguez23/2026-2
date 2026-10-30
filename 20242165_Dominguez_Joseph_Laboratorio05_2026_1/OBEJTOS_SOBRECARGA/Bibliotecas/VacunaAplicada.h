//
// Created by jdomi on 29/10/2026.
//

#ifndef OBEJTOS_SOBRECARGA_VACUNAAPLICADA_H
#define OBEJTOS_SOBRECARGA_VACUNAAPLICADA_H

#include <fstream>
using namespace std;

class VacunaAplicada {
private:
    char *nombre;
    int fecha;
    double dosis;
    char *colegiatura;
public:
    VacunaAplicada();
    ~VacunaAplicada();
    VacunaAplicada(const VacunaAplicada &);

    int get_fecha() const;
    void set_fecha(int fecha);
    double get_dosis() const;
    void set_dosis(double dosis);
    void set_nombre(const char *nombre);
    void get_nombre(char *nombre);
    void set_colegiatura(const char *colegiatura);
    void get_colegiatura(char *colegiatura);
    void operator=(const VacunaAplicada &);
    bool operator==(const VacunaAplicada &);
};
void operator>>(ifstream &,VacunaAplicada &);
void operator<<(ofstream &,VacunaAplicada &);

#endif //OBEJTOS_SOBRECARGA_VACUNAAPLICADA_H