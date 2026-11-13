#include "Biblioteca/AdministrarMetricas.h"
using namespace std;

int main() {
    AdministrarMetricas admin;

    admin.cargarArchivo("Datos/metricas.csv");
    admin.generarReporte("Reporte/reporte.txt");
    admin.eliminarNodos();
    admin.generarReporte("Reporte/reporteActivo.txt");
    admin.eliminarLista();

    return 0;
}
