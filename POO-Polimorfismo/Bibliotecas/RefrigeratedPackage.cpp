//
// Created by jdomi on 16/11/2026.
//

#include "RefrigeratedPackage.h"

RefrigeratedPackage::RefrigeratedPackage() {
    temperature = 0;
}

double RefrigeratedPackage::get_temperature() const {
    return temperature;
}

void RefrigeratedPackage::set_temperature(double temperature) {
    this->temperature = temperature;
}

double RefrigeratedPackage::calculate_cost() {
    return 20 + 3*get_total_weight() + 0.08*get_distance() + 1.5*(8-temperature);
}

bool RefrigeratedPackage::can_dispatch() {
    return get_total_weight()<=10 and get_distance()<=300 and temperature>=-10 and
        temperature<=8;
}

void RefrigeratedPackage::read(ifstream &arch) {
    Package::read(arch);
    arch>>temperature;
    arch.get();
}

void RefrigeratedPackage::print_specific(ofstream &arch) {
    arch<<"Required temperature: "<<temperature<<" C"<<endl;
}

string RefrigeratedPackage::is_type(ofstream &arch) {
    return "REFRIGERATED";
}

