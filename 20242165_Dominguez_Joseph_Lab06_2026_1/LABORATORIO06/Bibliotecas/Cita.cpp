//
// Created by jdomi on 31/10/2026.
//

#include "Cita.h"

#include <iomanip>

Cita::Cita() {
    fecha = 0;
    hora = 0;
}

int Cita::get_fecha() const {
    return fecha;
}

void Cita::set_fecha(int fecha) {
    this->fecha = fecha;
}

int Cita::get_hora() const {
    return hora;
}

void Cita::set_hora(int hora) {
    this->hora = hora;
}

void Cita::leercita(ifstream &arch) {
    //C,7/04/2025,11,101,Luna,C,Labrador,1222,20
    int d,m,a,nfecha,hh,mm,ss,nhora;
    char c;
    arch>>d>>c>>m>>c>>a>>c>>nhora>>c;
    nfecha=a*10000+m*100+d;
    fecha=nfecha;
    hora=nhora;
    Amascota.leerMascota(arch);
}

void Cita::operator=(Cita &orig) {
    fecha = orig.fecha;
    hora = orig.hora;
    Amascota = orig.Amascota;
}

void Cita::imprimirCita(ofstream &arch) {
    int dia, mes, anho;
    anho = fecha/10000;
    mes = (fecha%10000) / 100;
    dia = (fecha%10000) % 100;
    arch<<"  "<<setfill('0')<<setw(4)<<anho<<"."<<setw(2)<<mes<<"."<<setw(2)<<dia<<setfill(' ')<<"  "<<setfill('0')<<setw(2)<<hora<<setfill(' ')<<":00   ";
    Amascota.imprimirMascota(arch);
}
