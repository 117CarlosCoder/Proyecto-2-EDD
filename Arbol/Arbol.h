//
// Created by carlos on 30/03/24.
//

#ifndef POYECTO_2_ARBOL_H
#define POYECTO_2_ARBOL_H
#include <string>
#include "../Nodos/NodoArbol.h"
using namespace std;
class NodoGrupo;
class NodoArbol;
class Arbol {
private:
    int existenodo;
public:
    NodoArbol *anterior, *raiz, *recorrern, *PadreABn, *sHijo, *abuelo, *hijoHijo, *nuevon;
    Arbol();
    int convertirAscii(string valor);
    void buscarDato(NodoArbol *recorrer, string buscado);
    void insertarNuevo(NodoArbol *recorrer, NodoArbol *nuevo, NodoArbol *PadreAB);
    void verArbol(NodoArbol *recorrer, int n);
    int altura(NodoArbol *recorrer);
    void rotarID();
    void rotarDI();
    void rotarDD();
    void rotarII();
    void necesidadEquilibrar(NodoArbol *recorrer);
    void ingresar( string nuevoDato, NodoGrupo *grupo, string tipo);
    void buscar(string valor);
    void imprimir();
};


#endif //POYECTO_2_ARBOL_H
