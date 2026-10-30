#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "Bibliotecas/Restaurante.h"
using namespace std;

int main() {

    Restaurante res;

    res<"ArchivosDeDatos/Clientes.csv";
    res<="ArchivosDeDatos/PlatosOfrecidos.csv";
    res<<="ArchivosDeDatos/Pedidos.csv";
    res>>"ArchivosDeReporte/ReporteDeVentasDelDia.txt";

    return 0;
}