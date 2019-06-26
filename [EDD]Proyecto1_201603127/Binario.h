#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string> 
#include "Matriz.h"
#include "Nodo_ABB.h"

class Binario
{
private:
	string grafica = "";

public:

	Binario(bool a) {
		raiz = NULL;
		principal = NULL;
		no_Nodos = 0;
	}
	Nodo_ABB *raiz;
	Nodo_ABB *raiz_Espejo;
	Nodo_Matriz *principal;
	string preOrd = "";
	string inOrd = "";
	string posOrd = "";
	int no_Nodos;

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
	void Espejo(Nodo_ABB *raiz_E);
	void graficar();
	void graficar_Espejo();
	string recorrer(Nodo_ABB *raiz);
	void crear_IMG(Nodo_ABB *inicio);
	void splitear_Capas(string str, Matriz imagen_completa, int id);
	void PreOrden(Nodo_ABB *raiz);
	void InOrden(Nodo_ABB *raiz);
	void PostOrden(Nodo_ABB *raiz);
	string cadena(int n);
};

