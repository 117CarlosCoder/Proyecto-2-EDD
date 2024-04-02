//
// Created by carlos on 30/03/24.
//

#ifndef POYECTO_2_ARBOL_H
#define POYECTO_2_ARBOL_H
#include <string>
#include "../Nodos/NodoArbol.h"
#include "../ListaDoblementeEnlazada/ListaDoblementeEnlazada.h"

using namespace std;
class NodoGrupo;
class NodoArbol;
class Parametro;
class Arbol {
private:
    int existenodo;
    NodoArbol *anterior, *raiz, *recorrern, *PadreABn, *sHijo, *abuelo, *hijoHijo, *nuevon;
    int convertirAscii(string valor);
    Parametro* buscarDato(NodoArbol *recorrer, string buscado, int nuevP);
    void insertarNuevo(NodoArbol *recorrer, NodoArbol *nuevo, NodoArbol *PadreAB);
    void verArbol(NodoArbol *recorrer, int n);
    int altura(NodoArbol *recorrer);
    void rotarID();
    void rotarDI();
    void rotarDD();
    void rotarII();
    void necesidadEquilibrar(NodoArbol *recorrer);
public:
    Arbol();
    void ingresar( string nuevoDato, NodoGrupo *grupo, string tipo);
    Parametro* buscar(string valor, int nuevP);
    void imprimir();
    void graficar();
    void graficarArbol(NodoArbol *recorrer, int n, ofstream &file);
};


#endif //POYECTO_2_ARBOL_H
