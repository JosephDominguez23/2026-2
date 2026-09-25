//
// Created by jdomi on 24/09/2026.
//

#ifndef PUNTEROSGENERICOS_2023_2_FUNCIONES_H
#define PUNTEROSGENERICOS_2023_2_FUNCIONES_H

using namespace std;

void cargaproductos(void*& productos);
void cargaclientes(void*& clientes);
void cargapedidos(void* productos, void*& clientes);
void imprimereporte(void* clientes);

void *leerClientes(ifstream &arch);
char *leerCadena(ifstream &arch,char carlim);
void *leerProductos(ifstream &arch);

// int buscarCliente(int dni,void *clientes,double linea);
double buscarPrecio(char *codigo,void *productos,char tipo);
void agregaPedido(void *clientes,char *codigo,int cant,
    double precio,int &numdat,int &capa);
void aumentarEspacio(void *&clientes,int &numdat,int &capa);

int *asignarMemoriaTemporal(void *&clientes);
void  leerPedidosCliente(ifstream &arch,void *productos,void *&clientes,
    int *nPedidos);
int buscarProducto(void *productos, char *codProducto);
int buscarCliente(void *clientes, int dniCliente);
void validarInsercion(void* productos, int indiceProducto, void* clientes,
        int indiceCliente, int cantidad, bool& debeInsertar,
        bool& debeDescontar, double& montoPedido);
void insertarPedidoEnCliente(void*& clientes, int indiceCliente, bool debeDescontar,
            char *codProducto, int cantidad, double montoPedido, int* nPedidos);
void asignarMemoriaExactaEnPedidos(void *& clientes, int* nPedidos);

void imprimeLinea(ofstream &arch, char car, int n);
void imprimeCliente(ofstream& archReporte, void* cliente);



#endif //PUNTEROSGENERICOS_2023_2_FUNCIONES_H