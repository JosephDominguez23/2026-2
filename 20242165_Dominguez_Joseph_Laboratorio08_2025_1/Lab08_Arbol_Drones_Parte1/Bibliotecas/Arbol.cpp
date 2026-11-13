//
// Created by jdomi on 12/11/2026.
//

#include "Arbol.h"

Arbol::Arbol() {
    raiz=nullptr;
}

void Arbol::inserta(ifstream &arch) {
    char tipo[50];
    Nodo *nuevo,*rec;
    arch.getline(tipo,50,',');
    if (arch.eof()) return;
    nuevo=new Nodo;
    nuevo->asignaMemoria(tipo);
    nuevo->leeDron(arch);
    rec=raiz;
    while (rec) {
        if (rec->cmp(*nuevo)) {
            if (rec->izq==nullptr) {
                rec->izq=nuevo;
                break;
            } else {
                rec=rec->izq;
            }
        } else {
            if (rec->der==nullptr) {
                rec->der=nuevo;
                break;
            } else {
                rec=rec->der;
            }
        }
    }
    if (rec==nullptr) raiz=nuevo;
}

void Arbol::imprimerep(ofstream &arch) {
    enorden(arch,raiz);
}

void Arbol::enorden(ofstream &arch, Nodo *nodo) {
    if(nodo==nullptr) return;
    enorden(arch,nodo->izq);
    nodo->dron->imprimir(arch);
    enorden(arch,nodo->der);
}
