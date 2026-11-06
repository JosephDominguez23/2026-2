//
// Created by jdomi on 5/11/2026.
//

#ifndef STREAMERSHERENCIA_METRICAENGAGEMENT_H
#define STREAMERSHERENCIA_METRICAENGAGEMENT_H
#include <iosfwd>
#include <fstream>

#include "Metrica.h"
using namespace std;

class MetricaEngagement:public Metrica{
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

    void leerEngagement(ifstream &);
    void imprimirEngagement(ofstream &);
};


#endif //STREAMERSHERENCIA_METRICAENGAGEMENT_H