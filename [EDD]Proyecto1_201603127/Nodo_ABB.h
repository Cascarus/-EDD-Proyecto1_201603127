#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string> 
#include "Nodo_Matriz.h"

class Nodo_ABB {

public:
	Nodo_ABB() {
		derecha = NULL;
		izquierda = NULL;
		contenido = "";
		filMax = 0;
		colMax = 0;
	}

	int id;
	Nodo_ABB *derecha;
	Nodo_ABB *izquierda;
	Nodo_Matriz *principal;
	Nodo_Matriz *filas;
	Nodo_Matriz *columnas;
	string contenido;
	int filMax;
	int colMax;
};