//
// Created by jdomi on 24/09/2026.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#define INC 5

#include "Funciones.h"

void cargaVentas(const char *nom,char ***&ventas) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    char **bufferVentas[200]{};
    int numData=0;
    while (true) {
        bufferVentas[numData]=leerVentas(arch);
        if (arch.eof()) break;
        numData++;
    }
    ventas=new char **[numData+1]{};
    for (int i = 0; i < numData; i++) {
        ventas[i] = bufferVentas[i];
    }
}

char **leerVentas(ifstream &arch) {
    char *codigo = leerCadena(arch,',');
    if (arch.eof()) return nullptr;
    char **cuarteto = new char *[4]{};
    cuarteto[0]=codigo;
    cuarteto[1]=leerCadena(arch,',');
    cuarteto[2]=leerCadena(arch,',');
    cuarteto[3]=leerCadena(arch,'\n');
    return cuarteto;
}

char *leerCadena(ifstream &arch,char carlim) {
    char cad[200],*ptr;
    arch.getline(cad,200,carlim);
    if (arch.eof()) return nullptr;
    ptr = new char[strlen(cad)+1];
    strcpy(ptr,cad);
    return ptr;
}

void imprimirReporte(const char *nom,char ***ventas,
        char ****detalleTexto,int ***detalleValor) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    arch<<setw(60)<<"PackMart S.A."<<endl;
    arch<<setw(60)<<"REGISTRO DE VENTAS"<<endl;
    const char *cabeza[4]={
        "CODIGO DE VENTAS","CODIGO DE CLIENTES","FECHA DE VENTA","CANAL DE VENTA"
    };
    imprimirLinea(arch,140,'=');
    arch<<left<<setw(3)<<"";
    for (int i = 0; ventas[i]; i++) {
        imprimirEncabezado(arch,cabeza);
        arch<<setw(2)<<i+1<<") "<<left;
        imprimirVenta(arch,ventas[i]);
        if (detalleTexto != nullptr && detalleTexto[i] != nullptr) {
            imprimirLinea(arch,140,'=');
            imprimirDetalles(arch,detalleTexto[i],detalleValor[i]);
            double costoTotal=0.0,totalPrecio=0.0,gananciaTotal=0.0;
            calcularTotales(costoTotal,totalPrecio,gananciaTotal,detalleValor[i]);
            imprimirTotales(arch,costoTotal,totalPrecio);
        }
    }
}

void calcularTotales(double &costoTotal,double &totalPrecio,double &gananciaTotal,
        int **detalleValor) {
    for (int i = 0; detalleValor[i]; i++) {
        int *costo=detalleValor[i];
        costoTotal+=costo[3];
        totalPrecio+=costo[4];
    }
}

void imprimirVenta(ofstream &arch,char **ventas) {
    arch<<left
        <<setw(35)<<ventas[0]
        <<setw(25)<<ventas[1]
        <<setw(35)<<ventas[2]
        <<setw(20)<<ventas[3]
        <<right<<endl;
}

void procesarDetalleDeVenta(ifstream &arch,int pos,char ****detalleTexto,int ***detalleValor,
                int *numData,int *capacidad) {
    if (numData[pos]==capacidad[pos]) {
        incrementarEspacio(detalleTexto[pos],detalleValor[pos],numData[pos],
            capacidad[pos]);
    }
    agregarDetalle(arch,detalleTexto[pos],detalleValor[pos],numData[pos]);
}

void incrementarEspacio(char ***&detalleTexto,int **&detalleValor,int &numData,
            int &capacidad) {
    char ***auxTexto;
    int **auxValor;
    capacidad+=INC;
    if (detalleTexto==nullptr) {
        detalleTexto=new char **[capacidad]{};
        detalleValor=new int *[capacidad]{};
        numData++;
    } else {
        auxTexto=new char **[capacidad]{};
        auxValor=new int *[capacidad]{};
        for (int i = 0; i < numData; i++) {
            auxTexto[i]=detalleTexto[i];
            auxValor[i]=detalleValor[i];
        }
        delete  detalleTexto;
        delete detalleValor;
        detalleTexto=auxTexto;
        detalleValor=auxValor;
    }
}

void  agregarDetalle(ifstream &arch,char ***detalleTexto,int **detalleValor,int &numData) {
    char **auxTexto=new char *[4]{};
    int *auxValor=new int[5]{};
    auxTexto[0]=leerCadena(arch,',');
    auxTexto[1]=leerCadena(arch,',');
    auxValor[0]=leerInt(arch,true);
    auxValor[1]=leerInt(arch,true);
    auxValor[2]=leerInt(arch,true);
    arch.get();
    arch.get();
    detalleTexto[numData-1]=auxTexto;
    detalleValor[numData-1]=auxValor;
    numData++;
}

void cargarDetallesDeVenta(const char *nom,char ***ventas,char ****&detalleTexto,
        int ***&detalleValor) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    int numVenta=0, numData[150]{}, capacidad[150]{};
    char codigoVenta[7];
    while (ventas[numVenta]) numVenta++;
    detalleTexto = new char ***[numVenta+1]{};
    detalleValor = new int **[numVenta+1]{};
    while (true) {
        arch.getline(codigoVenta,7,',');
        if (arch.eof()) break;
        int pos=buscarVenta(codigoVenta,ventas);
        if (pos!=-1) {
            procesarDetalleDeVenta(arch,pos,detalleTexto,detalleValor,
                numData,capacidad);
        } else {
            while (arch.get()!='\n');
        }
    }
}

int buscarVenta(char *codigoVenta,char ***ventas) {
    for (int i = 0; ventas[i]; i++) {
        char **codigo=ventas[i];
        if (strcmp(codigoVenta,codigo[0])==0) return i;
    }
    return -1;
}


int leerInt(ifstream &arch, bool leer) {
    int number;
    arch >> number;
    if (leer) arch.get();
    return number;
}

double leeDbl(ifstream &arch, bool leer) {
    double real;
    arch >> real;
    if (leer) arch.get();
    return real;
}

void imprimirDetalles(ofstream &arch,char ***detalleTexto,int **detalleValor) {
    arch<<"PRODUCTOS COMPRADOS: "<<endl;
    arch<<left<<setw(9)<<"CODIGO"
        <<setw(30)<<"DESCRIPCION"
        <<setw(14)<<"PRESENTACION"
        <<setw(11)<<"CATEGORIA"
        <<setw(13)<<"UNID X PRES"
        <<setw(10)<<"CANTIDAD"
        <<setw(13)<<"COSTO UNIT"
        <<setw(15)<<"PRECIO UNIT"
        <<setw(10)<<"DESCUENTO"<<endl;
    imprimirLinea(arch,140,'=');
    for (int i = 0; detalleTexto[i]; i++) {
        imprimirDetail(arch,detalleTexto[i],detalleValor[i]);
    }
}

void imprimirDetail(ofstream &arch,char **detalleTexto,const int *detalleValor) {
    arch<<left<<setw(9)<<detalleTexto[0];
    if (detalleTexto[2])
        arch<<setw(33)<<detalleTexto[2];
    else
        arch<<setw(33)<<' ';
    arch<<setw(14)<<detalleTexto[1];
    if (detalleTexto[3])
        arch<<setw(11)<<detalleTexto[3];
    else
        arch<<setw(11)<<' ';
    arch<<right<<setw(5)<<detalleValor[0]<<setw(10)<<detalleValor[1];
    if (detalleValor[3])
        arch<<setw(13)<<detalleValor[3]<<setw(13)<<detalleValor[4];
    else
        arch<<setw(13)<<' '<<setw(13)<<' ';
    arch<<setw(13)<<detalleValor[2]<<"%"<<endl;
}

void cargarDetalleProducto(const char *nom,char ***ventas,
        char ****detalleTexto,int ***detalleValor) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    while (true) {
        char *codProd = leerCadena(arch,',');
        if (arch.eof()) break;
        char *descripcion = leerCadena(arch,',');
        char *categoria = leerCadena(arch,',');
        int costUnit = leerInt(arch,true);
        int precUnit = leerInt(arch,false);
        arch.get();
        // arch.get();
        for (int i = 0; ventas[i]; i++) {
            completarVentas(detalleTexto[i],detalleValor[i],
                codProd,descripcion,categoria,costUnit,precUnit);
        }
    }
}

void completarVentas(char ***detalleTexto,int **detalleValor,
                const char *codProd,char *descripcion,char *categoria,int costUnit,int precUnit) {
    if (detalleTexto == nullptr || detalleValor == nullptr)
        return;
    for (int i = 0; detalleTexto[i]; i++) {
        verificarYAsignar(detalleTexto[i],detalleValor[i],codProd,descripcion,categoria,
            costUnit,precUnit);
    }
}

void verificarYAsignar(char **detalleTexto,int *detalleValor,
        const char *codProd,char *descripcion,char *categoria,int costUnit,int precUnit) {
    if (strcmp(codProd,detalleTexto[0])==0) {
        detalleTexto[2]=descripcion;
        detalleTexto[3]=categoria;
        detalleValor[3]=costUnit;
        detalleValor[4]=precUnit;
    }
}

void imprimirEncabezado(ofstream &arch, const char **cabeza) {
    for (int i = 0; i<4; i++) {
        arch<<setw(30)<<left<<cabeza[i];
    }
    arch<<endl;
}

void imprimirTotales(ofstream &arch, const double totalCosto, const double totalPrecio) {
    arch.precision(2);
    arch<<fixed;
    imprimirLinea(arch,140,'=');
    arch<<"COSTO TOTAL:       "<<setw(10)<<totalCosto<<endl;
    arch<<"PRECIO TOTAL:      "<<setw(10)<<totalPrecio<<endl;
    arch<<"GANANCIA TOTAL:    "<<setw(10)<<totalPrecio-totalCosto<<endl;
    imprimirLinea(arch,140,'=');
}

void imprimirLinea(ofstream &arch,int n,char car) {
    for (int i = 0; i<n; i++) arch.put(car);
    arch<<endl;
}