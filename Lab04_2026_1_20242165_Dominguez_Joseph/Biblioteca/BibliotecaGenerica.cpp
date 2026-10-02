//
// Created by jdomi on 1/10/2026.
//

#include <fstream>
#include <iostream>

using namespace std;

#include "BibliotecaGenerica.h"

void procesaArreglo(void **arreglo,void *(*leer)(ifstream &),
    const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se pudo abri el archivo "<<nom<<endl;
        exit(1);
    }
    int i = 0;
    while (true) {
        void *data = leer(arch);
        if (data == nullptr) break;
        arreglo[i] = data;
        i += 1;
    }
}

int contarElementos(void **arreglo) {
    int i=0;
    for (i; arreglo[i]!=nullptr; i++);
    return i;
}

void generarLista(void *&lista) {
    void **llista=new void*[2]{};
    int *tamaño=new int;
    llista[0]=nullptr;
    llista[1]=tamaño;
    lista=llista;
}

void insertarLista(void *&lista,void *dato) {
    void **nodo=new void*[2]{};
    nodo[0]=dato;
    nodo[1]=nullptr;
    void **llista=(void **)lista;
    if (llista[0]==nullptr) {
        llista[0]=nodo;
    } else {
        nodo[1]=llista[0];
        llista[0]=nodo;
    }
    int *longitud=(int *)llista[1];
    (*longitud)++;
}

void creaLista(void **arreglo,void *&lista,int (*cmp)(const void *a, const void *b)) {
    int n=contarElementos(arreglo);
    qsort(arreglo,n,sizeof(void *),cmp);
    generarLista(lista);
    for (int i=0;i<n;i++) {
    // for (int i=n-1;i>=0;i--) {
        insertarLista(lista,arreglo[i]);
    }
}

void fusionaListas(void *lista1,void *lista2,int (*verify)(const void *a,
    const void *b)) {
    void **llista1=(void **)lista1;
    void **llista2=(void **)lista2;
    void **nodo1=(void **)llista1[0];
    void **nodo2=(void **)llista2[0];
    void **ant1=nullptr;
    while (nodo1!=nullptr and nodo2!=nullptr) {
        if (verify(nodo1[0],nodo2[0])>0) {
            if (ant1==nullptr) {
                llista1[0]=nodo2;
            } else {
                ant1[1]=nodo2;
            }
            void **temp=(void **)nodo2[1];
            nodo2[1]=nodo1;
            ant1=nodo2;
            nodo2=temp;
        } else {
            ant1=nodo1;
            nodo1=(void **)nodo1[1];
        }
    }
    if (nodo2!=nullptr) {
        if (ant1==nullptr) {
            llista1[0]=nodo2;
        } else {
            ant1[1]=nodo2;
        }
    }
}

void imprimeLista(void *lista,void (*imprimir)(ofstream &, void *),const char *nom) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout << "No se pudo abri el archivo "<<nom<<endl;
        exit(1);
    }
    void **llista=(void **)lista;
    void **prec=(void **)llista[0];
    while (prec) {
        imprimir(arch,prec[0]);
        prec=(void **)prec[1];
    }
}