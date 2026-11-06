//
// Created by jdomi on 5/11/2026.
//

#ifndef STREAMERSHERENCIA_STREAMERPAGO_H
#define STREAMERSHERENCIA_STREAMERPAGO_H
#include "MetricaBasica.h"
#include "MetricaCalidad.h"
#include "MetricaEngagement.h"
#include "Streamers.h"


class StreamerPago:public Streamers{
private:
    int fecha_inicio_plan;
    MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;
    MetricaEngagement *metricas_engagements;
    int cantidad_metricas_engagements;
    MetricaCalidad *metricas_calidades;
    int cantidad_metricas_calidades;
public:
    StreamerPago();
    ~StreamerPago();

    int get_fecha_inicio_plan() const;
    void set_fecha_inicio_plan(int fecha_inicio_plan);
    int get_cantidad_metricas_basicas() const;
    void set_cantidad_metricas_basicas(int cantidad_metricas_basicas);
    int get_cantidad_metricas_engagements() const;
    void set_cantidad_metricas_engagements(int cantidad_metricas_engagements);
    int get_cantidad_metricas_calidades() const;
    void set_cantidad_metricas_calidades(int cantidad_metricas_calidades);

    void leerPago(ifstream &);
    void operator=(StreamerPago &);
    void actualizarEngage(ifstream &);
    void actualizarDatosQualities(ifstream &);
    void actualizarDatosBasic(ifstream &);
};


#endif //STREAMERSHERENCIA_STREAMERPAGO_H