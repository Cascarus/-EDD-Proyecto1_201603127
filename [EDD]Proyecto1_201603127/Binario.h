#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string> 
#include "Nodo_Matriz.h"
#include "Nodo_ABB.h"

class Binario
{
public:

	Binario(bool a) {
		raiz = NULL;
		principal = NULL;
	}
	Nodo_ABB *raiz;
	Nodo_Matriz *principal;
	string grafica = "";
	bool existeB(Nodo_ABB *raiz, int dato);
	bool existe(int dato);
	Nodo_ABB *insertar(Nodo_ABB *raiz, int dato);
	void add(int dato);
	Nodo_ABB *eliminar(Nodo_ABB *raiz, int dato);
	void elim(int dato);
	Nodo_ABB *buscarNodo(Nodo_ABB *raiz, int dato);
	Nodo_ABB *busNodo(int dato);
	Nodo_ABB *ModNodo(Nodo_ABB *raiz, int dato, Nodo_ABB *matriz);
	void modificar(int dato, Nodo_ABB *matriz);
	void graficar();
	string recorrer(Nodo_ABB *raiz);
	string cadena(int n);
};

