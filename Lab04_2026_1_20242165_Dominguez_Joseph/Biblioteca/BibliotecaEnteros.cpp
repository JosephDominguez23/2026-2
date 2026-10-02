//
// Created by jdomi on 1/10/2026.
//
#include <fstream>
using namespace std;

#include "BibliotecaEnteros.h"


void *leenum(ifstream &arch) {
    int num;
    arch >> num;
    if (arch.eof()) return nullptr;
    int *pnum=new int;
    *pnum = num;
    return pnum;
}

int comparanum(const void *b, const void *a) {
    void **pa=(void **)a;
    void **pb=(void **)b;
    void *ai=*pa;
    void *bi=*pb;
    return verificanum(ai,bi);
}

int verificanum(const void *a, const void *b) {
    int num1=*(int *)a;
    int num2=*(int *)b;
    return num1-num2;
}

void imprimenum(ofstream &arch, void *dato) {
    int num=*(int *)dato;
    arch<<num<<endl;
}