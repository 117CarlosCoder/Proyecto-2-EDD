//
// Created by carlos on 30/03/24.
//

#include "NodoGrupo.h"

NodoGrupo::NodoGrupo() {
    grupo = "";
    sig = nullptr;
}

NodoGrupo::~NodoGrupo() {
    delete sig;
}
