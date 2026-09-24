//
// Created by jdomi on 24/09/2026.
//

#ifndef ASIGNACIONEFICIENTEDEMEMORIA_2026_2_FUNCIONES_H
#define ASIGNACIONEFICIENTEDEMEMORIA_2026_2_FUNCIONES_H

void cargaVentas(const char *nom,char ***&ventas);
char **leerVentas(ifstream &arch);
char *leerCadena(ifstream &arch,char carlim);
void imprimirReporte(const char *nom,char ***ventas,
        char ****detalleTexto,int ***detalleValor);
void imprimirVenta(ofstream &arch,char **ventas);
void cargarDetallesDeVenta(const char *nom,char ***ventas,char ****&detalleTexto,
        int ***&detalleValor);
int buscarVenta(char *codigoVenta,char ***ventas);
void procesarDetalleDeVenta(ifstream &arch,int pos,char ****detalleTexto,int ***detalleValor,
                int *numData,int *capacidad);
void incrementarEspacio(char ***&detalleTexto,int **&detalleValor,int &numData,
            int &capacidad);
void agregarDetalle(ifstream &arch,char ***detalleTexto,int **detalleValor,int &numData);
int leerInt(ifstream &arch, bool leer);
double leeDbl(ifstream &arch, bool leer);
void imprimirDetalles(ofstream &arch,char ***detalleTexto,int **detalleValor);
void imprimirDetail(ofstream &arch,char **detalleTexto,const int *detalleValor);
void cargarDetalleProducto(const char *nom,char ***ventas,
        char ****detalleTexto,int ***detalleValor);
void completarVentas(char ***detalleTexto,int **detalleValor,
                const char *codProd,char *descripcion,char *categoria,int costUnit,int precUnit);
void verificarYAsignar(char **detalleTexto,int *detalleValor,
        const char *codProd,char *descripcion,char *categoria,int costUnit,int precUnit);
void imprimirEncabezado(ofstream &arch, const char **cabeza);
void imprimirTotales(ofstream &arch, const double totalCosto, const double totalPrecio);
void calcularTotales(double &costoTotal,double &totalPrecio,double &gananciaTotal,
        int **detalleValor);
void imprimirLinea(ofstream &arch,int n,char car);


#endif //ASIGNACIONEFICIENTEDEMEMORIA_2026_2_FUNCIONES_H