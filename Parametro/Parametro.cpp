//
// Created by carlos on 30/03/24.
//

#include "Parametro.h"

Parametro::Parametro() {
    valor="";
    valorAscii=0;
    grupo = nullptr;
    tipo = "";
    parametroAnt = nullptr;
    parametroSig = nullptr;
}

Parametro::~Parametro() {
    delete grupo;
    delete parametroSig;
    delete parametroAnt;
}
