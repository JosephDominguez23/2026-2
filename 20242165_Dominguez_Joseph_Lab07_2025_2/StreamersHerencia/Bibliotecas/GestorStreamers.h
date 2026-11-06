//
// Created by jdomi on 5/11/2026.
//

#ifndef STREAMERSHERENCIA_GESTORSTREAMERS_H
#define STREAMERSHERENCIA_GESTORSTREAMERS_H
#include "StreamerGratuito.h"
#include "StreamerPago.h"


class GestorStreamers {
private:
    StreamerGratuito *streamer_gratuitos;
    StreamerPago *streamer_pagados;
    int cantidad_gratuitos;
    int cantidad_pagados;
public:
    GestorStreamers();
    ~GestorStreamers();

    int get_cantidad_gratuitos() const;
    void set_cantidad_gratuitos(int cantidad_gratuitos);
    int get_cantidad_pagados() const;
    void set_cantidad_pagados(int cantidad_pagados);

    void cargar_datos_streamers(const char *);
    void actualizar_datos_metricas(const char *);
    void generar_reportes();
    void actualizarEngagements(ifstream &);
    void actualizarBasics(ifstream &);
    void actualizarQualities(ifstream &);
    int buscarStreamPago(int);
};


#endif //STREAMERSHERENCIA_GESTORSTREAMERS_H