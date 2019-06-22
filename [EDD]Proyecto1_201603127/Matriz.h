#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Nodo_Matriz.h"
#include "Nodo_ABB.h"


using namespace std;




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
	Nodo_ABB *agregarMatriz(int id, int fil, int col, string color, Nodo_ABB *nodo);
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

