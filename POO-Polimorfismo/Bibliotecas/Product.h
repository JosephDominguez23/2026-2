//
// Created by jdomi on 16/11/2026.
//

#ifndef POO_POLIMORFISMO_PRODUCT_H
#define POO_POLIMORFISMO_PRODUCT_H
#include <string>
#include <fstream>
using namespace std;


class Product {
private:
    string code;
    string name;
    double weight;
    double value;
public:
    Product();

    string get_code() const;
    void set_code(const string &code);
    string get_name() const;
    void set_name(const string &name);
    double get_weight() const;
    void set_weight(double weight);
    double get_value() const;
    void set_value(double value);

    void readProduct(ifstream &arch);
    void printProduct(ofstream &arch);
};


#endif //POO_POLIMORFISMO_PRODUCT_H