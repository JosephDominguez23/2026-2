//
// Created by jdomi on 29/10/2026.
//

#ifndef OBEJTOS_SOBRECARGA_VETERINARIA_H
#define OBEJTOS_SOBRECARGA_VETERINARIA_H
#include "Mascota.h"


class Veterinaria {
private:
    Mascota *listaDeMascotas;
    int numMascotas;
public:
    Veterinaria();
    ~Veterinaria();

    int get_num_mascotas() const;
    void set_num_mascotas(int num_mascotas);
    void operator<=(const char *);
    void operator<<=(const char *);
    int buscaMascota(int,char *);
    void operator<<(const char *);
    void imprimirLinea(ofstream &,char,int );
};


#endif //OBEJTOS_SOBRECARGA_VETERINARIA_H