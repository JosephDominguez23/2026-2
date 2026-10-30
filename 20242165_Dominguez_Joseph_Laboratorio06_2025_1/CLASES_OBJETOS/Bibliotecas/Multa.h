//
// Created by jdomi on 29/10/2026.
//

#ifndef CLASES_OBJETOS_MULTA_H
#define CLASES_OBJETOS_MULTA_H
#include <fstream>
using namespace std;

class Multa {
private:
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;
public:
    Multa();
    ~Multa();
    Multa(const Multa &);

    void set_fecha_de_infraccion(int fecha_de_infraccion);
    void set_fecha_de_pago(int fecha_de_pago);
    void set_codigo_infraccion(int codigo_infraccion);
    void set_multa(double multa);
    int get_fecha_de_infraccion() const;
    int get_fecha_de_pago() const;
    int get_codigo_infraccion() const;
    double get_multa() const;
    void set_placa(const char *placa);
    void get_placa(char *placa);
    void operator=(const Multa &);
};

void operator>>(ifstream &,Multa &);
void operator<<(ofstream &,Multa &);


#endif //CLASES_OBJETOS_MULTA_H