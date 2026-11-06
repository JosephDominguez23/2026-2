//
// Created by jdomi on 31/10/2026.
//

#include <iomanip>
#include <iostream>
#include "Veterinaria.h"
#define INC 5

Veterinaria::Veterinaria() {
    arrControl=nullptr;
    numdatControl=0;
    capaControl=0;
    numdatOperacion=0;
    numdatVacuna=0;
}

Veterinaria::~Veterinaria() {
    if (arrControl!=nullptr) delete[] arrControl;
}

int Veterinaria::get_numdat_control() const {
    return numdatControl;
}

void Veterinaria::set_numdat_control(int numdat_control) {
    numdatControl = numdat_control;
}

int Veterinaria::get_capa_control() const {
    return capaControl;
}

void Veterinaria::set_capa_control(int capa_control) {
    capaControl = capa_control;
}

void Veterinaria::cargacitas() {
    ifstream arch("ArchivosDeDatos/Atenciones.csv",ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo atenciones"<<endl;
        exit(1);
    }
    char tipo;
    while (true) {
        arch>>tipo;
        if (arch.eof()) break;
        arch.get();
        if (tipo == 'C') {
            llenarControl(arch);
        } else if (tipo == 'O') {
            arrOperacion[numdatOperacion].leerOperacion(arch);
            numdatOperacion++;
        } else if (tipo == 'V') {
            arrVacuna[numdatVacuna].leeVacuna(arch);
            numdatVacuna++;
        } else {
            while (arch.get() != '\n');
        }
    }
}

void Veterinaria::llenarControl(ifstream &arch) {
    Control aux;
    aux.leerControl(arch);
    if (numdatControl == capaControl)
        incrementarEspacio();
    arrControl[numdatControl-1] = aux;
    numdatControl++;
}

void Veterinaria::incrementarEspacio() {
    Control *aux;
    capaControl+=INC;
    if (numdatControl==0) {
        arrControl=new Control[capaControl];
        numdatControl++;
    } else {
        aux=new Control[capaControl];
        for (int i=0;i<numdatControl;i++) {
            aux[i]=arrControl[i];
        }
        delete [] arrControl;
        arrControl=aux;
    }
}

void Veterinaria::muestracitas() {
    ofstream arch("ArchivosDeReporte/Reporte.txt",ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un inconveniente al generar el reporte solicitado."<<endl;
        exit(1);
    }

    double montoTotalControl = 0;
    int totalVacunas = 0;
    double totalPorOperaciones = 0;;

    imprimeControl(arch,montoTotalControl);
    arch<<endl;
    imprimeVacuna(arch,totalVacunas);
    arch<<endl;
    imprimeOperacion(arch,totalPorOperaciones);
}

void Veterinaria::imprimeOperacion(ofstream &arch, double &totalPorOperaciones) {
    arch<<"Citas de Vacunas: "<<endl;
    arch<<setw(7)<<"Fecha"<<setw(11)<<"Hora"<<setw(9)<<"Raza"<<setw(22)<<"Nombre"<<setw(25)<<"Anestesia"<<setw(20)<<"Numero de medicos"<<endl;
    elaborarLinea(arch,100,'-');

    for (int i = 0; i<numdatOperacion and arrOperacion[i].get_fecha() != 0; i++) {
        arrOperacion[i].imprimeOperacion(arch);
        totalPorOperaciones += arrOperacion[i].get_total();
    }
    arch<<endl<<"Total por operaciones: "<<totalPorOperaciones<<endl;
}

void Veterinaria::imprimeVacuna(ofstream &arch, int &totalVacunas) {
    arch<<"Citas de Vacunas: "<<endl;
    arch<<setw(7)<<"Fecha"<<setw(11)<<"Hora"<<setw(9)<<"Raza"<<setw(22)<<"Nombre"<<setw(21)<<"Dosis"<<setw(30)<<"Meses próxima Dosis"<<endl;
    elaborarLinea(arch,100,'-');

    for (int i = 0; i<numdatVacuna and arrVacuna[i].get_fecha() != 0; i++) {
        arrVacuna[i].imprimirVacuna(arch);
        totalVacunas += arrVacuna[i].get_dosis();
    }
    arch<<endl<<"Numero de vacunas: "<<totalVacunas<<endl;

}

void Veterinaria::imprimeControl(ofstream &arch, double &montoTotalControl) {

    arch<<"Citas de Control: "<<endl;
    arch<<setw(7)<<"Fecha"<<setw(11)<<"Hora"<<setw(9)<<"Raza"<<setw(22)<<"Nombre"<<setw(24)<<"Cod. Medico"<<setw(9)<<"Monto"<<endl;
    elaborarLinea(arch,100,'-');

    arch.precision(2);
    arch<<fixed;

    for (int i = 0; i<numdatControl and arrControl[i].get_fecha() != 0; i++) {
        arrControl[i].imprimeControl(arch);
        montoTotalControl += arrControl[i].get_costo();
    }
    arch<<endl<<"Monto por Control: "<<montoTotalControl<<endl;
}

int Veterinaria::get_numdat_vacuna() const {
    return numdatVacuna;
}

void Veterinaria::set_numdat_vacuna(int numdat_vacuna) {
    numdatVacuna = numdat_vacuna;
}

int Veterinaria::get_numdat_operacion() const {
    return numdatOperacion;
}

void Veterinaria::set_numdat_operacion(int numdat_operacion) {
    numdatOperacion = numdat_operacion;
}

void Veterinaria::elaborarLinea(ofstream &arch, int max, char c) {
    for (int i = 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}
