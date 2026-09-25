//
// Created by jdomi on 24/09/2026.
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#define  INC 5

using namespace std;

#include "Funciones.h"

void cargaproductos(void *&productos) {
    void *buffer[200];
    void **lproductos;
    int i=0;
    ifstream arch("ArchivosDeDatos/Productos2.csv",ios::in);
    if (not arch) {
        cout << "No se pudo abrir el archivo productos" << endl;
        exit(1);
    }
    while (true) {
        buffer[i]=leerProductos(arch);
        if (arch.eof()) break;
        i++;
    }
    lproductos=new void*[i+1];
    for (int j=0;j<i;j++) {
        lproductos[j]=buffer[j];
    }
    productos=lproductos;
}

void *leerProductos(ifstream &arch) {
    char *codigo,*nombre,*tipo,c;
    double *precio;
    void **reg;
    codigo=leerCadena(arch,',');
    if (arch.eof()) return nullptr;
    nombre=leerCadena(arch,',');
    precio = new double;
    tipo = new char;
    arch>>*precio>>c>>*tipo;
    arch.get();
    reg=new void *[4];
    reg[0]=codigo;
    reg[1]=nombre;
    reg[2]=precio;
    reg[3]=tipo;
    return reg;
}

void cargaclientes(void *&clientes) {
    void *buffer[200],**lclientes;
    int i=0;
    ifstream arch("ArchivosDeDatos/Clientes2.csv",ios::in);
    if (not arch) {
        cout << "No se pudo abrir el archivo clientes" << endl;
        exit(1);
    }
    while (true) {
        buffer[i] = leerClientes(arch);
        if (buffer[i]==nullptr) break;
        i++;
    }
    lclientes= new void *[i+1];
    for (int j=0;j<i;j++) lclientes[j]=buffer[j];
    clientes=lclientes;
}

void *leerClientes(ifstream &arch) {
    int *dni,telefono,cod;
    char *nombre,c;
    double *linea;
    void **reg;
    arch>>cod;
    if (arch.eof()) return nullptr;
    dni = new int;
    *dni=cod;
    arch.get();
    nombre=leerCadena(arch,',');
    linea=new double;
    arch>>telefono>>c>>*linea;
    reg=new void *[4];
    reg[0]=dni;
    reg[1]=nombre;
    reg[2]=nullptr;
    reg[3]=linea;
    return reg;
}

char *leerCadena(ifstream &arch,char carlim) {
    char cad[100],*ptr;
    arch.getline(cad,100,carlim);
    if (arch.eof()) return nullptr;
    ptr = new char[strlen(cad)+1];
    strcpy(ptr,cad);
    return ptr;
}

void cargapedidos(void *productos, void *&clientes) {
    ifstream arch("ArchivosDeDatos/Pedidos2.csv",ios::in);
    if (not arch) {
        cout << "No se pudo abrir el archivo pedidos" << endl;
        exit(1);
    }
    void **auxClientes;
    int *nPedidos;
    nPedidos=asignarMemoriaTemporal(clientes);
    while (true) {
        leerPedidosCliente(arch,productos,clientes,nPedidos);
        if (arch.eof()) break;
    }
    asignarMemoriaExactaEnPedidos(clientes, nPedidos);
}

void asignarMemoriaExactaEnPedidos(void *& clientes, int* nPedidos){
    int nClientes = 0, i;
    void **auxPedidos, **auxCliente, **auxNuevo;
    void **auxClientes = (void **)clientes;
    for(nClientes; auxClientes[nClientes]; nClientes++){
        auxCliente = (void**) auxClientes[nClientes];
        if(nPedidos[nClientes] > 0){
            auxPedidos = (void**) auxCliente[2];
            auxNuevo = new void*[nPedidos[nClientes]+1];
            for(i=0; i<nPedidos[nClientes]; i++)
                auxNuevo[i] = auxPedidos[i];
            auxNuevo[i] = nullptr;
            auxPedidos = auxNuevo;
        } else {
            auxPedidos = nullptr;
        }
        auxCliente[2] = auxPedidos;
        auxClientes[nClientes] = auxCliente;
    }
    clientes = auxClientes;
}

int *asignarMemoriaTemporal(void *&clientes) {
    int nClientes=0,*nPedidosXCliente;
    void **auxClientes=(void **)clientes,**auxCliente;
    for (nClientes;auxClientes[nClientes];nClientes++) {
        auxCliente=(void **)auxClientes[nClientes];
        auxCliente[2]=new void*[50];
        auxClientes[nClientes]=auxCliente;
    }
    clientes=auxClientes;
    nPedidosXCliente=new int[nClientes]{};
    return nPedidosXCliente;
}

void  leerPedidosCliente(ifstream &arch,void *productos,void *&clientes,
    int *nPedidos) {
    char *codProducto, aux;
    int dniCliente, cantidad, indiceProducto, indiceCliente;
    bool debeInsertar, debeDescontar;
    double montoADescontar;
    codProducto = leerCadena(arch,',');
    if(arch.eof()) return;
    arch >> dniCliente >> aux >> cantidad;
    arch.get();
    indiceProducto = buscarProducto(productos, codProducto);
    if(indiceProducto > -1){
        indiceCliente = buscarCliente(clientes, dniCliente);
        if(indiceCliente > -1){
            validarInsercion(productos, indiceProducto, clientes, indiceCliente,
                    cantidad, debeInsertar, debeDescontar, montoADescontar);
            if(debeInsertar){
                insertarPedidoEnCliente(clientes, indiceCliente, debeDescontar,
                        codProducto, cantidad, montoADescontar, nPedidos);
            }
        }
    }
}

int buscarProducto(void *productos, char *codProducto) {
    void **lproductos=(void **)productos;
    for (int i=0; lproductos[i];i++) {
        void **reg=(void **)lproductos[i];
        char *codigo=(char *)reg[0];
        if (strcmp(codigo,codProducto)==0) return i;
    }
    return -1;
}

int buscarCliente(void *clientes, int dniCliente) {
    void **lclientes=(void **)clientes;
    for (int i=0; lclientes[i];i++) {
        void **reg=(void **)lclientes[i];
        int *dni=(int *)reg[0];
        if (*dni == dniCliente) return i;
    }
    return -1;
}

void insertarPedidoEnCliente(void*& clientes, int indiceCliente, bool debeDescontar,
            char *codProducto, int cantidad, double montoPedido, int* nPedidos) {
    void **auxClientes = (void**)clientes;
    void **auxCliente  = (void**)auxClientes[indiceCliente];
    void **auxPedidos = (void**)auxCliente[2];
    void **registro = new void*[3];
    int *auxCantidad = new int;
    *auxCantidad = cantidad;
    double *auxMonto = new double, *auxLinea;
    *auxMonto = montoPedido;
    registro[0] = codProducto;
    registro[1] = auxCantidad;
    registro[2] = auxMonto;
    int indiceInsertado = nPedidos[indiceCliente];
    auxPedidos[indiceInsertado] = registro;
    auxCliente[2] = auxPedidos;
    if(debeDescontar){
        auxLinea = (double*) auxCliente[3];
        *auxLinea -= montoPedido;
        auxCliente[3] = auxLinea;
    }
    auxClientes[indiceCliente] = auxCliente;
    clientes = auxClientes;
    nPedidos[indiceCliente]++;
}

void validarInsercion(void* productos, int indiceProducto, void* clientes,
        int indiceCliente, int cantidad, bool& debeInsertar,
        bool& debeDescontar, double& montoPedido) {
    char tipo;
    double lineaCredito;
    void **auxProductos = (void**) productos;
    void **auxProducto = (void**) auxProductos[indiceProducto];
    void **auxClientes = (void**) clientes;
    void **auxCliente = (void**) auxClientes[indiceCliente];
    tipo = *((char*) auxProducto[3]);
    montoPedido = *((double*) auxProducto[2]) * cantidad;
    if(tipo == 'N'){
        debeInsertar = true;
        debeDescontar = false;
    } else{
        lineaCredito = *((double*) auxCliente[3]);
        if(lineaCredito >= montoPedido){
            debeInsertar = true;
            debeDescontar = true;
        } else
            debeInsertar = false;
    }
}

void agregaPedido(void *clientes,char *codigo,int cant,
    double precio,int &numdat,int &capa) {
    void **lclientes=(void **)clientes;
    if (numdat==capa)
        aumentarEspacio(lclientes[2],numdat,capa);
    void **reg=new void *[3];
    reg[0]=codigo;
    int *auxCant=new int;
    *auxCant=cant;
    reg[1]=auxCant;
    double *auxTotal=new double;
    *auxTotal=cant*precio;
    reg[2]=auxTotal;
    void **lpedidos=(void **)lclientes[2];
    lpedidos[numdat-1]=reg;
    numdat++;
}

void aumentarEspacio(void *&clientes,int &numdat,int &capa) {
    void **lclientes=(void**)clientes;
    capa+=INC;
    if (numdat==0) {
        lclientes=new void*[capa]{};
        numdat++;
    }
    else {
        void**laux=new void*[capa]{};
        for (int i=0;i<numdat;i++)
            laux[i]=lclientes[i];
        delete lclientes;
        lclientes=laux;
    }
    clientes=lclientes;
}

// int buscarCliente(int dni,void *clientes,double linea) {
//     void **lclientes=(void **)clientes;
//     for (int i=0; lclientes[i]; i++) {
//         void **reg=(void **)lclientes[i];
//         int *dniAux=(int *)reg[0];
//         double *credAux=(double *)reg[3];
//         if (dni==*dniAux) {
//             linea=*credAux;
//             return i;
//         }
//     }
//     return -1;
// }

double buscarPrecio(char *codigo,void *productos,char tipo) {
    void **lproductos=(void **)productos;
    for (int i=0; lproductos[i]; i++) {
        char *cod,*prodTipo;
        double *precio;
        void **reg=(void **)lproductos[i];
        cod = (char *)reg[0];
        if (strcmp(codigo,cod)==0) {
            precio=(double *)reg[2];
            prodTipo=(char *)reg[3];
            tipo=*prodTipo;
            return *precio;
        }
    }
    return 0.0;
}

void imprimereporte(void *clientes) {
    ofstream arch("ArchivosDeReporte/InformeFinal.txt",ios::out);
    if (not arch) {
        cout << "No se pudo abrir el archivo reporte" << endl;
        exit(1);
    }
    void** auxClientes = (void**) clientes;
    arch.precision(2);
    for(int i=0; auxClientes[i]; i++){
        imprimeLinea(arch, '=', 100);
        arch << left << setw(20) << "DNI" << setw(50) << "Nombre" <<
                "Crédito" << endl;
        imprimeCliente(arch, auxClientes[i]);
    }
}

void imprimeLinea(ofstream &arch, char car, int n) {
    for (int i=0; i<n; i++) arch.put(car);
    arch<<endl;
}

void imprimeCliente(ofstream& archReporte, void* cliente){
    void** auxCliente, **auxRegistro, **auxPedidos, **auxPedido;
    auxCliente = (void**) cliente;
    auxRegistro = (void**) auxCliente;
    archReporte << left << setw(20) << *((int*) auxRegistro[0]) <<
            setw(50) << (char*) auxRegistro[1] << fixed <<
            *((double*) auxRegistro[3]) << endl;
    imprimeLinea(archReporte, '-', 100);
    archReporte << "Pedidos atendidos:" << endl;
    imprimeLinea(archReporte, '-', 100);
    archReporte << left << setw(10) << "Código" << setw(10) << "Cantidad" <<
            "Total" << endl;
    auxPedidos = (void**) auxRegistro[2];
    if(auxPedidos != nullptr)
        for(int i=0; auxPedidos[i]; i++){
            auxPedido = (void**) auxPedidos[i];
            archReporte << left << setw(10) << ((char*) auxPedido[0]) <<
                    setw(10) << *((int*) auxPedido[1]) <<
                    *((double*) auxPedido[2]) << endl;
        }
    archReporte << endl;
}