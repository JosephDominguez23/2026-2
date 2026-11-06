//
// Created by jdomi on 5/11/2026.
//

#include "GestorStreamers.h"

#include <cstring>
#include <iostream>

GestorStreamers::GestorStreamers() {
    streamer_gratuitos=nullptr;
    streamer_pagados=nullptr;
    cantidad_gratuitos=0;
    cantidad_pagados=0;
}

GestorStreamers::~GestorStreamers() {
    if (streamer_gratuitos!=nullptr) delete [] streamer_gratuitos;
    if (streamer_pagados!=nullptr) delete [] streamer_pagados;
}


int GestorStreamers::get_cantidad_gratuitos() const {
    return cantidad_gratuitos;
}

void GestorStreamers::set_cantidad_gratuitos(int cantidad_gratuitos) {
    this->cantidad_gratuitos = cantidad_gratuitos;
}

int GestorStreamers::get_cantidad_pagados() const {
    return cantidad_pagados;
}

void GestorStreamers::set_cantidad_pagados(int cantidad_pagados) {
    this->cantidad_pagados = cantidad_pagados;
}

void GestorStreamers::cargar_datos_streamers(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    //Gratuito,174920,xQcOW,PUBG,3246298,2025-10-17
    char cad[100];
    StreamerGratuito bufferG[100];
    StreamerPago bufferP[100];
    while (true) {
        arch.getline(cad,100,',');
        if (arch.eof()) break;
        arch.get();
        if (strcmp(cad,"Gratuito")==0) {

            bufferG[cantidad_gratuitos].leerGratuito(arch);
            cantidad_gratuitos++;
        } else if (strcmp(cad,"Pagado")==0) {
            bufferP[cantidad_pagados].leerPago(arch);
            cantidad_pagados++;
        } else {
            while (arch.get()!='\n');
        }
    }
    streamer_gratuitos=new StreamerGratuito[cantidad_gratuitos+1];
    streamer_pagados=new StreamerPago[cantidad_pagados+1];
    for (int i=0;i<cantidad_gratuitos;i++) {
        streamer_gratuitos[i]=bufferG[i];
    }
    for (int i=0;i<cantidad_pagados;i++) {
        streamer_pagados[i]=bufferP[i];
    }
}

void GestorStreamers::actualizar_datos_metricas(const char *nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout<<"No se pudo abrir el archivo "<<nom<<endl;
        exit(1);
    }
    //ENGAGEMENT,320975,121,Maratón de chat,2025-10-17,2025-10-31,1535,553,54
    char cad[100];
    while (true) {
        arch.getline(cad,100,',');
        if (arch.eof()) break;
        arch.get();
        if (strcmp(cad,"ENGAGEMENT")==0) {
            actualizarEngagements(arch);
        } else if (strcmp(cad,"BASIC")==0) {
            actualizarBasics(arch);
        } else if (strcmp(cad,"QUALITY")==0) {
            actualizarQualities(arch);
        }
    }
}

void GestorStreamers::actualizarEngagements(ifstream &arch) {
    int idStreamer;
    arch>>idStreamer;
    arch.get();
    int pos=buscarStreamPago(idStreamer);
    if (pos!=-1) {
        streamer_pagados[pos].actualizarEngage(arch);
    }
}

int GestorStreamers::buscarStreamPago(int idS) {
    for (int i=0;i<cantidad_pagados;i++) {
        if (idS==streamer_pagados[i].get_id()) return i;
    }
    return -1;
}

void GestorStreamers::actualizarQualities(ifstream &arch) {
    int idStreamer;
    arch>>idStreamer;
    arch.get();
    int posStreamer = buscarStreamPago(idStreamer);
    if (posStreamer != -1) {
        streamer_pagados[posStreamer].actualizarDatosQualities(arch);
    }
}

void GestorStreamers::actualizarBasics(ifstream &arch) {
    int idStreamer;
    arch>>idStreamer;
    arch.get();
    for (int i = 0; i < cantidad_gratuitos;i++) {
        if (idStreamer == streamer_gratuitos[i].get_id()) {
            streamer_gratuitos[i].actualizarDatos(arch);
            return;
        }
    }
    for (int i= 0; i < cantidad_pagados;i++) {
        if (idStreamer == streamer_pagados[i].get_id()) {
            streamer_pagados[i].actualizarDatosBasic(arch);
            return;
        }
    }
}

