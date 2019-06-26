#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Nodo_ABB.h"


using namespace std;

struct Nodo_Lista
{
	Nodo_Lista() {
		dato = NULL;
		siguiente = NULL;
		capa = NULL;
	}

	int dato;
	Nodo_Lista *siguiente;
	Nodo_ABB *capa;
};

class Lista_Simple
{
public:
	int filaMax, colMax;

	Nodo_Lista *primero;
	Nodo_Lista *ultimo;
	Lista_Simple(bool a) {
		primero = NULL;
		ultimo = NULL;
		filaMax = 0;
		colMax = 0;
	}

	Lista_Simple(Nodo_Lista *cabeza) {
		primero = cabeza;
		ultimo = NULL;
		filaMax = 0;
		colMax = 0;
	}

	void agregar(int dato, Nodo_ABB *&capa);
	void eliminar(int dato);
	void graficar();
	string recorrer(Nodo_Lista *primero);
	string recorrer2(int no,Nodo_Lista *primero);
	string recorrer3(int no, Nodo_Lista *primero);
	string cadena(int a);
	void buscar_dim_mayores(Nodo_ABB *&capa);
	
};

