#include <iostream>
#include<windows.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

#include "Matriz.h"
#include "AVL.h"
#include "Lista_Doble_Circular.h"
#include "Lista_Simple.h"
#include "Binario.h"


using namespace std;

Matriz mat1 = new Matriz(true);
Matriz mat2 = new Matriz(true);
AVL Usuarios = new AVL(true);
Lista_Doble_Circular Imagenes = new Lista_Doble_Circular(true);
Lista_Doble_Circular ImagenesUsuario = new Lista_Doble_Circular(true);
Lista_Simple Capas_IMG = new Lista_Simple(true);
Binario Arbol_Capas = new Binario(true);
Matriz matri = new Matriz(true);

int ID, fila, columna;
string color, contenido="";
bool encontradoF, encontradoC, insertarAVL;

void Graficar();
void insertar();
void Turno();
void splitear_Capas(string s);
void splitear_Imagenes(string s);
void splitear_Usuarios(string s);
string cadena(int numero);

int main() {
	 
	/*mat1.Insertar(1, 1, 3, "#FE2EC8");
	mat2.Insertar(2, 4, 5, "#27CA9A");
	mat1.Insertar(1, 5, 5, "#e74c3c");
	mat2.Insertar(2, 1, 4, "#0624E9");
	mat1.Insertar(1, 1, 2, "#e74c3c");
	mat2.Insertar(2, 1, 2, "#FE2EC8");

	mat1.buscarCelda(3, 2);
	mat1.buscarCelda(5, 5);
	mat2.buscarCelda(5, 4);

	mat1.graficar(1, mat1.Cprincipal);
	mat2.graficar(2,mat2.Cprincipal);

	Sleep(100);

	mat1.Insertar(1, 7, 7, "#FE2EC8");
	mat2.Insertar(2, 7, 7, "#FE2EC8");

	mat1.graficar(1, mat1.Cprincipal);
	mat2.graficar(2, mat2.Cprincipal);

	Nodo_Matriz *temporal = new Nodo_Matriz();
	temporal = mat1.ObtenerCelda(7, 7);
	cout << "El metodo devolvio el nodo en: " << temporal->fila << "," << temporal->columna << " con el dato de " << temporal->colorhex << endl;
	*/
	/*
	Usuarios.agregar("i");
	Usuarios.agregar("d");
	Usuarios.agregar("s");
	Usuarios.agregar("r");
	Usuarios.agregar("j");
	Usuarios.agregar("c");
	Usuarios.agregar("a");
	Usuarios.agregar("h");
	Usuarios.agregar("k");
	Usuarios.agregar("f");
	Usuarios.graficar();

	Sleep(1000);
	Usuarios.my_delete("i");
	Usuarios.my_delete("f");
	Usuarios.my_delete("c");
	Usuarios.graficar();
	*/
/*
	Imagenes.insertarNuevo(8);
	Imagenes.insertarNuevo(4);
	Imagenes.insertarNuevo(9);
	Imagenes.insertarNuevo(2);
	Imagenes.graf();
	*/

	/*Capas_IMG.agregar(4);
	Capas_IMG.agregar(2);
	Capas_IMG.agregar(1);
	Capas_IMG.agregar(7);
	Capas_IMG.agregar(5);

	

	Capas_IMG.eliminar(5);
	Capas_IMG.eliminar(4);
	Capas_IMG.eliminar(1);
	Capas_IMG.eliminar(4);
	Capas_IMG.graficar();
	*/
	
	/*Arbol_Capas.add(5);
	Arbol_Capas.add(3);
	Arbol_Capas.add(77);
	Arbol_Capas.add(4);
	Arbol_Capas.add(11);
	Arbol_Capas.add(1);
	Arbol_Capas.add(55);
	Arbol_Capas.add(55);
	//Arbol_Capas.graficar();

	Arbol_Capas.graficar();

	Matriz matri = new Matriz(true);
	Nodo_ABB *nodlist = Arbol_Capas.busNodo(3);
	for (int a = 0; a < 3; a++) {
		nodlist = matri.agregarMatriz(3, a+1, a+1,"#FE2EC8" , nodlist);
		nodlist = matri.agregarMatriz(3, a+1, a+2, "#FE2EC8", nodlist);
		Arbol_Capas.modificar(3, nodlist);
	}

	nodlist = Arbol_Capas.busNodo(3);
	matri.graficar(3, nodlist->principal);
	*/
	
	string ruta,palabra;
	cout << "Ingrese la ruta del archivo>>";
	cin >> ruta;
	contenido = "";
	ifstream inFile;
	inFile.open(ruta);
	if (inFile) {
		while (inFile >> palabra)
		{
			
			contenido += palabra + "\n";
			splitear_Capas(palabra);
		}
		palabra = "";
		Nodo_ABB *nodlist = Arbol_Capas.busNodo(2);
		Matriz matri = new Matriz(true);
		matri.graficar(nodlist->id, nodlist->principal);
		cout << nodlist->contenido;
	}
	else {
		cout << "No se pudo abrir el archivo!!" << endl;
	}
	inFile.close();
	Arbol_Capas.graficar();
	
	// leer archivo de imagen
	cout << "Ingrese la ruta del archivo de capas>>";
	cin >> ruta;
	inFile.open(ruta);
	if (inFile) {
		while (inFile >> palabra)
		{
			splitear_Imagenes(palabra);
		}
		palabra = "";
		Imagenes.graf();
	}
	else {
		cout << "No se pudo abrir el archivo!!" << endl;
	}
	inFile.close();

	Nodo_c *IMG = Imagenes.buscarNodo(30);
	Imagenes.crear_IMG(IMG);

	// leer archivo de imagen
	cout << "Ingrese la ruta del archivo de Usuarios>>";
	cin >> ruta;
	inFile.open(ruta);
	if (inFile) {
		while (inFile >> palabra)
		{
			splitear_Usuarios(palabra);
		}
		palabra = "";
		Imagenes.graf();
	}
	else {
		cout << "No se pudo abrir el archivo!!" << endl;
	}
	inFile.close();

	Usuarios.graficar();
	

	system("pause");
	return 0;
}

void splitear_Capas(string str) {
	string palabra = "";
	for (auto x : str) {
		if (x == '{') {
			cout << "Se crea el nodo ABB con id: " << palabra << endl;
			ID = atoi(palabra.c_str());
			Arbol_Capas.add(ID);
			matri = new Matriz(true);
			palabra = "";
		}
		else if (x == ',') {

			if (encontradoF == false) {
				cout << "la coordenada en fila es: " << palabra << endl;
				fila = atoi(palabra.c_str());
				encontradoF = true;
			}
			else if (encontradoC == false) {
				cout << "la coordenada en columna es: " << palabra << endl;
				columna = atoi(palabra.c_str());
				encontradoC = true;
			}
			palabra = "";
		}
		else if (x == ';') {
			cout << "El color de la celda es: " << palabra << endl;
			color = palabra;
			cout << "Se crea el nodo en la matriz y se guarda en el ABB" << endl;
			Nodo_ABB *nodlist = Arbol_Capas.busNodo(ID);
			nodlist = matri.agregarMatriz(ID, fila, columna, color, nodlist);
			Arbol_Capas.modificar(ID, nodlist);
			encontradoC = false;
			encontradoF = false;
			palabra = "";
		}
		else if (x == '}') {
			cout << "se reinician todas las variables" << endl;
			Nodo_ABB *nodlist = Arbol_Capas.busNodo(ID);
			nodlist->contenido = contenido;
			Arbol_Capas.modificar(ID, nodlist);
			contenido = "";
			fila = 0;
			columna = 0;
			encontradoC = false;
			encontradoF = false;
			ID = 0;
		}
		else
		{
			palabra += x;
		}
	}
}

void splitear_Imagenes(string str) {
	string palabra = "";
	for (auto x : str) {
		if (x == '{') {
			cout << "Se crea el nodo ABB con id: " << palabra << endl;
			ID = atoi(palabra.c_str());
			Capas_IMG = new Lista_Simple(true);
			palabra = "";
		}
		else if (x == ',') {
			int no_capa = atoi(palabra.c_str());
			Nodo_ABB *nodArbol = Arbol_Capas.busNodo(no_capa);
			if (nodArbol != NULL) {
				Capas_IMG.agregar(no_capa, nodArbol);
			} else {
				cout << "ERROR: La capa " << no_capa << " no existe" << endl;
			}
			palabra = "";
		}
		else if (x == '}') {
			cout << "se reinician todas las variables" << endl;
			int no_capa = atoi(palabra.c_str());
			Nodo_ABB *nodArbol = Arbol_Capas.busNodo(no_capa);
			if (nodArbol != NULL) {
				Capas_IMG.agregar(no_capa, nodArbol);
			} else {
				cout << "ERROR: La capa " << no_capa << " no existe" << endl;
			}

			Imagenes.insertarNuevo(ID, Capas_IMG.primero);
			Nodo_c *nodImg = Imagenes.buscarNodo(ID);
			if (nodImg != NULL)
			{
				nodImg->colMax = Capas_IMG.colMax;
				nodImg->filMax = Capas_IMG.filaMax;
			}
			palabra = "";
			ID = 0;
		}
		else
		{
			palabra += x;
		}
	}
}

void splitear_Usuarios(string str) {
	string palabra = "";
	string usuario = "";
	for (auto x : str) {
		if (x == ':') {
			usuario = palabra;
			if (!Usuarios.existe(usuario)) {
				Usuarios.agregar(usuario);
				ImagenesUsuario = new Lista_Doble_Circular(true);
			}
			else {
				palabra = "";
				break;
			}
			palabra = "";
		}
		else if (x == ',') {

			int imagen = atoi(palabra.c_str());
			Nodo_c *actual = Imagenes.buscarNodo(imagen);
			if (actual != NULL) {
				ImagenesUsuario.insertarNuevo(imagen, actual->primero_lista);
			}
			palabra = "";
		}
		else if (x == ';') {
			int imagen = atoi(palabra.c_str());
			Nodo_c *actual = Imagenes.buscarNodo(imagen);
			
			if (actual != NULL) {
				ImagenesUsuario.insertarNuevo(imagen, actual->primero_lista);
			}

			Usuarios.update(usuario, ImagenesUsuario.primero);
			palabra = "";
		}
		else
		{
			palabra += x;
		}
	}
}