//
// Created by jdomi on 5/11/2026.
//

#include "Streamers.h"

#include <cstring>

Streamers::Streamers() {
    cuenta=nullptr;
    categoria=nullptr;
    id=0;
    n_seguidores=0;
}

Streamers::~Streamers() {
    if (cuenta != nullptr)   delete cuenta;
    if (categoria != nullptr) delete categoria;
}


int Streamers::get_id() const {
    return id;
}

void Streamers::set_id(int id) {
    this->id = id;
}

int Streamers::get_n_seguidores() const {
    return n_seguidores;
}

void Streamers::set_n_seguidores(int n_seguidores) {
    this->n_seguidores = n_seguidores;
}

void Streamers::set_categoria(const char *categoria) {
    if (this->categoria != nullptr) delete this->categoria;
    this->categoria=new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}

void Streamers::get_categoria(char *categoria) {
    if (this->categoria != nullptr)
        strcpy(categoria,this->categoria);
}

void Streamers::set_cuenta(const char *cuenta) {
    if (this->cuenta != nullptr) delete this->cuenta;
    this->cuenta=new char[strlen(cuenta)+1];
    strcpy(this->cuenta,cuenta);
}

void Streamers::get_cuenta(char *cuenta) {
    if (this->cuenta != nullptr)
        strcpy(cuenta,this->cuenta);
}

void Streamers::leerStreamer(ifstream &arch) {
    //174920,xQcOW,PUBG,3246298,2025-10-17
    char cad[100];
    arch>>id;
    arch.get();
    arch.getline(cad,100,',');
    set_cuenta(cad);
    arch.getline(cad,100,',');
    set_categoria(cad);
    arch>>n_seguidores;
    arch.get();
}

void Streamers::imprimirStreamer(ofstream &arch) {

}


void Streamers::operator=(Streamers &orig) {
    if (orig.cuenta!=nullptr)
        set_cuenta(orig.cuenta);
    if (orig.categoria!=nullptr)
        set_categoria(orig.categoria);
    id=orig.id;
    n_seguidores=orig.n_seguidores;
}
