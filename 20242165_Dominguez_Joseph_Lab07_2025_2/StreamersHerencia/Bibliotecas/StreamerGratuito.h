//
// Created by jdomi on 5/11/2026.
//

#ifndef STREAMERSHERENCIA_STREAMERGRATUITO_H
#define STREAMERSHERENCIA_STREAMERGRATUITO_H
#include "MetricaBasica.h"
#include "Streamers.h"


class StreamerGratuito:public Streamers{
private:
    int fecha_fin_trial;
    MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;
public:
    StreamerGratuito();
    ~StreamerGratuito();

    int get_fecha_fin_trial() const;
    void set_fecha_fin_trial(int fecha_fin_trial);
    int get_cantidad_metricas_basicas() const;
    void set_cantidad_metricas_basicas(int cantidad_metricas_basicas);

    void leerGratuito(ifstream &);
    void operator=(StreamerGratuito &);
    void actualizarDatos(ifstream &);
};


#endif //STREAMERSHERENCIA_STREAMERGRATUITO_H