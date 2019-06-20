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


class Matriz
{
public:
	Nodo_Matriz *CabeceraC;
	Nodo_Matriz *CabeceraF;
	Nodo_Matriz *Cprincipal;
	bool encontradofil = false;
	bool encontradoCol = false;
	string relaciones = "", labels = "", rank = "";

	Matriz(bool c);
	void Insertar(int id, int fil, int col, string color);
	void insertarFila(int fil);
	void insertarColumna(int col);
	void insertarCelda(int x, int y, string terreno);
	string cadena(int n);
	void buscarfila(int fil);
	void buscarcol(int col);
	void buscarCelda(int col, int fil);
	Nodo_Matriz *ObtenerCelda(int col, int fil);
	void graficar(int id, Nodo_Matriz *principal);
	void recorrer(Nodo_Matriz *inicio);
};

