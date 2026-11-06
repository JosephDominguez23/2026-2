//
// Created by jdomi on 31/10/2026.
//

#ifndef PREG01_LAB07_PRODUCTO_H
#define PREG01_LAB07_PRODUCTO_H
#include <fstream>
using namespace std;

class Producto {
private:
    char *nombre;
    double precio;
public:
    Producto();
    ~Producto();

    double get_precio() const;
    void set_precio(double precio);
    void get_nombre(char *nombre);
    void set_nombre(const char *nombre);
    void leeproducto(ifstream &);
    void imprimeproducto(ofstream &,double &);
};


#endif //PREG01_LAB07_PRODUCTO_H