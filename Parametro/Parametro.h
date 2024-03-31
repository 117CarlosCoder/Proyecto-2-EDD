//
// Created by carlos on 30/03/24.
//

#ifndef POYECTO_2_PARAMETRO_H
#define POYECTO_2_PARAMETRO_H
#include <string>
#include "../Nodos/NodoGrupo.h"
using namespace std;

class NodoGrupo;
class Parametro {
public:
    string valor;
    int valorAscii;
    NodoGrupo *grupo;
    string tipo;
    Parametro *parametroAnt;
    Parametro *parametroSig;
    Parametro();
    ~Parametro();
};


#endif //POYECTO_2_PARAMETRO_H
