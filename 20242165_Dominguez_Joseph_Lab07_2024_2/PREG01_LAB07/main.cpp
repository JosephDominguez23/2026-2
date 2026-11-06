#include <iostream>

#include "Bibliotecas/Restaurante.h"

using namespace std;

int main() {

    Restaurante res;

    res.cargar_comandas();
    res.imprimir_comandas();

    return 0;
}