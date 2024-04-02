#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Parametro/Parametro.h"
#include "Hash/Hash.h"
#include "Comandos/Comandos.h"

using namespace std;

int main() {

    Hash *hashGroup = new Hash();
    Hash *hashParametro = new Hash();
    Comandos *comandos = new Comandos();

    /*Parametro *para1;
    Parametro *para2;
    para1 = new Parametro();
    para2 = new Parametro();
    para2->tipo = "STRING";
    para2->valor = "apellido";
    para2->grupo = new NodoGrupo();
    para1->tipo = "STRING";
    para1->valor = "nombre";
    para1->grupo = new NodoGrupo();

    NodoGrupo *nodoGrupo;
    NodoParametro *nodoParametro;
    NodoParametro *nodoParametro2;

    nodoGrupo = new NodoGrupo();
    nodoParametro = new NodoParametro();
    nodoParametro2 = new NodoParametro();

    nodoParametro->valor = new Arbol();
    nodoParametro->parametro = para1->valor;
    nodoParametro->tipo = para1->tipo;

    nodoParametro2->valor = new Arbol();
    nodoParametro2->parametro = para2->valor;
    nodoParametro2->tipo = para2->tipo;

    nodoGrupo->grupo = "clientes";
    nodoGrupo->listaDoblementeEnlazada = new ListaDoblementeEnlazada();
    nodoGrupo->parametros = new ListaDoblementeEnlazada();
    nodoGrupo->parametros->ingresar(para1);
    nodoGrupo->parametros->ingresar(para2);

    para1->grupo = nodoGrupo;
    para2->grupo = nodoGrupo;

    hashGroup->ingresarGrupo(nodoGrupo);
    hashParametro->ingresarParametro(nodoParametro);
    hashGroup->imprimirGrupo();
    hashParametro->imprimirParametro();

    nodoParametro->valor->ingresar("Carlos",nodoGrupo,"STRING");
    nodoParametro->valor->ingresar("Carla",nodoGrupo,"STRING");
    nodoParametro->valor->ingresar("Maria",nodoGrupo,"STRING");
    nodoParametro->valor->ingresar("Carmelo",nodoGrupo,"STRING");
    nodoParametro->valor->ingresar("Candas",nodoGrupo,"STRING");
    nodoParametro->valor->ingresar("Car",nodoGrupo,"STRING");

    nodoParametro2->valor->ingresar("perez",nodoGrupo,"STRING");
    nodoParametro2->valor->ingresar("marquez",nodoGrupo,"STRING");
    nodoParametro2->valor->ingresar("mendez",nodoGrupo,"STRING");
    nodoParametro2->valor->ingresar("morales",nodoGrupo,"STRING");
    nodoParametro2->valor->ingresar("martinez",nodoGrupo,"STRING");
    nodoParametro2->valor->ingresar("lopez",nodoGrupo,"STRING");


    nodoParametro->valor->imprimir();
    nodoParametro2->valor->imprimir();
    nodoParametro->valor->graficar();

    hashParametro->buscarParametro("nombre")->valor->buscar("Carlos",nodoGrupo->parametros->cantidad);
    nodoGrupo->listaDoblementeEnlazada->imprimir();*/

    std::string comando;
    std::cout << "Ingrese un comando (o escriba 'fin' para salir):\n";
    while (std::getline(std::cin, comando)) {
        if (comando == "fin") {
            break;
        }
        comandos->ejecutar(comando, hashGroup, hashParametro);
        std::cout << "\nIngrese otro comando (o escriba 'fin' para salir):\n";
    }

    delete hashGroup;
    delete hashParametro;
    delete comandos;


    return 0;
}
