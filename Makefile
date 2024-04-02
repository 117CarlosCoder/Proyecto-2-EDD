# Variables
CPP = g++
TARGET = Poyecto_2

# Regla para compilar todo
all: $(TARGET)

# Regla para enlazar los objetos y crear el ejecutable
$(TARGET): main.o ListaDoblementeEnlazada.o Comandos.o Hash.o Arbol.o NodoArbol.o NodoGrupo.o NodoParametro.o Parametro.o
	$(CPP) main.o ListaDoblementeEnlazada.o Comandos.o Hash.o Arbol.o NodoArbol.o NodoGrupo.o NodoParametro.o Parametro.o -o $(TARGET)

# Reglas para compilar los archivos fuente
main.o: main.cpp
	$(CPP) -c main.cpp

ListaDoblementeEnlazada.o: ListaDoblementeEnlazada/ListaDoblementeEnlazada.cpp ListaDoblementeEnlazada/ListaDoblementeEnlazada.h
	$(CPP) -c ListaDoblementeEnlazada/ListaDoblementeEnlazada.cpp

Comandos.o: Comandos/Comandos.cpp Comandos/Comandos.h
	$(CPP) -c Comandos/Comandos.cpp

Hash.o: Hash/Hash.cpp Hash/Hash.h
	$(CPP) -c Hash/Hash.cpp

Arbol.o: Arbol/Arbol.cpp Arbol/Arbol.h
	$(CPP) -c Arbol/Arbol.cpp

NodoArbol.o: Nodos/NodoArbol.cpp Nodos/NodoArbol.h
	$(CPP) -c Nodos/NodoArbol.cpp

NodoGrupo.o: Nodos/NodoGrupo.cpp Nodos/NodoGrupo.h
	$(CPP) -c Nodos/NodoGrupo.cpp

NodoParametro.o: Nodos/NodoParametro.cpp Nodos/NodoParametro.h
	$(CPP) -c Nodos/NodoParametro.cpp

Parametro.o: Parametro/Parametro.cpp Parametro/Parametro.h
	$(CPP) -c Parametro/Parametro.cpp

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	rm -f *.o $(TARGET)
