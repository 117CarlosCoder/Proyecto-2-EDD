//
// Created by carlosl on 1/04/24.
//

#ifndef POYECTO_2_COMANDOS_H
#define POYECTO_2_COMANDOS_H

#include <string>
#include "../Parametro/Parametro.h"
#include "../Hash/Hash.h"

class Parametro;
class Hash;
class NodoParametro;
class NodoGrupo;
class Comandos {
public:
    Parametro parametroN;
    NodoParametro* nodoParametro;
    NodoParametro nodoParametroNuev;
    NodoGrupo* nodoGrupo;
    NodoGrupo nodoGrupoNuev;
    Comandos();

    void ejecutar(string comando, Hash *hashGroup, Hash *hashParametro);
};


#endif //POYECTO_2_COMANDOS_H
