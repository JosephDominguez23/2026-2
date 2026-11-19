//
// Created by jdomi on 16/11/2026.
//

#ifndef POO_POLIMORFISMO_STANDARTPACKAGE_H
#define POO_POLIMORFISMO_STANDARTPACKAGE_H
#include "Package.h"
#include <fstream>
using namespace std;

class StandartPackage:public Package{
private:
    bool urgent;
public:
    StandartPackage();

    bool is_urgent() const;
    void set_urgent(bool urgent);

    double calculate_cost();
    bool can_dispatch();

    void read(ifstream &arch);
    void print_specific(ofstream &arch);
    string is_type(ofstream &arch);
};


#endif //POO_POLIMORFISMO_STANDARTPACKAGE_H