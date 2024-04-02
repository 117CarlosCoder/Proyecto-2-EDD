//
// Created by carlos on 23/03/24.
//

#include <iostream>
#include <utility>
#include "Hash.h"



void Hash::ingresarGrupo(NodoGrupo *nodoGrupo) {
    espacioGrupo++;
    int indiceGrupo = convertirAscii(nodoGrupo->grupo);
    grupo[indiceGrupo] = new NodoGrupo();
    grupo[indiceGrupo] = nodoGrupo;
}

void Hash::ingresarParametro(NodoParametro *parametroNuevo) {
    espacioParametro++;
    int indiceParametro = convertirAscii(parametroNuevo->parametro);
    parametro[indiceParametro] = new NodoParametro();
    parametro[indiceParametro]->parametro = parametroNuevo->parametro;
    parametro[indiceParametro]->valor = parametroNuevo->valor;
}

int Hash::convertirAscii(string valor) {
    int suma = 0;
    for (int i = 0; i < valor.length(); i++)
    {
        char x = valor.at(i);
        suma = suma + int(x);
    }
    suma = suma % 10;

    return suma;
}

NodoParametro* Hash::buscarParametro(string parametron) {
    int indiceParametro = convertirAscii(std::move(parametron));
    return parametro[indiceParametro];
}

NodoGrupo* Hash::buscarGrupo(string grupon) {
    int indiceGrupo = convertirAscii(std::move(grupon));
    return grupo[indiceGrupo];
}

void Hash::imprimirGrupo() {
    cout<<"Grupo"<<endl;
    int contador = 0;
    for (auto & i : grupo) {
        if (i!= nullptr) {
            cout << contador << " " << i->grupo << endl;
        }
        contador++;
    }
}

void Hash::imprimirParametro() {
    cout<<"Parametro"<<endl;
    int contador = 0;
    for (auto & i : parametro) {
        if (i != nullptr){
            if (!i->parametro.empty()){
                cout<<contador<<" "<<i->parametro<<endl;
                contador++;
            }else {
                cout << contador << endl;
                contador++;
            }
        }
    }
}



