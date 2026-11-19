//
// Created by jdomi on 16/11/2026.
//

#ifndef POO_POLIMORFISMO_REFRIGERATEDPACKAGE_H
#define POO_POLIMORFISMO_REFRIGERATEDPACKAGE_H
#include "Package.h"
#include <fstream>
using namespace std;

class RefrigeratedPackage:public Package{
private:
    double temperature;
public:
    RefrigeratedPackage();

    double get_temperature() const;
    void set_temperature(double temperature);

    double calculate_cost();
    bool can_dispatch();

    void read(ifstream &arch);
    void print_specific(ofstream &arch);
    string is_type(ofstream &arch);
};


#endif //POO_POLIMORFISMO_REFRIGERATEDPACKAGE_H