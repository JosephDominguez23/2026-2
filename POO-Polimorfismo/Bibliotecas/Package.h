//
// Created by jdomi on 16/11/2026.
//

#ifndef POO_POLIMORFISMO_PACKAGE_H
#define POO_POLIMORFISMO_PACKAGE_H
#include <string>
#include <fstream>

#include "Stack.h"
using namespace std;


class Package {
private:
    string code;
    double distance;
    Stack products;
    int n_products;
    double total_weight;
    double total_value;
public:
    Package();

    string get_code() const;
    void set_code(const string &code);
    double get_distance() const;
    void set_distance(double distance);
    Stack get_products() const;
    void set_products(const Stack &products);
    int get_n_products() const;
    void set_n_products(int n_products);
    double get_total_weight() const;
    void set_total_weight(double total_weight);
    double get_total_value() const;
    void set_total_value(double total_value);

    virtual double calculate_cost()=0;
    virtual bool can_dispatch()=0;
    virtual string is_type(ofstream &arch)=0;
    virtual void print_specific(ofstream &arch)=0;

    virtual void read(ifstream &arch);
    void print(ofstream &arch);

    void add_product(Product *prod);
    void print_products(ofstream &arch);
    void print_line(ofstream &arch,int n,char car);
};


#endif //POO_POLIMORFISMO_PACKAGE_H