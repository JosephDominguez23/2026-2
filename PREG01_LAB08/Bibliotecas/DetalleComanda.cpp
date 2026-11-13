//
// Created by jdomi on 12/11/2026.
//

#include "DetalleComanda.h"

#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"

DetalleComanda::DetalleComanda() {
    id=0;
    pedido=nullptr;
}

int DetalleComanda::get_id() const {
    return id;
}

void DetalleComanda::set_id(int id) {
    this->id = id;
}

void DetalleComanda::leerComanda(ifstream &arch,int nid) {
    char tipo;
    id=nid;
    arch >> tipo;
    arch.get();
    if (tipo=='E')
        pedido=new Entrada;
    if (tipo=='B')
        pedido=new Bebida;
    if (tipo=='P')
        pedido=new PlatoFondo;
    pedido->leer(arch);
}

void DetalleComanda::operator=(DetalleComanda &orig) {
    id=orig.id;
    pedido=orig.pedido;
}
