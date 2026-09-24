#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

#include "Bibliotecas/Funciones.h"

int main() {

    char ***ventas=nullptr;
    char ****detalleTexto=nullptr;
    int ***detalleValor=nullptr;

    cargaVentas("ArchivosDeDatos/Ventas.csv",ventas);
    imprimirReporte("ArchivosDeReporte/ReporteVentas.txt",ventas,
        detalleTexto,detalleValor);

    cargarDetallesDeVenta("ArchivosDeDatos/DetalleVentas.csv",ventas,detalleTexto,
        detalleValor);
    imprimirReporte("ArchivosDeReporte/ReporteVentasConDetalles.txt",ventas,
        detalleTexto,detalleValor);

    cargarDetalleProducto("ArchivosDeDatos/Productos.csv",ventas,
        detalleTexto,detalleValor);
    imprimirReporte("ArchivosDeReporte/ReporteVentasConDetallesProductos.txt",ventas,
        detalleTexto,detalleValor);

    return 0;
}