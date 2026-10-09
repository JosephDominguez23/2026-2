//
// Created by jdomi on 8/10/2026.
//

#ifndef CLASES_OBJETOS_PLATO_H
#define CLASES_OBJETOS_PLATO_H

#include <fstream>
using namespace std;
class Plato {
    private:
        char *codigo;
        char *nombre;
        double precio;
        char *categoria;
        int preparados;
        double descuento;
        int atendidos;
        int noAtendidos;
        double totalEsperado;
        double totalBruto;
        double totalNeto;
    public:
        Plato();
        ~Plato();

        double get_precio() const;
        void set_precio(double precio);
        int get_preparados() const;
        void set_preparados(int preparados);
        double get_descuento() const;
        void set_descuento(double descuento);
        int get_atendidos() const;
        void set_atendidos(int atendidos);
        int get_no_atendidos() const;
        void set_no_atendidos(int no_atendidos);
        double get_total_esperado() const;
        void set_total_esperado(double total_esperado);
        double get_total_bruto() const;
        void set_total_bruto(double total_bruto);
        double get_total_neto() const;
        void set_total_neto(double total_neto);
        void set_nombre(const char *nombre);
        void get_nombre(char *nombre);
        void set_codigo(const char *codigo);
        void get_codigo(char *codigo);
        void set_categoria(const char *categoria);
        void get_categoria(char *categoria);
        void lee_plato(ifstream &);
};


#endif //CLASES_OBJETOS_PLATO_H