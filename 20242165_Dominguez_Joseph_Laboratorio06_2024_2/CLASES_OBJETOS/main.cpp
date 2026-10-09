#include <iostream>
#include "Biblioteca/Restaurante.h"

int main() {
    Restaurante rest;
    rest.cargaclientes("Clientes (1).csv");
    rest.borracliente();
    rest.cargaplato("PlatosOfrecidos (1).csv");
    rest.procesapedidos("Pedidos.csv");
    rest.imprimeclientes("ReporteClie.txt");


    return 0;
}