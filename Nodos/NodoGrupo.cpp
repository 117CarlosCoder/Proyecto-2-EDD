//
// Created by carlos on 30/03/24.
//

#include "NodoGrupo.h"

NodoGrupo::NodoGrupo() {
    grupo = "";
    listaDoblementeEnlazada = nullptr;
    parametros = nullptr;
}

NodoGrupo::~NodoGrupo() {
    delete listaDoblementeEnlazada;
    delete parametros;
}
