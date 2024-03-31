#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Parametro/Parametro.h"
#include "Hash/Hash.h"

using namespace std;// Agregar esta línea para incluir la definición de basic_istringstream

// Función para dividir una cadena en partes utilizando un delimitador
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void buscar(string input){
    cout << "Ingrese la búsqueda de contacto: ";
    getline(cin, input);

    // Dividir la cadena en partes utilizando el delimitador '='
    vector<string> parts = split(input, '=');

    // Verificar si se dividió en dos partes
    if(parts.size() == 2) {
        string campo = parts[0];
        string dato = parts[1];

        // Mostrar el resultado
        cout << "Campo: " << campo << endl;
        cout << "Dato que busca: " << dato << endl;
    } else {
        cout << "Entrada no válida. Por favor, ingrese en el formato correcto." << endl;
    }
}

int main() {
    /*
    std::string input;

    // Leer la entrada del usuario
    std::cout << "Ingrese el comando para agregar contacto: ";
    std::getline(std::cin, input);

    // Dividir la cadena en partes utilizando el delimitador ' '
    std::vector<std::string> parts = split(input, ' ');
    cout<<parts[0]<<endl;
    cout<<parts[1]<<endl;
    cout<<parts[2]<<endl;
    cout<<parts[3]<<endl;
    cout<<parts[4]<<endl;
    cout<<parts[5]<<endl;
    cout<<parts[6]<<endl;

    // Verificar si se dividió en partes adecuadas
    if( parts[0] == "ADD" && parts[1] == "CONTACT" && parts[2] == "IN" && parts[3] == "amigos" && parts[4] == "FIELDS"   && parts.back().back() == ';') {
        std::string grupo = parts[3];
        std::vector<std::string> campos;

        // Recorrer las partes para obtener los campos
        for(size_t i = 5; i < parts.size() - 1; ++i) {
            // Eliminar ',' al final de cada parte si es necesario
            std::string campo = (parts[i].back() == ',') ? parts[i].substr(0, parts[i].size() - 1) : parts[i];
            campos.push_back(campo);
        }

        // Mostrar el resultado
        std::cout << "Grupo: " << grupo << std::endl;
        std::cout << "Campos: ";
        for(const auto& campo : campos) {
            std::cout << campo << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Comando no válido. Por favor, ingrese en el formato correcto." << std::endl;
    }
*/
    Parametro *para1;
    Parametro *para2;
    Parametro *para3;
    para1 = new Parametro();
    para2 = new Parametro();
    para3 = new Parametro();
    para1->tipo = "STRING";
    para1->valor = "nombre";
    para1->grupo = new NodoGrupo();

    Arbol *arbol;
    NodoGrupo *nodoGrupo;
    NodoParametro *nodoParametro;
    Hash *hashGroup;
    Hash *hashParametro;

    arbol = new Arbol();
    nodoParametro = new NodoParametro();
    hashGroup = new Hash();
    hashParametro = new Hash();
    nodoGrupo = new NodoGrupo();
    nodoParametro->valor = new Arbol();
    nodoParametro->parametro = para1->valor;
    nodoParametro->tipo = para1->tipo;
    nodoGrupo->grupo = "clientes";
    nodoGrupo->sig = new NodoParametro();
    nodoGrupo->sig = nodoParametro;
    para1->grupo = nodoGrupo;
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
    nodoParametro->valor->imprimir();
    return 0;
}
