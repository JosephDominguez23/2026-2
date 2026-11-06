//
// Created by jdomi on 5/11/2026.
//

#ifndef STREAMERSHERENCIA_STREAMERS_H
#define STREAMERSHERENCIA_STREAMERS_H
#include <fstream>
using namespace std;

class Streamers {
private:
    int id;
    char *cuenta;
    int  n_seguidores;
    char *categoria;
public:
    Streamers();
    ~Streamers();

    int get_id() const;
    void set_id(int id);
    int get_n_seguidores() const;
    void set_n_seguidores(int n_seguidores);
    void set_cuenta(const char *cuenta);
    void get_cuenta(char *cuenta);
    void set_categoria(const char *categoria);
    void get_categoria(char *categoria);

    void leerStreamer(ifstream &);
    void imprimirStreamer(ofstream &);
    void operator=(Streamers &);
};


#endif //STREAMERSHERENCIA_STREAMERS_H