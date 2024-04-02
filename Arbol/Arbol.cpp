//
// Created by carlos on 25/03/24.
//

#include "Arbol.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Arbol::Arbol() {
    raiz = nullptr;
    existenodo = 0;
    nuevon = new NodoArbol();
    recorrern = new NodoArbol();
    PadreABn = new NodoArbol();
    sHijo = new NodoArbol();
    abuelo = new NodoArbol();
    hijoHijo = new NodoArbol();
    anterior = new NodoArbol();
}

int Arbol::convertirAscii(string valor) {
    int suma = 0;
    for (int i = 0; i < valor.length(); i++)
    {
        char x = valor.at(i);
        suma = suma + int(x);
    }

    return suma;
}

Parametro* Arbol::buscar(string valor, int cantidadP) {
    recorrern = raiz;
    return buscarDato(recorrern,std::move(valor), cantidadP);
}


Parametro* Arbol::buscarDato(NodoArbol *recorrer, string buscado, int cantidaP){
    existenodo=0;
    int valosBuscado  = convertirAscii(buscado);
    if (recorrer==nullptr){
        cout<<"Arbol Vacio o el nodo no existe"<<endl;
    }else{
        if(valosBuscado < recorrer->valor->valorAscii){
            cout<<"buscando ...."<<endl;
            buscarDato(recorrer->izq, buscado,cantidaP);
        }else if (valosBuscado>recorrer->valor->valorAscii){
            cout<<"buscando ...."<<endl;
            buscarDato(recorrer->der, buscado,cantidaP);

        }else if (valosBuscado == recorrer->valor->valorAscii){
            existenodo=1;
            PadreABn=recorrer->padre;
            //ABBcout<<"Padre: "<<PadreAB->dato<<" Nodo buscado: "<<recorrer->dato<<endl;
            cout<<"El nodo SI existe"<<endl;
            Parametro* pnuev = new Parametro();
            for (int i = 0; i < cantidaP; ++i) {
                pnuev = recorrer->valor;
                cout<<"Valor: "<<pnuev->valor<<endl;
                cout<<"Tipo: "<<pnuev->tipo<<endl;
                cout<<"AScii: "<<pnuev->valorAscii<<endl;
                pnuev = pnuev->parametroSig;
            }
            cout<<endl;
            return recorrer->valor;
        }
    }
    return nullptr;
}



void Arbol::ingresar(string nuevoDato, NodoGrupo *grupo, string tipo) {
    int nuevoAscii = convertirAscii(nuevoDato);


   /*if (raiz == nullptr){
       raiz = new NodoArbol();
    }*/

    auto* nuevonn = new NodoArbol();

    nuevonn->valor = new Parametro();
    nuevonn->valor->grupo = grupo;
    nuevonn->valor->valorAscii = nuevoAscii;
    nuevonn->valor->valor = nuevoDato;
    nuevonn->valor->tipo = tipo;
    nuevonn->izq = nullptr;
    nuevonn->der = nullptr;
    nuevonn->alturaIzq = 0;
    nuevonn->alturaDer = 0;
    nuevonn->fe = nuevonn->alturaIzq - nuevonn->alturaDer;
    //grupo->listaDoblementeEnlazada->ingresar(nuevonn->valor);
    nuevon = nuevonn;
    recorrern = raiz;
    PadreABn = raiz;

    insertarNuevo(recorrern, nuevon, PadreABn);
    altura(recorrern);
    necesidadEquilibrar(recorrern);


}

void Arbol::insertarNuevo(NodoArbol *recorrer, NodoArbol *nuevo, NodoArbol *PadreAB){
    anterior = recorrer;
    if (raiz== nullptr){
        raiz=nuevo;
        raiz->padre=nullptr;
        cout<<"Arbol vacio "<<raiz->valor->valor<<endl;

    }else{

        if(nuevo->valor->valorAscii <= recorrer->valor->valorAscii){
            if(recorrer->izq!=nullptr){
                PadreAB=recorrer->izq;
                cout<<"Padre: "<<PadreAB->valor->valor<<" Nuevo: "<<nuevo->valor->valor<<endl;
                insertarNuevo(recorrer->izq, nuevo, PadreAB);
            }else{
                recorrer->izq=nuevo;
                nuevo->padre=PadreAB;
                cout<<"Por izq"<<endl;
                return;
            }
        }else if (nuevo->valor->valorAscii > recorrer->valor->valorAscii){
            if (recorrer->der!=nullptr){
                PadreAB=recorrer->der;
                cout<<"Padre: "<<PadreAB->valor->valor<<" Nuevo: "<<nuevo->valor->valor<<endl;
                insertarNuevo(recorrer->der, nuevo, PadreAB);
            }else{
                recorrer->der=nuevo;
                nuevo->padre=PadreAB;
                cout<<"Por der"<<endl;
                return;
            }
        }
    }
}

void Arbol::imprimir() {
    recorrern = raiz;

    //cout<<raiz->valor<<endl;
    //cout<<raiz->izq->valor<<endl;
    //cout<<raiz->der->valor<<endl;
    verArbol(recorrern,0);
}

void Arbol::verArbol(NodoArbol *recorrer, int n){
    if(recorrer==nullptr)
        return;
    verArbol(recorrer->der, n+1);

    for(int i=0; i<n; i++)
        cout<<"   ";

    cout<< recorrer->valor->valor <<endl;

    verArbol(recorrer->izq, n+1);
}

void Arbol::graficar(){

    ofstream file("../Graficos/graph.dot");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    file << "digraph G {\n";
    file << "    node [shape=circle, style=filled, fillcolor=lightblue, fontcolor=black];\n";
    graficarArbol(recorrern,0,file);
    file << "}\n";
    file.close();
    string comando = "dot -Tpng ../Graficos/graph.dot -o ../Graficos/" + recorrern->valor->valor + ".png";
    system(comando.c_str());

    cout << "Gráfico generado correctamente." << endl;
}

void Arbol::graficarArbol(NodoArbol *recorrer, int n, ofstream& file){
    if(recorrer == nullptr)
        return;

    file << "    " << recorrer->valor->valor  << " [label=\"" << recorrer->valor->valor  << "\"];\n";

    graficarArbol(recorrer->izq, n + 1, file);

    graficarArbol(recorrer->der, n + 1, file);

    if(recorrer->izq != nullptr)
        file << "    " << recorrer->valor->valor  << " -> " << recorrer->izq->valor->valor << ";\n";
    if(recorrer->der != nullptr)
        file << "    " << recorrer->valor->valor  << " -> " << recorrer->der->valor->valor << ";\n";
}

int Arbol::altura(NodoArbol *recorrer){
    if (recorrer == nullptr)
        return 0 ;
    else{
        recorrer->alturaIzq=altura (recorrer->izq);
        recorrer->alturaDer=altura (recorrer->der);
        recorrer->fe=recorrer->alturaDer-recorrer->alturaIzq;

        if (recorrer->alturaIzq > recorrer->alturaDer)
            return recorrer->alturaIzq + 1;
        else
            return recorrer->alturaDer + 1;
    }
}

void Arbol::rotarDI(){
    if (PadreABn==raiz){

        hijoHijo=sHijo->izq;

        raiz=hijoHijo;

        hijoHijo->padre=nullptr;

        hijoHijo->der=sHijo;
        sHijo->padre=hijoHijo;
        if(sHijo->izq!=nullptr){
            sHijo->izq=hijoHijo->izq;
        }else{
            sHijo->izq=nullptr;
        }



        hijoHijo->izq=PadreABn;

        if(PadreABn->izq==nullptr){
            PadreABn->izq=nullptr;
        }

        PadreABn->der=nullptr;
        PadreABn->padre=hijoHijo;
    }else{

        abuelo=PadreABn->padre;

        hijoHijo=sHijo->izq;

        hijoHijo->padre=abuelo;

        hijoHijo->der=sHijo;
        sHijo->padre=hijoHijo;

        if(sHijo->izq!=nullptr){
            sHijo->izq=hijoHijo->izq;
        }else{
            sHijo->izq=nullptr;
        }


        hijoHijo->izq=PadreABn;

        if(PadreABn->izq==nullptr){
            PadreABn->izq=nullptr;
        }

        PadreABn->der=nullptr;
        PadreABn->padre=hijoHijo;

        abuelo->der=hijoHijo;
    }
}


//Rotación  Izquierda Derecha
void Arbol::rotarID(){
    if (PadreABn==raiz){

        hijoHijo=sHijo->der;

        raiz=hijoHijo;

        hijoHijo->padre=nullptr;

        hijoHijo->izq=sHijo;
        sHijo->padre=hijoHijo;
        sHijo->der=nullptr;

        PadreABn->izq=nullptr;

        hijoHijo->der=PadreABn;


        if(PadreABn->der==nullptr){
            PadreABn->der=nullptr;
        }
        PadreABn->padre=hijoHijo;
    }else{

        abuelo=PadreABn->padre;

        hijoHijo=sHijo->der;

        hijoHijo->padre=abuelo;
        abuelo->izq=hijoHijo;

        hijoHijo->izq=sHijo;
        sHijo->padre=hijoHijo;

        sHijo->der=nullptr;


        hijoHijo->der=PadreABn;

        PadreABn->izq=nullptr;

        if(PadreABn->der==nullptr){
            PadreABn->der=nullptr;
        }
        PadreABn->padre=hijoHijo;
    }
}

void Arbol::rotarDD(){
    if (PadreABn==raiz){
        raiz=sHijo;

        sHijo->izq=PadreABn;
        PadreABn->padre=sHijo;
        PadreABn->der=nullptr;

        sHijo->padre=nullptr;

    }else{
        abuelo=PadreABn->padre;
        abuelo->der=PadreABn->der;
        sHijo->padre=abuelo;
        sHijo->izq=PadreABn;
        PadreABn->padre=sHijo;
        PadreABn->der=nullptr;
    }
}

void Arbol::rotarII(){
    if(PadreABn==raiz){
        raiz=sHijo;

        hijoHijo=sHijo->izq;

        sHijo->der=PadreABn;
        PadreABn->izq=nullptr;
        PadreABn->padre=sHijo;

        sHijo->padre=nullptr;

    }else{
        abuelo=PadreABn->padre;
        abuelo->izq=PadreABn->izq;
        sHijo->padre=abuelo;
        sHijo->der=PadreABn;
        PadreABn->padre=sHijo;
        PadreABn->izq=nullptr;
    }
}


void Arbol::necesidadEquilibrar(NodoArbol *recorrer){
    if (recorrer != nullptr) {

        necesidadEquilibrar(recorrer->izq);
        necesidadEquilibrar(recorrer->der);

        if ((recorrer->fe==2)||(recorrer->fe==-2)){
            cout<<"Es necesario equilibrar el arbol"<<endl;

            PadreABn=recorrer;
            sHijo=PadreABn->der;

            if ((PadreABn->fe>1)&&(sHijo->fe>0)){
                cout<<"Rotacion derecha derecha."<<endl;
                cout<<" Padre: "<<PadreABn->valor->valor<<" Hijo: "<<sHijo->valor->valor<<endl;
                rotarDD();
                altura(raiz);
                return;
            }else if((PadreABn->fe>1)&&(sHijo->fe<0)){
                cout<<"Rotacion derecha izquierda."<<endl;
                cout<<" Padre: "<<PadreABn->valor->valor<<" Hijo: "<<sHijo->valor->valor<<endl;
                rotarDI();
                altura(raiz);
                return;
            }else{

                PadreABn=recorrer;
                sHijo=PadreABn->izq;
                if((PadreABn->fe<-1)&&(sHijo->fe<0)){
                    cout<<"Rotacion izquierda izquierda."<<endl;
                    cout<<" Padre: "<<PadreABn->valor->valor<<" Hijo: "<<sHijo->valor->valor<<endl;
                    rotarII();
                    altura(raiz);
                    return;
                }else if((PadreABn->fe<-1)&&(sHijo->fe>0)){
                    cout<<"Rotacion izquierda Derecha."<<endl;
                    cout<<" Padre: "<<PadreABn->valor->valor<<" Hijo: "<<sHijo->valor->valor<<endl;
                    rotarID();
                    altura(raiz);
                    return;
                }
            }
            return;
        }
    }
}

