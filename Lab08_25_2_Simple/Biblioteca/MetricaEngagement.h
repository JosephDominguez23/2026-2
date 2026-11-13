//
// Created by Alan on 11/06/2026.
//

#ifndef LAB08_25_2_METRICAENGAGEMENT_H
#define LAB08_25_2_METRICAENGAGEMENT_H
#include "Metrica.h"


class MetricaEngagement:public Metrica {
private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;

public:
    MetricaEngagement();
    int get_mensajes_chat() const;
    void set_mensajes_chat(int mensajes_chat);
    int get_usuarios_unicos_chat() const;
    void set_usuarios_unicos_chat(int usuarios_unicos_chat);
    int get_clips_generados() const;
    void set_clips_generados(int clips_generados);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    const char* tipoMetrica() const;
};


#endif //LAB08_25_2_METRICAENGAGEMENT_H
