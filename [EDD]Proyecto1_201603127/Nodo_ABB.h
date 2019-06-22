#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string> 

class Nodo_ABB {

public:
	Nodo_ABB() {
		derecha = NULL;
		izquierda = NULL;
	}

	int id;
	Nodo_ABB *derecha;
	Nodo_ABB *izquierda;
	Nodo_Matriz *principal;
	Nodo_Matriz *filas;
	Nodo_Matriz *columnas;
};