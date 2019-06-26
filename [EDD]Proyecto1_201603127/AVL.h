#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string> 
#include "Lista_Doble_Circular.h"

using namespace std;


class Nodo_Arbol {
private:
	string cadena(int n) {
		stringstream flujo;
		flujo << n;
		return(flujo.str());
	}
	int contador;
	string concat;

public:
	Nodo_Arbol() {
		for (int a = 0; a < 7; a++) {
			contador = rand() % 9;
			concat += cadena(contador);
		}
		std::string::size_type sz;
		hash = stol(concat, &sz);
		derecha =	NULL;
		izquierda = NULL;
		primero = NULL;
		ultimo = NULL;
	}

	int id, altura;
	int hash;
	string nick;
	string contrasenia;
	Nodo_Arbol *derecha;
	Nodo_Arbol *izquierda;
	Nodo_c *primero;
	Nodo_c *ultimo;
};

class AVL
{
private:
	int altura(Nodo_Arbol *N);
	int maxi(int a, int b);
	Nodo_Arbol* newNode(string key);
	Nodo_Arbol *RotarDer(Nodo_Arbol *y);
	Nodo_Arbol *RotarIzq(Nodo_Arbol *x);
	int getBalance(Nodo_Arbol *N);

public:
	Nodo_Arbol *raiz;
	string grafica;
	AVL(bool cosa);
	Nodo_Arbol *insertar(Nodo_Arbol *N, string nick);
	void agregar(string nombre);
	Nodo_Arbol *mini(Nodo_Arbol *nodo);
	Nodo_Arbol *eliminar(Nodo_Arbol *raiz, string usuario);
	void my_delete(string usuario);
	void AVL::update(string nombre, Nodo_c *actual);
	void actualizar(Nodo_Arbol *current, string nick, Nodo_c *actual);
	Nodo_Arbol *buscarNodo(string usuario);
	Nodo_Arbol *buscarNod(Nodo_Arbol *raiz, string usuario);
	void graficar();
	void recorrer(Nodo_Arbol *inicio);
	string cadena(int n);
	bool existe(string usuario);
	
};

