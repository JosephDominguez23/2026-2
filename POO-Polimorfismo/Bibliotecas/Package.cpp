//
// Created by jdomi on 16/11/2026.
//

#include "Package.h"
#define LINE 42
#include <iomanip>

Package::Package() {
    distance=0;
    n_products=0;
    total_weight=0;
    total_value=0;
}

string Package::get_code() const {
    return code;
}

void Package::set_code(const string &code) {
    this->code = code;
}

double Package::get_distance() const {
    return distance;
}

void Package::set_distance(double distance) {
    this->distance = distance;
}

Stack Package::get_products() const {
    return products;
}

void Package::set_products(const Stack &products) {
    this->products = products;
}

int Package::get_n_products() const {
    return n_products;
}

void Package::set_n_products(int n_products) {
    this->n_products = n_products;
}

double Package::get_total_weight() const {
    return total_weight;
}

void Package::set_total_weight(double total_weight) {
    this->total_weight = total_weight;
}

double Package::get_total_value() const {
    return total_value;
}

void Package::set_total_value(double total_value) {
    this->total_value = total_value;
}

void Package::read(ifstream &arch) {
    //P001,90,2,
    getline(arch,code,',');
    if (arch.eof()) return;
    arch>>distance;
    arch.get();
    arch>>n_products;
    arch.get();
}

void Package::add_product(Product *prod) {
    products.push(prod);
    total_weight+=prod->get_weight();
    total_value+=prod->get_value();
}

void Package::print(ofstream &arch) {
    arch<<setprecision(2)<<fixed;
    arch<<"PACKAGE TYPE: "<<is_type(arch)<<endl;
    arch<<"Package: "<<code<<endl;
    arch<<"Distance: "<<distance<<endl;
    print_specific(arch);
    arch<<"Total weight: "<<get_total_weight()<<" kg"<<endl;
    arch<<"Total value: S/ "<<get_total_value()<<endl;
    arch<<"Shipping cost: S/ "<<calculate_cost()<<endl;
    arch<<"Status: ";
    if (can_dispatch()) {
        arch<<"DISPATCHED"<<endl;
    } else {
        arch<<"PENDING"<<endl;
    }
    print_products(arch);
    arch<<endl;
    print_line(arch,LINE,'-');
    arch<<endl;
}

void Package::print_products(ofstream &arch) {
    Product *product;
    arch<<endl;
    arch<<"Products:"<<endl;
    arch<<left<<setw(8)<<"Code"<<setw(14)<<"Name"<<right
        <<setw(8)<<"Weight"<<setw(12)<<"Value"<<endl;
    while ((product=products.pop())!=nullptr) {
        product->printProduct(arch);
        delete product;
    }
}

void Package::print_line(ofstream &arch, int n, char car) {
    for (int i=0;i<n;i++) arch.put(car);
    arch<<endl;
}

