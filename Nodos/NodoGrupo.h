//
// Created by carlos on 30/03/24.
//

#ifndef POYECTO_2_NODOGRUPO_H
#define POYECTO_2_NODOGRUPO_H
#include <string>
#include "NodoParametro.h"
using namespace std;
class NodoParametro;
class NodoGrupo {
public:
    string grupo;
    NodoParametro *sig;
    NodoGrupo();
    ~NodoGrupo();
};


#endif //POYECTO_2_NODOGRUPO_H
