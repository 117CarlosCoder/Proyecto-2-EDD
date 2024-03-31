//
// Created by carlos on 30/03/24.
//

#include "NodoArbol.h"

NodoArbol::NodoArbol() {
    valor = nullptr;
    izq = nullptr;
    der = nullptr;
    padre = nullptr;
    alturaIzq = 0;
    alturaDer = 0;
    fe = 0;
}

NodoArbol::~NodoArbol() {
    delete valor;
    delete izq;
    delete der;
    delete padre;
}