#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

#include "Bibliotecas/GestorStreamers.h"
using namespace std;

int main() {

    GestorStreamers str;

    str.cargar_datos_streamers("ArchivosDeDatos/streamers.csv");
    str.actualizar_datos_metricas("ArchivosDeDatos/metricas.csv");

    return 0;
}