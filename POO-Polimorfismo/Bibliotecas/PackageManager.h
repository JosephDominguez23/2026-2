//
// Created by jdomi on 16/11/2026.
//

#ifndef POO_POLIMORFISMO_PACKAGEMANAGER_H
#define POO_POLIMORFISMO_PACKAGEMANAGER_H
#include "Queue.h"


class PackageManager {
private:
    Queue package_queue;
public:
    void load_packages();
    void process_packages();
    Package *asignarMemoria(char tipo);
    void load_products(ifstream &arch_prod,Package *package);
    Product *read_product(ifstream &arch);
};


#endif //POO_POLIMORFISMO_PACKAGEMANAGER_H