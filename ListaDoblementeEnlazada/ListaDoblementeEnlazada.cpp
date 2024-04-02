//
// Created by carlosl on 31/03/24.
//

#include "ListaDoblementeEnlazada.h"
#include <iostream>

ListaDoblementeEnlazada::ListaDoblementeEnlazada() {
    raiz = nullptr;
    cantidad = 0;
}

ListaDoblementeEnlazada::~ListaDoblementeEnlazada() {
    Parametro *reco = raiz;
    Parametro *bor;
    while (reco != nullptr)
    {
        bor = reco;
        reco = reco->parametroSig;
        delete bor;
    }
}

void ListaDoblementeEnlazada::ingresar(Parametro *x) {
    auto* nuevo = new Parametro();
    nuevo->valor = x->valor;
    nuevo->tipo = x->tipo;
    nuevo->valorAscii = x->valorAscii;
    nuevo->grupo=new NodoGrupo();
    nuevo->grupo = x->grupo;
    if (raiz == nullptr) {
        raiz = nuevo;
    } else {
        nuevo->parametroSig = raiz;
        raiz->parametroAnt = nuevo;
        raiz = nuevo;
    }
    cantidad++;
}

void ListaDoblementeEnlazada::imprimir()
{
    Parametro *reco = raiz;
    while (reco != nullptr)
    {
        cout << reco->valor <<endl;
        reco = reco->parametroSig;
    }
    cout << "\n";
}




string ListaDoblementeEnlazada::obtenerValorEnPosicion(int posicion) {
    Parametro *reco = raiz;
    if (posicion > cantidad){
        return "";
    }
    for (int i = posicion; reco != nullptr && posicion < cantidad-1; i++) {
        reco = reco->parametroSig;
        cout<<"Valor del pametro en posicion "<<i << " "<< reco->valor<<endl;
    }
    if (reco != nullptr) {
        return reco->valor;
    } else {
        return "";
    }
}