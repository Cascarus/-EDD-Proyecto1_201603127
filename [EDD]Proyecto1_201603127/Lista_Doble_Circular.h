#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string> 

using namespace std;

class Nodo_c
{
public:
	Nodo_c() {
		Siguiente = NULL;
		Anterior = NULL;
	}
	int id;
	Nodo_c *Siguiente;
	Nodo_c *Anterior;
	//Nodo_List *primero;


};


class Lista_Doble_Circular
{
public:
	Nodo_c *primero;
	Nodo_c *ultimo;
	string labels = "", relaciones = "";

	Lista_Doble_Circular(bool a) {
		ultimo = NULL;
		primero = NULL;
	}

	void insertarNuevo(int dato);
	void mostrar();
	Nodo_c *buscarNodo(int dato);
	void ModNodo(int dato, Nodo_c *matri);
	void eliminar(int x);
	void recorrer(Nodo_c *primero);
	void graf();
	string cadena(int n);
};

