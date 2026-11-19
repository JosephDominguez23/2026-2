#include <iostream>

#include "Bibliotecas/PackageManager.h"

int main() {

    PackageManager manager;

    manager.load_packages();
    manager.process_packages();

    return 0;
}
