//
// Created by jdomi on 1/10/2026.
//

#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#include "BibliotecaRegistros.h"

int leerfecha(ifstream &arch) {
    char c;
    int year, month, day;
    arch >> day >> c >> month >> c >> year >> c;
    return 10000 * year + 100 * month + day;
}

int leerhora(ifstream &arch) {
    char c;
    int hour, min;
    arch >> hour >> c >> min >> c;
    return 60 * hour + min;
}

char *leerstr(ifstream &arch,char carlim) {
    constexpr int MAX_BUFFER = 64;
    char buffer[MAX_BUFFER]{};
    arch.getline(buffer, MAX_BUFFER, carlim);
    char *str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void *leeregistro(ifstream &arch) {
    char c;
    int cod;
    arch>>cod;
    if (arch.eof()) return nullptr;
    arch>>c;
    int fecha=leerfecha(arch);
    char *motivo=leerstr(arch,',');
    int hora=leerhora(arch);
    char *estado=leerstr(arch,',');
    char *nombre=leerstr(arch,',');
    char *raza=leerstr(arch,',');
    char *color=leerstr(arch,',');
    char *especie=leerstr(arch,'\n');
    int *auxCod=new int,*auxFecha=new int,*auxHora=new int;
    *auxCod=cod;
    *auxFecha=fecha;
    *auxHora=hora;
    void **reg=new void*[9]{};
    reg[0]=auxCod;
    reg[1]=auxFecha;
    reg[2]=motivo;
    reg[3]=auxHora;
    reg[4]=estado;
    reg[5]=nombre;
    reg[6]=raza;
    reg[7]=color;
    reg[8]=especie;
    return reg;
}

int fecha_hora(int fecha,int hora) {
    return fecha*10000 + hora;
}

int comparareg(const void *a, const void *b) {
    void **pa = (void **)a;
    void **pb = (void **)b;
    return verificareg(*pa,*pb);
}

int verificareg(const void *a, const void *b) {
    void **areg=(void **)a;
    void **breg=(void **)b;
    int fecha_a=fecha_hora(*(int *)areg[1],*(int *)areg[3]);
    int fecha_b=fecha_hora(*(int *)breg[1],*(int *)breg[3]);
    return fecha_a-fecha_b;
}

void imprimirfecha(ofstream &arch,int fecha) {
    int year = fecha / 10000;
    int month = (fecha % 10000) / 100;
    int day = fecha % 100;
    arch << right << setfill('0') << year << "/";
    arch << setw(2) << month << "/";
    arch << setw(2) << day << setfill(' ');
    arch << "  ";
}

void imprimirhora(ofstream &arch,int hora) {
    int hour = hora / 60;
    int minute = hora % 60;
    arch << right << setfill('0') << setw(2) << hour << ":";
    arch << setw(2) << minute << setfill(' ');
    arch << "   ";
}

void imprimeregistro(ofstream &arch, void *dato) {
    void **reg=(void **)dato;
    imprimirfecha(arch, *(int *)reg[1]);
    imprimirhora(arch, *(int *)reg[3]);
    arch<<left<<setw(6)<<*(int *)reg[0];
    arch<<left<<setw(16)<<(char *)reg[5];
    arch<<left<<setw(24)<<(char *)reg[6];
    arch<<left<<setw(16)<<(char *)reg[7];
    arch<<endl;
}