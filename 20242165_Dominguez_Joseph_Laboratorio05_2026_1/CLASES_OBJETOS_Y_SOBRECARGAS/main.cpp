#include <iostream>
#include "Bibliotecas/Veterinaria.h"

int main() {

    Veterinaria vet;
    vet.cargarMascota("ArchivosDeDatos/mascotas.csv");
    vet.cargaVacunas("ArchivosDeDatos/vacunasAplicadas.csv");
    vet.imprime_reporte("ArchivosDeReporte/ReporteVeterinaria.txt");

    return 0;
}