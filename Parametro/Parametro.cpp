//
// Created by carlos on 30/03/24.
//

#include "Parametro.h"
#include <string>
#include <iostream>

using namespace std;

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


