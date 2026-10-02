//
// Created by jdomi on 1/10/2026.
//

#ifndef LAB04_2026_1_20242165_DOMINGUEZ_JOSEPH_BIBLIOTECAENTEROS_H
#define LAB04_2026_1_20242165_DOMINGUEZ_JOSEPH_BIBLIOTECAENTEROS_H

#include <fstream>

void *leenum(ifstream &arch);
int comparanum(const void *b, const void *a);
int verificanum(const void *a, const void *b);
void imprimenum(ofstream &arch, void *dato);


#endif //LAB04_2026_1_20242165_DOMINGUEZ_JOSEPH_BIBLIOTECAENTEROS_H