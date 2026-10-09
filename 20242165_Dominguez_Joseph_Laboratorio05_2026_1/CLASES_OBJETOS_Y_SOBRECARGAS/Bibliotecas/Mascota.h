//
// Created by jdomi on 8/10/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_MASCOTA_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_MASCOTA_H

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
        void imprime_mascota(ofstream &);
        bool tiene_duplicados();
    public:
        Mascota();
        ~Mascota();

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
        void lee_mascota(ifstream &);
        void asigna(Mascota &);
        void agrega_vacuna(VacunaAplicada &);
        void imprime_cartilla(ofstream &);
};


#endif //CLASES_OBJETOS_Y_SOBRECARGAS_MASCOTA_H