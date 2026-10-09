//
// Created by jdomi on 8/10/2026.
//

#ifndef CLASES_OBJETOS_Y_SOBRECARGAS_VETERINARIA_H
#define CLASES_OBJETOS_Y_SOBRECARGAS_VETERINARIA_H
#include "Mascota.h"


class Veterinaria {
    private:
        Mascota listaDeMascotas[10];
        int numMascotas;
        int buscaMascota(int,char *);
        void asignavacuna(int,VacunaAplicada &);
        void imprimirLinea(ofstream &,char);
    public:
        Veterinaria();
        void cargarMascota(const char *);
        void cargaVacunas(const char *);
        void imprime_reporte(const char *);
};


#endif //CLASES_OBJETOS_Y_SOBRECARGAS_VETERINARIA_H