#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "Bibliotecas/MinisterioDeTransporte.h"
using namespace std;

int main() {

    MinisterioDeTransporte min;

    min<"ArchivosDeDatos/TablaDeInfracciones.csv";
    min<="ArchivosDeDatos/EmpresasRegistradas.csv";
    min<<="ArchivosDeDatos/InfraccionesCometidas.csv";
    min>>"ArchivosDeReporte/ReporteParElMinisterio.txt";

    return 0;
}