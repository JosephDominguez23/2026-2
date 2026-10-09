//
// Created by jdomi on 8/10/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_VACUNAAPLICADA_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_VACUNAAPLICADA_H

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

        int get_fecha() const;
        void set_fecha(int fecha);
        double get_dosis() const;
        void set_dosis(double dosis);
        void set_nombre(const char *nombre);
        void get_nombre(char *nombre);
        void set_colegiatura(const char *colegiatura);
        void get_colegiatura(char *colegiatura);
        void lee_vacuna(ifstream &);
        void asigna(VacunaAplicada &);
        bool esigual(VacunaAplicada &);
        void imprime_vacuna(ofstream &);
};


#endif //CLASES_OBJETOS_Y_SOBRECARGAS_VACUNAAPLICADA_H