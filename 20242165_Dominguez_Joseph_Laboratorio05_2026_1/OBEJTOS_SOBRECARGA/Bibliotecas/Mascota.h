//
// Created by jdomi on 29/10/2026.
//

#ifndef OBEJTOS_SOBRECARGA_MASCOTA_H
#define OBEJTOS_SOBRECARGA_MASCOTA_H
#include "VacunaAplicada.h"
#include <fstream>
using namespace std;

class Mascota {
private:
    int dni;
    char *nombre;
    char *especie;
    int edad;
    double peso;
    char *colegiatura;
    VacunaAplicada listaVacunas[20];
    int numVacunas;
public:
    Mascota();
    ~Mascota();
    Mascota(const Mascota &);

    int get_dni() const;
    void set_dni(int dni);
    int get_edad() const;
    void set_edad(int edad);
    double get_peso() const;
    void set_peso(double peso);
    int get_num_vacunas() const;
    void set_num_vacunas(int num_vacunas);
    void set_nombre(const char *nombre);
    void get_nombre(char *nombre);
    void set_especie(const char *especie);
    void get_especie(char *especie);
    void set_colegiatura(const char *colegiatura);
    void get_colegiatura(char *colegiatura);
    void operator=(const Mascota &);
    void operator+=(const VacunaAplicada &);
    bool operator~();
    void imprimirVacuna(ofstream &);
};

void operator>>(ifstream &, Mascota &);
void operator<<(ofstream &, Mascota &);


#endif //OBEJTOS_SOBRECARGA_MASCOTA_H