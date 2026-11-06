//
// Created by jdomi on 31/10/2026.
//

#ifndef LABORATORIO06_MASCOTA_H
#define LABORATORIO06_MASCOTA_H
#include <fstream>
using namespace std;

class Mascota {
private:
    int codigo;
    char *nombre;
    char tipo;
    char *raza;
public:
    Mascota();
    ~Mascota();

    int get_codigo() const;
    void set_codigo(int codigo);
    char get_tipo() const;
    void set_tipo(char tipo);
    void set_nombre(const char *nombre);
    void get_nombre(char *nombre);
    void set_raza(const char *raza);
    void get_raza(char *raza);
    void leerMascota(ifstream &);
    void operator=(Mascota &);
    void imprimirMascota(ofstream &);
};


#endif //LABORATORIO06_MASCOTA_H