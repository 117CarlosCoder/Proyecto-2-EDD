//
// Created by carlos on 23/03/24.
//

#include <iostream>
#include "Hash.h"

void Hash::ingresarGrupo(NodoGrupo *nodoGrupo) {
    espacioGrupo++;
    int indiceGrupo = convertirAscii(nodoGrupo->grupo);
    grupo[indiceGrupo].grupo = nodoGrupo->grupo;
    grupo[indiceGrupo].sig = nodoGrupo->sig;
}

void Hash::ingresarParametro(NodoParametro *parametroNuevo) {
    espacioParametro++;
    int indiceParametro = convertirAscii(parametroNuevo->parametro);
    cout<<"Nodo Parametro "<< parametroNuevo->tipo<<endl;
    cout<<"Nodo Parametro "<< parametroNuevo->parametro<<endl;
    parametro[indiceParametro].parametro = parametroNuevo->parametro;
    parametro[indiceParametro].valor = parametroNuevo->valor;
}

int Hash::convertirAscii(string valor) {
    int suma = 0;
    for (int i = 0; i < valor.length(); i++)
    {
        char x = valor.at(i);
        cout<<"Ascii "<<int(x)<<endl;
        suma = suma + int(x);
    }
    cout<<" Valor Ascii "<< suma<<endl;
    suma = suma % 10;
    cout<<" indice tabla hash "<<suma<<endl;

    return suma;
}

void Hash::imprimirGrupo() {
    cout<<"Gruṕo"<<endl;
    int contador = 0;
    for (auto & i : grupo) {
        cout<<contador<<" "<<i.grupo<<endl;
        contador++;
    }
}

void Hash::imprimirParametro() {
    cout<<"Parametro"<<endl;
    int contador = 0;
    for (auto & i : parametro) {
        cout<<contador<<endl;
        if (!i.parametro.empty()){
            cout<<" "<<i.parametro<<endl;
        }
        contador++;
    }
}


