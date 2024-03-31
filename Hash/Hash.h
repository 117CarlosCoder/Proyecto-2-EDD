//
// Created by carlos on 30/03/24.
//

#ifndef POYECTO_2_HASH_H
#define POYECTO_2_HASH_H
#include <string>
#include "../Nodos/NodoParametro.h"
#include "../Nodos/NodoGrupo.h"


class Hash {
private:
    NodoGrupo grupo[10];
    NodoParametro parametro[10];
    int espacioGrupo;
    int espacioParametro;
    int convertirAscii(string valor);

public:
    NodoParametro claveParametro;
    NodoGrupo claveGrupo;
    int indice;


    void ingresarGrupo(NodoGrupo *nodoGrupo);
    void ingresarParametro(NodoParametro *parametro);
    void imprimirGrupo();
    void imprimirParametro();


};


#endif //POYECTO_2_HASH_H
