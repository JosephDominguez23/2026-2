#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "Bibliotecas/Veterinaria.h"
using namespace std;

int main() {

    Veterinaria vet;
    vet<="ArchivosDeDatos/mascotas.csv";
    vet<<="ArchivosDeDatos/vacunasAplicadas.csv";
    vet<<"ArchivosDeReporte/ReporteVeterinaria.txt";

    return 0;
}