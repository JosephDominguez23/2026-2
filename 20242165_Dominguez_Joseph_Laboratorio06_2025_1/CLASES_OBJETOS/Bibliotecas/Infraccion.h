//
// Created by jdomi on 29/10/2026.
//

#ifndef CLASES_OBJETOS_INFRACCION_H
#define CLASES_OBJETOS_INFRACCION_H
#include <iosfwd>
#include <fstream>
using namespace std;

class Infraccion {
private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
public:
    Infraccion();
    ~Infraccion();
    Infraccion(const Infraccion &);

    int get_codigo() const;
    void set_codigo(int codigo);
    double get_multa() const;
    void set_multa(double multa);
    void set_descripcion(const char *descripcion);
    void get_descripcion(char *descripcion);
    void set_gravedad(const char *gravedad);
    void get_gravedad(char *gravedad);
    void operator=(const Infraccion &);
};

void operator>>(ifstream &,Infraccion &);
void operator<<(ofstream &,Infraccion &);

#endif //CLASES_OBJETOS_INFRACCION_H