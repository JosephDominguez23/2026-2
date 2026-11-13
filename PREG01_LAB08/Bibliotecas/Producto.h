//
// Created by jdomi on 12/11/2026.
//

#ifndef PREG01_LAB08_PRODUCTO_H
#define PREG01_LAB08_PRODUCTO_H
#include <string>
#include <fstream>
using namespace std;


class Producto {
private:
    string nombre;
    double precio;
public:
    Producto();

    string get_nombre() const;
    void set_nombre(const string &nombre);
    double get_precio() const;
    void set_precio(double precio);
    virtual void leer(ifstream &);
};


#endif //PREG01_LAB08_PRODUCTO_H