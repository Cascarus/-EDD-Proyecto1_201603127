#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string> 

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
		derecha = nullptr;
		izquierda = nullptr;
	}

	int id, altura;
	int hash;
	string nick;
	string contrasenia;
	//Nodo_Lista *inicio;
	Nodo_Arbol *derecha;
	Nodo_Arbol *izquierda;
};

class AVL
{
public:
	Nodo_Arbol *raiz;
	string grafica;
	AVL(bool cosa);
	int altura(Nodo_Arbol *N);
	int maxi(int a, int b);
	Nodo_Arbol* newNode(string key);
	Nodo_Arbol *RotarDer(Nodo_Arbol *y);
	Nodo_Arbol *RotarIzq(Nodo_Arbol *x);
	int getBalance(Nodo_Arbol *N);
	Nodo_Arbol *insertar(Nodo_Arbol *N, string nick);
	void agregar(string nombre);
	Nodo_Arbol *mini(Nodo_Arbol *nodo);
	Nodo_Arbol *eliminar(Nodo_Arbol *raiz, string usuario);
	void my_delete(string usuario);
	Nodo_Arbol *buscarNodo(string usuario);
	Nodo_Arbol *buscarNod(Nodo_Arbol *raiz, string usuario);
	void graficar();
	void recorrer(Nodo_Arbol *inicio);
	string cadena(int n);
	
};

