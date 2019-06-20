#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

struct Nodo_Lista
{
	Nodo_Lista() {
		dato = NULL;
		siguiente = NULL;
	}

	int dato;
	Nodo_Lista *siguiente;
};

class Lista_Simple
{
public:

	Nodo_Lista *primero;
	Nodo_Lista *ultimo;
	Lista_Simple(bool a) {
		primero = NULL;
		ultimo = NULL;
	}

	void agregar(int dato);
	void eliminar(int dato);
	void graficar();
	string recorrer(Nodo_Lista *primero);
	string cadena(int a);
	
};

