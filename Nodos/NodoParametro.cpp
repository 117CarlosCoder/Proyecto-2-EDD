//
// Created by carlos on 30/03/24.
//

#include "NodoParametro.h"

NodoParametro::NodoParametro() {
    parametro = "";
    tipo = "";
    valor = nullptr;
}

NodoParametro::~NodoParametro() {
    delete valor;
}
