#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string> 
#include "Matriz.h"

class Nodo_ABB {

public:
	Nodo_ABB() {
		derecha = NULL;
		izquierda = NULL;
	}

	int id;
	Nodo_ABB *derecha;
	Nodo_ABB *izquierda;
	Nodo_Matriz *principal;
	Nodo_Matriz *filas;
	Nodo_Matriz *columnas;
};


class Binario
{
public:

	Binario(bool a) {
		raiz = NULL;
	}
	Nodo_ABB *raiz;
	string grafica = "";

	Nodo_ABB *insertar(Nodo_ABB *raiz, int dato);
	void add(int dato);
	Nodo_ABB *eliminar(Nodo_ABB *raiz, int dato);
	void elim(int dato);
	void graficar();
	string recorrer(Nodo_ABB *raiz);
	string cadena(int n);
};

