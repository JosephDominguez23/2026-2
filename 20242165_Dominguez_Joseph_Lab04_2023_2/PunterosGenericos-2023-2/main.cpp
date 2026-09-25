#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "Bibliotecas/Funciones.h"

using namespace std;

int main() {
    void *productos, *clientes;
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos, clientes);
    imprimereporte(clientes);
    return 0;
}