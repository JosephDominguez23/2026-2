//
// Created by jdomi on 1/10/2026.
//

#ifndef LAB04_2026_1_20242165_DOMINGUEZ_JOSEPH_BIBLIOTECAREGISTROS_H
#define LAB04_2026_1_20242165_DOMINGUEZ_JOSEPH_BIBLIOTECAREGISTROS_H


void *leeregistro(ifstream &arch);
int leerfecha(ifstream &arch);
int leerhora(ifstream &arch);
char *leerstr(ifstream &arch,char carlim);
int comparareg(const void *a, const void *b);
int verificareg(const void *a, const void *b);
int fecha_hora(int fecha,int hora);
void imprimeregistro(ofstream &arch, void *dato);
void imprimirfecha(ofstream &arch,int fecha);
void imprimirhora(ofstream &arch,int hora);

#endif //LAB04_2026_1_20242165_DOMINGUEZ_JOSEPH_BIBLIOTECAREGISTROS_H