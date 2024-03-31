//
// Created by carlos on 30/03/24.
//

#ifndef POYECTO_2_NODOARBOL_H
#define POYECTO_2_NODOARBOL_H
#include "../Parametro/Parametro.h"
class Parametro;
class NodoArbol {
public:
    Parametro *valor;
    NodoArbol *izq;
    NodoArbol *der;
    NodoArbol *padre;
    int alturaIzq;
    int alturaDer;
    int fe;
    NodoArbol();
    ~NodoArbol();
};


#endif //POYECTO_2_NODOARBOL_H
