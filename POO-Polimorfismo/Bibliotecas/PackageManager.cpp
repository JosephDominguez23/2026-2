//
// Created by jdomi on 16/11/2026.
//

#include "PackageManager.h"

#include <iostream>

#include "RefrigeratedPackage.h"
#include "StandartPackage.h"

void PackageManager::load_packages() {
    ifstream arch_pack("ArchivosDeDatos/packages.csv",ios::in);
    if (not arch_pack) {
        cout<<"No se pudo abrir el arhivo de paquetes "<<endl;
        exit(1);
    }
    ifstream arch_prod("ArchivosDeDatos/products.csv",ios::in);
    if (not arch_prod) {
        cout<<"No se pudo abrir el arhivo de productos "<<endl;
        exit(1);
    }
    char tipo;
    Package *package;
    while (true) {
        arch_pack>>tipo;
        if (arch_pack.eof()) break;
        arch_pack.get();
        package=asignarMemoria(tipo);
        package->read(arch_pack);
        load_products(arch_prod,package);
        package_queue.enqueue(package);
    }
}

Package *PackageManager::asignarMemoria(char tipo) {
    if (tipo=='S') return new StandartPackage;
    if (tipo=='R') return new RefrigeratedPackage;
    return nullptr;
}

void PackageManager::load_products(ifstream &arch_prod, Package *package) {
    for (int i=0; i<package->get_n_products();i++) {
        Product *prod=read_product(arch_prod);
        package->add_product(prod);
    }
}

Product *PackageManager::read_product(ifstream &arch) {
    string codigo;
    if (arch.eof()) return nullptr;
    getline(arch,codigo,',');
    Product *prod;
    prod=new Product;
    prod->readProduct(arch);
    return prod;
}

void PackageManager::process_packages() {
    ofstream dispatch("ArchivosDeReporte/dispatch.txt",ios::out);
    if (not dispatch) {
        cout<<"No se pudo abrir el arhivo de empaque "<<endl;
        exit(1);
    }
    ofstream pending("ArchivosDeReporte/pending.txt",ios::out);
    if (not pending) {
        cout<<"No se pudo abrir el arhivo de pendientes "<<endl;
        exit(1);
    }
    int cant_dispatched=0, cant_pending=0;
    dispatch<<"========== DISPATCHED PACKAGES ==========="<<endl<<endl;
    pending<<"============ PENDING PACKAGES ============"<<endl<<endl;
    while (not package_queue.is_empty()) {
        Package *pack=package_queue.dequeue();
        if (pack->can_dispatch()) {
            pack->print(dispatch);
            cant_dispatched++;
        } else {
            pack->print(pending);
            cant_pending++;
        }
        delete pack;
    }
    dispatch<<"TOTAL DISPATCHED PACKAGES: "<<cant_dispatched<<endl;
    pending<<"TOTAL PENDING PACKAGES: "<<cant_pending<<endl;
}
