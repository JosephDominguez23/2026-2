//
// Created by jdomi on 16/11/2026.
//

#include "StandartPackage.h"

StandartPackage::StandartPackage() {
    urgent = false;
}

bool StandartPackage::is_urgent() const {
    return urgent;
}

void StandartPackage::set_urgent(bool urgent) {
    this->urgent = urgent;
}

double StandartPackage::calculate_cost() {
    double cost=10 + 2*get_total_weight() + 0.05*get_distance();
    if (urgent) cost+=8;
    return cost;
}

bool StandartPackage::can_dispatch() {
    return get_total_weight()<=20 and get_distance()<=500;
}

void StandartPackage::read(ifstream &arch) {
    Package::read(arch);
    int esUrg;
    arch>>esUrg;
    arch.get();
    if (esUrg==1) {
        urgent=true;
    }
}

void StandartPackage::print_specific(ofstream &arch) {
    arch<<"Urgent: ";
    if (urgent) {
        arch<<"Yes"<<endl;
    } else {
        arch<<"No"<<endl;
    }
}

string StandartPackage::is_type(ofstream &arch) {
    return "STANDARD";
}







