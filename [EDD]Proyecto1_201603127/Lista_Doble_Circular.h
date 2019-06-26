#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string> 
#include "Lista_Simple.h"
#include "Binario.h"
#include "Matriz.h"

using namespace std;

class Nodo_c
{
public:
	Nodo_c() {
		Siguiente = NULL;
		Anterior = NULL;
		primero_lista = NULL;
		colMax = 0;
		filMax = 0;
	}
	int id;
	Nodo_c *Siguiente;
	Nodo_c *Anterior;
	Nodo_Lista *primero_lista;
	int colMax, filMax;

};


class Lista_Doble_Circular
{
private:
	void splitear_Capas(string str, Matriz imagen_completa, int id);

public:
	Nodo_c *primero;
	Nodo_c *ultimo;
	string labels = "", relaciones = "", listas = "", ranks = "";

	Lista_Doble_Circular(bool a) {
		ultimo = NULL;
		primero = NULL;
	}

	void insertarNuevo(int dato, Nodo_Lista *&lista);
	void mostrar();
	Nodo_c *buscarNodo(int dato);
	void ModNodo(int dato, Nodo_c *matri);
	void eliminar(int x);
	void recorrer(Nodo_c *primero);
	void graf();
	void crear_IMG(Nodo_c *nodo);
	void crear_IMG2(Nodo_c *nodo, Nodo_ABB *raiz);
	string cadena(int n);
	string recorrer2(Nodo_c *&primero,string c);

};

