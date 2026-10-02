//
// Created by jdomi on 1/10/2026.
//

#ifndef LAB04_2026_1_20242165_DOMINGUEZ_JOSEPH_BIBLIOTECAGENERICA_H
#define LAB04_2026_1_20242165_DOMINGUEZ_JOSEPH_BIBLIOTECAGENERICA_H
#include <fstream>
using namespace std;

void procesaArreglo(void **arreglo,void *(*leer)(ifstream &),
    const char *nom);
void creaLista(void **arreglo,void *&lista,
    int (*cmp)(const void *a, const void *b));
void fusionaListas(void *lista1,void *lista2,
    int (*verify)(const void *a, const void *b));
void imprimeLista(void *lista,void (*imprimir)(ofstream &, void *),const char *nom);
int contarElementos(void **arreglo);
void generarLista(void *&lista);
void insertarLista(void *&lista,void *dato);

#endif //LAB04_2026_1_20242165_DOMINGUEZ_JOSEPH_BIBLIOTECAGENERICA_H