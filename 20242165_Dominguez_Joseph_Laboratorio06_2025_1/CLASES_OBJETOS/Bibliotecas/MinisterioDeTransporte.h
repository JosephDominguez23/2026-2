//
// Created by jdomi on 29/10/2026.
//

#ifndef CLASES_OBJETOS_MINISTERIODETRANSPORTE_H
#define CLASES_OBJETOS_MINISTERIODETRANSPORTE_H
#include "Empresa.h"
#include "Infraccion.h"


class MinisterioDeTransporte {
private:
    Infraccion *infracciones;
    int numInf;
    Empresa empresas[50];
    int numEmp;
public:
    MinisterioDeTransporte();
    ~MinisterioDeTransporte();

    int get_num_inf() const;
    void set_num_inf(int num_inf);
    int get_num_emp() const;
    void set_num_emp(int num_emp);
    void operator<(const char *);
    void operator<=(const char *);
    void operator<<=(const char *);
    int buscarMulta(int );
    int buscarEmpresa(char *);
    void operator>>(const char *);
};


#endif //CLASES_OBJETOS_MINISTERIODETRANSPORTE_H