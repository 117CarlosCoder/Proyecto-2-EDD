//
// Created by carlos on 25/03/24.
//

#include "Arbol.h"
#include <string>
#include <iostream>
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

void Arbol::buscar(string valor) {
    recorrern = raiz;
    buscarDato(recorrern,std::move(valor));
}


//Si es 0 no existe, y si es 1 si existe.
void Arbol::buscarDato(NodoArbol *recorrer, string buscado){
    existenodo=0;
    int valosBuscado  = convertirAscii(buscado);
    cout<<"Ascii buscado "<<valosBuscado<<endl;
    cout<<"Ascii actual "<<recorrer->valor->valorAscii<<endl;
    if (recorrer==nullptr){
        cout<<"Arbol Vacio o el nodo no existe"<<endl;
    }else{
        if(valosBuscado < recorrer->valor->valorAscii){
            cout<<"buscando ...."<<endl;
            buscarDato(recorrer->izq, buscado);
        }else if (valosBuscado>recorrer->valor->valorAscii){
            cout<<"buscando ...."<<endl;
            buscarDato(recorrer->der, buscado);

        }else if (valosBuscado == recorrer->valor->valorAscii){
            existenodo=1;
            PadreABn=recorrer->padre;
            //ABBcout<<"Padre: "<<PadreAB->dato<<" Nodo buscado: "<<recorrer->dato<<endl;
            cout<<"El nodo SI existe"<<endl;
            cout<<"Palabra: "<<recorrer->valor->valor<<endl;
            cout<<"AScii: "<<recorrer->valor->valorAscii<<endl;
            cout<<endl;
        }
    }
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
    nuevon = nuevonn;
    recorrern = raiz;
    PadreABn = raiz;

    insertarNuevo(recorrern, nuevon, PadreABn);
    altura(recorrern);
    necesidadEquilibrar(recorrern);


}

void Arbol::insertarNuevo(NodoArbol *recorrer, NodoArbol *nuevo, NodoArbol *PadreAB){
    if (raiz== nullptr){ //Si es el primer nodo entonces la raíz aún será nula porque no existe nada dentro de ella.
        raiz=nuevo; //Asignar a la raíz el valor del nuevo nodo creado...
        raiz->padre=nullptr;
        cout<<"Arbol vacio "<<raiz->valor->valor<<endl;

    }else{
        anterior = recorrer;
        /*
        if (anterior->valor.grupo == nuevo->valor.grupo) {
            anterior->valor.parametroSig = &nuevo->valor;
        }*/
        cout<<"Nuevo "<<nuevo->valor->valorAscii<<endl;
        //cout<<"Anterior "<<recorrer->valor->valorAscii<<endl;
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

//Rotación Derecha Izquierda
void Arbol::rotarDI(){
    if (PadreABn==raiz){

        hijoHijo=sHijo->izq; //Ubico al hijo del hijo...

        raiz=hijoHijo; //Cambiar el apuntador de la raíz.

        hijoHijo->padre=nullptr; //Aseguro que el padre de la raíz se quede en nullptr

        hijoHijo->der=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.
        sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.
        if(sHijo->izq!=nullptr){
            sHijo->izq=hijoHijo->izq;
        }else{
            sHijo->izq=nullptr; //Apuntar a nullptr la parte izquierda del hijo, ya que ahora no tendrá hijos...
        }

        //sHijo->dere=nullptr; // Apuntar a nullptr la parte derecha del hijo, ya que ahora no tendrá Hijos...

        hijoHijo->izq=PadreABn; //El nuevo padre debe apuntar al hijo derecho.

        if(PadreABn->izq==nullptr){
            PadreABn->izq=nullptr; //El antiguo padre debe apuntar ahora a nu
        }

        PadreABn->der=nullptr; //el antiguo padre debe apuntar ahora a nullptr
        PadreABn->padre=hijoHijo; //Apuntar al nuevo padre ...
    }else{

        abuelo=PadreABn->padre;

        hijoHijo=sHijo->izq; //Ubico al hijo del hijo...

        hijoHijo->padre=abuelo; //Aseguro que el padre de la raíz se quede apuntando al abuelo

        hijoHijo->der=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.
        sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.

        if(sHijo->izq!=nullptr){
            sHijo->izq=hijoHijo->izq;
        }else{
            sHijo->izq=nullptr; //Apuntar a nullptr la parte izquierda del hijo, ya que ahora no tendrá hijos...
        }

        //sHijo->dere=nullptr; // Apuntar a nullptr la parte derecha del hijo, ya que ahora no tendrá Hijos...

        hijoHijo->izq=PadreABn; //El nuevo padre debe apuntar al hijo derecho.

        if(PadreABn->izq==nullptr){
            PadreABn->izq=nullptr; //El antiguo padre debe apuntar ahora a nu
        }

        PadreABn->der=nullptr; //el antiguo padre debe apuntar ahora a nullptr
        PadreABn->padre=hijoHijo; //Apuntar al nuevo padre ...

        abuelo->der=hijoHijo;
    }
}


//Rotación  Izquierda Derecha
void Arbol::rotarID(){
    if (PadreABn==raiz){

        hijoHijo=sHijo->der; //Ubico al hijo del hijo...

        raiz=hijoHijo; //Cambiar el apuntador de la raíz.

        hijoHijo->padre=nullptr; //Aseguro que el padre de la raíz se quede en nullptr

        hijoHijo->izq=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.
        sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.

        sHijo->der=nullptr; //Apuntar a nullptr la parte izquierda del hijo, ya que ahora no tendrá hijos...

        PadreABn->izq=nullptr; //El antiguo padre debe apuntar ahora a nullptr

        hijoHijo->der=PadreABn; //El nuevo padre debe apuntar al hijo derecho.


        if(PadreABn->der==nullptr){
            PadreABn->der=nullptr; //El antiguo padre debe apuntar ahora a nu
        }
        PadreABn->padre=hijoHijo; //Apuntar al nuevo padre ...
    }else{

        abuelo=PadreABn->padre;

        hijoHijo=sHijo->der; //Ubico al hijo del hijo...

        hijoHijo->padre=abuelo; //Aseguro que el padre de la raíz se quede apuntando al abuelo
        abuelo->izq=hijoHijo;

        hijoHijo->izq=sHijo; // el nuevo padre debe apuntar al hijo izquierdo.
        sHijo->padre=hijoHijo; //El hijo debe apuntar a su nuevo padre.

        sHijo->der=nullptr; //Apuntar a nullptr la parte izquierda del hijo, ya que ahora no tendrá hijos...


        hijoHijo->der=PadreABn; //El nuevo padre debe apuntar al hijo derecho.

        PadreABn->izq=nullptr; //El antiguo padre debe apuntar ahora a nullptr

        if(PadreABn->der==nullptr){
            PadreABn->der=nullptr; //El antiguo padre debe apuntar ahora a nu
        }
        PadreABn->padre=hijoHijo; //Apuntar al nuevo padre ...
    }
}

//Rotación  Derecha Derecha
void Arbol::rotarDD(){
    if (PadreABn==raiz){
        raiz=sHijo;

        //sHijo->dere=hijoHijo;
        //hijoHijo->padre=sHijo;
        //hijoHijo->dere=nullptr;

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


//Rotación  Izquierda Izquierda
void Arbol::rotarII(){
    if(PadreABn==raiz){
        raiz=sHijo;

        hijoHijo=sHijo->izq;

        sHijo->der=PadreABn;
        PadreABn->izq=nullptr;
        PadreABn->padre=sHijo;

        sHijo->padre=nullptr;

        //PadreAB->dere=hijoHijo;
        //hijoHijo->padre=PadreAB;

        //sHijo->dere=PadreAB;


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

            //Identificar Si es el caso  RDD, Rotación Derecha, Derecha.
            if ((PadreABn->fe>1)&&(sHijo->fe>0)){
                cout<<"Rotacion derecha derecha."<<endl;
                cout<<" Padre: "<<PadreABn->valor->valor<<" Hijo: "<<sHijo->valor->valor<<endl;
                rotarDD();
                altura(raiz);
                return;
                //Identificar Si es el caso  RDI, Rotación Derecha, Izquierda.
            }else if((PadreABn->fe>1)&&(sHijo->fe<0)){
                cout<<"Rotacion derecha izquierda."<<endl;
                cout<<" Padre: "<<PadreABn->valor->valor<<" Hijo: "<<sHijo->valor->valor<<endl;
                rotarDI();
                altura(raiz);
                return;
            }else{

                PadreABn=recorrer;
                sHijo=PadreABn->izq;

                //Identificar Si es el caso  RII, Rotación Izquierda, Izquierda.
                if((PadreABn->fe<-1)&&(sHijo->fe<0)){
                    cout<<"Rotacion izquierda izquierda."<<endl;
                    cout<<" Padre: "<<PadreABn->valor->valor<<" Hijo: "<<sHijo->valor->valor<<endl;
                    rotarII();
                    altura(raiz);
                    return;
                    //Identificar Si es el caso  RID, Rotación Izquierda, Derecha.
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

