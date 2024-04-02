//
// Created by carlosl on 31/03/24.
//

#ifndef POYECTO_2_LISTADOBLEMENTEENLAZADA_H
#define POYECTO_2_LISTADOBLEMENTEENLAZADA_H


#include "../Parametro/Parametro.h"
#include <string>

using namespace std;
class Parametro;
class ListaDoblementeEnlazada {
private:
    Parametro *raiz;
public:
    int cantidad;
    ListaDoblementeEnlazada();
    ~ListaDoblementeEnlazada();
    void ingresar(Parametro *x);
    void imprimir();
    string obtenerValorEnPosicion(int posicion);
};


#endif //POYECTO_2_LISTADOBLEMENTEENLAZADA_H
