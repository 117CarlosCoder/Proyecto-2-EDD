//
// Created by carlos on 30/03/24.
//

#ifndef POYECTO_2_NODOPARAMETRO_H
#define POYECTO_2_NODOPARAMETRO_H
#include <string>
#include "../Parametro/Parametro.h"
#include "../Arbol/Arbol.h"
using namespace std;
class Arbol;
class NodoParametro {
public:
    string parametro;
    string tipo;
    Arbol  *valor;
    NodoParametro();
    ~NodoParametro();
};


#endif //POYECTO_2_NODOPARAMETRO_H
