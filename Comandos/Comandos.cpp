//
// Created by carlosl on 1/04/24.
//

#include "Comandos.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "../Parametro/Parametro.h"
#include "../Hash/Hash.h"

using namespace std;

Comandos::Comandos() {
    parametroN = *new Parametro();
    parametroN.grupo = new NodoGrupo();

    nodoParametro = new NodoParametro();
    nodoParametro->valor = new Arbol();
    nodoGrupo = new NodoGrupo();
    nodoGrupo->parametros = new ListaDoblementeEnlazada();
    nodoGrupo->listaDoblementeEnlazada = new ListaDoblementeEnlazada();

    nodoParametroNuev = *new NodoParametro();
    nodoParametroNuev.valor = new Arbol();
    nodoGrupoNuev = *new NodoGrupo();
    nodoGrupoNuev.parametros = new ListaDoblementeEnlazada();
    nodoGrupoNuev.listaDoblementeEnlazada = new ListaDoblementeEnlazada();
}

void Comandos::ejecutar(string comando,Hash *hashGroup, Hash *hashParametro){
    string valornuevo;

    istringstream iss(comando);
    vector<std::string> tokens;
    string token;
    bool isNewGroup = false;
    bool isInGroup = false;
    bool isFind = false;
    bool isFindN = false;
    bool isContact = false;
    bool isAdd = false;
    bool isAddP = false;
    bool isAddNew = false;
    bool isAddNewType = false;
    bool isgraph = false;
    bool isequals = false;



    while (iss >> token) {
        tokens.push_back(token);
    }

    int numparam = 0;

    for (const std::string& token : tokens) {
        std::string cleanedToken = token;
        cleanedToken.erase(std::remove_if(cleanedToken.begin(), cleanedToken.end(), [](char c) { return c == '(' || c == ')' || c == ','  || c == ';'; }), cleanedToken.end());

        if (cleanedToken == "ADD" || cleanedToken == "NEW-GROUP" || cleanedToken == "FIELDS" || cleanedToken == "CONTACT" || cleanedToken == "IN" || cleanedToken == "FIND" || cleanedToken == "GRAPH" || cleanedToken == "CONTACT-FIELD" || cleanedToken == "=") {
            std::cout << "Operación: " << cleanedToken << std::endl;
            if (cleanedToken == "NEW-GROUP") {
                isNewGroup = true;
            }
            if (cleanedToken == "CONTACT") {
                isAdd = true;
            }
            if (cleanedToken == "FIND") {
                isFind = true;
            }
            if (cleanedToken == "IN") {
                isInGroup = true;
            }
            if (cleanedToken == "GRAPH") {
                isgraph = true;
            }
            if (cleanedToken == "CONTACT-FIELD") {
                isContact = true;
            }
            if (cleanedToken == "=") {
                isequals = true;
            }


        }
        else if (isgraph) {
            std::cout << "Nombre del grupo: " << cleanedToken << std::endl;
            nodoGrupo =  hashGroup->buscarGrupo(cleanedToken);
            if (nodoGrupo->parametros->cantidad != 0){
                for (int i = 0; i < nodoGrupo->parametros->cantidad; ++i) {
                    nodoParametro = hashParametro->buscarParametro(nodoGrupo->parametros->obtenerValorEnPosicion(i));
                    nodoParametro->valor->graficar();
                }
            }
            isgraph = false;
        }
        else if (isFind) {
            std::cout << "Nombre del grupo: " << cleanedToken << std::endl;
            if (nodoGrupo != nullptr){
                nodoGrupo =  hashGroup->buscarGrupo(cleanedToken);
                isFind = false;
                isFindN = true;
            }

        }
        else if (isFindN && isContact) {
            std::cout << "Buscar Parametro " << cleanedToken << std::endl;

            if (nodoGrupo != nullptr){
                nodoParametro = hashParametro->buscarParametro(cleanedToken);
                isContact = false;
                isFindN = false;
            }

        }

        else if (isequals) {
            std::cout << "Buscar Valor " << cleanedToken << std::endl;

            if (nodoParametro != nullptr){
                nodoParametro->valor->buscar(cleanedToken, nodoGrupo->parametros->cantidad);
            }

        }
        else if (isNewGroup) {
            std::cout << "Nombre del grupo: " << cleanedToken << std::endl;

            nodoGrupo = new NodoGrupo();

            nodoGrupo->grupo = cleanedToken;
            nodoGrupo->parametros = new ListaDoblementeEnlazada();
            nodoGrupo->listaDoblementeEnlazada = new ListaDoblementeEnlazada();

            hashGroup->ingresarGrupo(nodoGrupo);
            hashGroup->imprimirGrupo();
            isNewGroup = false;
        }
        else if (isAdd && isInGroup) {
            cout << "Nombre del grupo: " << cleanedToken << endl;
            cout << "buscando grupo: " << cleanedToken << endl;
            valornuevo = cleanedToken;
            if(hashGroup->buscarGrupo(cleanedToken)){

                nodoGrupo =  hashGroup->buscarGrupo(cleanedToken);
                cout << "Grupo: " << nodoGrupo->grupo << endl;
                isAddP = true;
            }
            isNewGroup = false;
            isInGroup = false;
            isAdd = false;
        }
        else if (isAddP) {

            cout << "Agregar Valor: " << cleanedToken << endl;
            //cout << "Numero param: " << numparam << endl;
            if (numparam < nodoGrupo->parametros->cantidad){
                hashParametro->imprimirParametro();
                nodoParametro = hashParametro->buscarParametro(nodoGrupo->parametros->obtenerValorEnPosicion(numparam));
                nodoParametro->valor->ingresar(cleanedToken, nodoGrupo,nodoParametro->tipo);
            }
            if (numparam == nodoGrupoNuev.parametros->cantidad){
                numparam = 0;
            }
            isAddP = false;
            isAddNew = true;
            numparam++;

        }
        else if (cleanedToken == "GROUP" || cleanedToken == "CONTACT-FIELD") {
            std::cout << "Tipo: " << cleanedToken << std::endl;
        }
        else if (cleanedToken == "STRING" || cleanedToken == "INTEGER" || cleanedToken == "CHAR" || cleanedToken == "DATE" ) {

            parametroN.tipo = cleanedToken;
           // cout<<"Valor "<< parametroN.valor<<endl;
           // cout<<"Tipo "<< parametroN.tipo<<endl;
            if (hashParametro->buscarParametro(cleanedToken)){
                hashGroup->imprimirGrupo();
            }else{
                nodoParametro = new NodoParametro();
                nodoParametro->valor = new Arbol();
                parametroN.grupo = nodoGrupo;
                nodoParametro->parametro = parametroN.valor;
                nodoParametro->tipo = parametroN.tipo;

                hashParametro->ingresarParametro(nodoParametro);
                nodoGrupo->parametros->ingresar(&parametroN);
                hashParametro->imprimirParametro();
                hashGroup->imprimirGrupo();
                //nodoGrupo->parametros->imprimir();
                //nodoGrupo->listaDoblementeEnlazada->imprimir();
            }


        }
        else if (!cleanedToken.empty()) {
            std::cout << "Dato: " << cleanedToken << std::endl;
            if (isAddNew) {
                std::cout << "Guardando tipo: " << nodoParametro->tipo << std::endl;
                std::cout << "Ingresando dato: " << cleanedToken << std::endl;
                nodoParametro->valor->ingresar(cleanedToken,nodoGrupo,nodoParametro->tipo);
                cout<<"Valores del arbol "<<nodoParametro->parametro<<endl;
                //nodoParametro->valor->imprimir();
            }
            else{
                parametroN.valor = cleanedToken;
            }

        }
    }

}



