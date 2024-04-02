//
// Created by carlos on 30/03/24.
//

#ifndef POYECTO_2_NODOGRUPO_H
#define POYECTO_2_NODOGRUPO_H
#include <string>
#include "../ListaDoblementeEnlazada/ListaDoblementeEnlazada.h"

using namespace std;
class ListaDoblementeEnlazada;
class NodoGrupo {
public:
    string grupo;
    ListaDoblementeEnlazada *parametros;
    ListaDoblementeEnlazada *listaDoblementeEnlazada;
    NodoGrupo();
    ~NodoGrupo();
};


#endif //POYECTO_2_NODOGRUPO_H
