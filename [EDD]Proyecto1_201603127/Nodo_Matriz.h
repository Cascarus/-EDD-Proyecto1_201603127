#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Nodo_Matriz
{
private:
	string cadena(int n) {
		stringstream flujo;
		flujo << n;
		return(flujo.str());
	}

public:
	Nodo_Matriz() {
		for (int a = 0; a < 7; a++) {
			contador = rand() % 9;
			concat += cadena(contador);
		}
		std::string::size_type sz;
		hash = stol(concat, &sz);
	}

	Nodo_Matriz *Arriba;
	Nodo_Matriz *Abajo;
	Nodo_Matriz *Siguiente;
	Nodo_Matriz *Anterior;
	int contador;
	int fila;
	int columna;
	string colorhex;
	string color;
	string concat;
	int id;
	long long hash;

};
