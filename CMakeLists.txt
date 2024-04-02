cmake_minimum_required(VERSION 3.27)
project(Poyecto_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp
        Parametro/Parametro.cpp
        Parametro/Parametro.h
        Nodos/NodoGrupo.cpp
        Nodos/NodoGrupo.h
        Nodos/NodoParametro.cpp
        Nodos/NodoParametro.h
        Nodos/NodoArbol.cpp
        Nodos/NodoArbol.h
        Hash/Hash.cpp
        Hash/Hash.h
        Arbol/Arbol.cpp
        Arbol/Arbol.h
        ListaDoblementeEnlazada/ListaDoblementeEnlazada.cpp
        ListaDoblementeEnlazada/ListaDoblementeEnlazada.h
        Comandos/Comandos.h
        Comandos/Comandos.cpp
        main.cpp
)
