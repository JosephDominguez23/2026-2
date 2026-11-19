//
// Created by jdomi on 16/11/2026.
//

#include "Product.h"

#include <iomanip>

Product::Product() {
    weight=0;
    value=0;
}

string Product::get_code() const {
    return code;
}

void Product::set_code(const string &code) {
    this->code = code;
}

string Product::get_name() const {
    return name;
}

void Product::set_name(const string &name) {
    this->name = name;
}

double Product::get_weight() const {
    return weight;
}

void Product::set_weight(double weight) {
    this->weight = weight;
}

double Product::get_value() const {
    return value;
}

void Product::set_value(double value) {
    this->value = value;
}

void Product::readProduct(ifstream &arch) {
    //P001,PR001,Laptop,2.5,3500
    getline(arch,code,',');
    if (arch.eof()) return;
    getline(arch,name,',');
    arch>>weight;
    arch.get();
    arch>>value;
    arch.get();
}

void Product::printProduct(ofstream &arch) {
    arch<<left<<setw(8)<<code<<setw(14)<<name<<right<<setw(8)<<weight
        <<setw(12)<<value<<endl;
}
