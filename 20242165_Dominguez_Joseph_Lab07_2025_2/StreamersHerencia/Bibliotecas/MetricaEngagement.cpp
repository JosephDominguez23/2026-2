//
// Created by jdomi on 5/11/2026.
//

#include "MetricaEngagement.h"

MetricaEngagement::MetricaEngagement() {
    mensajes_chat=0;
    usuarios_unicos_chat=0;
    clips_generados=0;
}

int MetricaEngagement::get_mensajes_chat() const {
    return mensajes_chat;
}

void MetricaEngagement::set_mensajes_chat(int mensajes_chat) {
    this->mensajes_chat = mensajes_chat;
}

int MetricaEngagement::get_usuarios_unicos_chat() const {
    return usuarios_unicos_chat;
}

void MetricaEngagement::set_usuarios_unicos_chat(int usuarios_unicos_chat) {
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEngagement::get_clips_generados() const {
    return clips_generados;
}

void MetricaEngagement::set_clips_generados(int clips_generados) {
    this->clips_generados = clips_generados;
}

void MetricaEngagement::leerEngagement(ifstream &arch) {
    //1535,553,54
    char c;
    leerMetrica(arch);
    arch>>mensajes_chat>>c>>usuarios_unicos_chat>>c>>clips_generados;
    arch.get();
}

void MetricaEngagement::imprimirEngagement(ofstream &arch) {

}

