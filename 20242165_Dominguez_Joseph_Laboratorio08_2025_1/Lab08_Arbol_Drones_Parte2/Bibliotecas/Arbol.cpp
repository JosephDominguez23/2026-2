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

void Arbol::actualiza() {
    int ne,ns;
    ne=cuenta(raiz,'E')*0.5;
    recorre(raiz,ne,'E',1);
    ns=cuenta(raiz,'S')*0.5;
    recorre(raiz,ns,'S',0);
}

int Arbol::cuenta(Nodo *ptr, char car) {
    int cont=0;
    if (ptr->dron->gettipo()==car)
        cont++;
    if (ptr->izq!=nullptr)
        cont+=cuenta(ptr->izq,car);
    if (ptr->der!=nullptr)
        cont+=cuenta(ptr->der,car);
    return cont;
}

void Arbol::recorre(Nodo *&parbol, int &n, char tipo, int valor) {
    if (parbol==nullptr) return;
    if (parbol->dron->gettipo()==tipo and n>0) {
        parbol->dron->cambia(valor);
        n--;
    }
    recorre(parbol->izq,n,tipo,valor);
    recorre(parbol->der,n,tipo,valor);
}

