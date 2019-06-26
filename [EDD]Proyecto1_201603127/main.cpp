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

void Cargar_Archivos();
void Generar_Imagenes();
void mUsuarios();
void mImagenes();
void reportes();
void splitear_Capas(string s);
void splitear_Imagenes(string s);
void splitear_Usuarios(string s);
string splitear_Recorridos(string s, int no);
void graf_recorrido(string str, int no_capas);
void Recorrido_Lim(int no_capas, int tipo_recorrido);

bool esNumero(string linea);
string cadena(int numero);

int main() {
	 
	int opcion = 0;
	while (opcion != 6) {
		system("cls");
		cout << "-----------------MENU PRINCIPAL-----------------" << endl;
		cout << "|   1. CARGAR ARCHIVOS                         |" << endl;
		cout << "|   2. GENERARCION DE IMAGENES                 |" << endl;
		cout << "|   3. USUARIOS                                |" << endl;
		cout << "|   4. IMAGENES                                |" << endl;
		cout << "|   5. REPORTES                                |" << endl;
		cout << "|   6. SALIR                                   |" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "ingrese la opcion que desee realizar: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			Cargar_Archivos();
			//system("pause");
			break;

		case 2:
			int tur;
			system("cls");
			Generar_Imagenes();
			break;

		case 3:
			system("cls");
			mUsuarios();
			break;

		case 4:
			system("cls");
			mImagenes();
			break;

		case 5:
			system("cls");
			reportes();
			break;

		case 6:
			cout << "Finalizando.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			break;

		default:
			cout << "Inserte una opcion valida!!" << endl;
			system("pause");
			break;
		}
	}

	//system("pause");
	return 0;
}

void Cargar_Archivos() {
	int opcion = 0;
	string ruta, palabra;
	ifstream inFile;

	while (opcion != 4) {
		system("cls");
		cout << "------------------MENU CARGAR------------------" << endl;
		cout << "|   1. CARGAR CAPAS                           |" << endl;
		cout << "|   2. CARGAR IMAGENES                        |" << endl;
		cout << "|   3. CARGAR USUARIOS                        |" << endl;
		cout << "|   4. SALIR                                  |" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "ingrese la opcion que desee realizar: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			cout << "Ingrese la ruta del archivo de capas>>";
			cin >> ruta;
			contenido = "";
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
				//matri.graficar(nodlist->id, nodlist->principal);
				//cout << nodlist->contenido;
			}
			else {
				cout << "No se pudo abrir el archivo!!" << endl;
			}
			inFile.close();
			//Arbol_Capas.graficar();
			Arbol_Capas.graficar_Espejo();
			Arbol_Capas.graficar();
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "Ingrese la ruta del archivo de imagenes>>";
			cin >> ruta;
			inFile.open(ruta);
			if (inFile) {
				while (inFile >> palabra)
				{
					splitear_Imagenes(palabra);
				}
				palabra = "";
				//Imagenes.graf();
			}
			else {
				cout << "No se pudo abrir el archivo!!" << endl;
			}
			inFile.close();

			//{Nodo_c *IMG = Imagenes.buscarNodo(30);
			//Imagenes.crear_IMG(IMG);}
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "Ingrese la ruta del archivo de Usuarios>>";
			cin >> ruta;
			inFile.open(ruta);
			if (inFile) {
				while (inFile >> palabra)
				{
					splitear_Usuarios(palabra);
				}
				palabra = "";
				//Imagenes.graf();
			}
			else {
				cout << "No se pudo abrir el archivo!!" << endl;
			}
			inFile.close();
			//Usuarios.graficar();
			//Imagenes.graf();
			system("pause");
			break;

		case 4:
			cout << "Finalizando.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			cout << endl;
			break;

		default:
			cout << "Inserte una opcion valida!!" << endl;
			system("pause");
			break;
		}
	}
}

void Generar_Imagenes() {
	int opcion = 0, orden, no_capas;
	string linea, palabra;
	ifstream inFile;
	bool repetir = true;
	bool repetir2 = true;
	string imagenes_usurio = "";

	while (opcion != 5) {
		system("cls");
		cout << "----------------MENU GENERAR IMAGEN----------------" << endl;
		cout << "|   1. POR RECORRIDO LIMITADO                     |" << endl;
		cout << "|   2. POR LISTA DE IMAGENES                      |" << endl;
		cout << "|   3. POR CAPA                                   |" << endl;
		cout << "|   4. POR USUARIO                                |" << endl;
		cout << "|   5. SALIR                                      |" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "ingrese la opcion que desee realizar: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			do {
				system("cls");
				cout << "Ingrese el numero de capas a utilizar>> ";
				cin >> linea;
				
				if (esNumero(linea)) {
					repetir = false;
					no_capas = atoi(linea.c_str());

					do {
						cout << "--------------------Recoridos--------------------" << endl;
						cout << "1. PRE-ORDER" << endl;
						cout << "2. IN-ORDER" << endl;
						cout << "3. POST-ORDER" << endl;
						cout << "Ingrese el numero del recorido a utilizar>> ";
						cin >> linea;

						if (esNumero(linea)) {
							repetir2 = false;
							orden = atoi(linea.c_str());

							if (no_capas >= Arbol_Capas.no_Nodos) {
								no_capas = Arbol_Capas.no_Nodos;
							}

							Recorrido_Lim(no_capas, orden);

						} else {
							cout << "Debe ingresar solamente numeros positivos" << endl;
							Sleep(1000);
						}

					} while (repetir2);

				} else {
					cout << "Debe ingresar solamente numeros positivos" << endl;
					Sleep(1000);
				}
			} while (repetir);
			repetir = true;
			repetir2 = true;
			system("pause");
			break;

		case 2:
			do {
				system("cls");
				cout << "Ingrese el id de la imagen que desea graficar>> ";
				cin >> linea;

				if (esNumero(linea)) {
					repetir = false;
					no_capas = atoi(linea.c_str());
					Nodo_c *IMG = Imagenes.buscarNodo(no_capas);
					if (IMG != NULL) {
						Imagenes.crear_IMG(IMG);
					}
					else {
						cout << "ERROR: la imagen " << no_capas << " no existe";
						Sleep(1000);
						repetir = true;
					}
				}
				else {
					cout << "Debe ingresar solamente numeros positivos" << endl;
					Sleep(1000);
				}
			} while (repetir);
			system("pause");
			break;

		case 3:
			do {
				system("cls");
				cout << "Ingrese el id de la imagen que desea graficar>> ";
				cin >> linea;

				if (esNumero(linea)) {
					repetir = false;
					no_capas = atoi(linea.c_str());
					Nodo_ABB *nodlist = Arbol_Capas.busNodo(no_capas);
					if (nodlist != NULL) {
						Arbol_Capas.crear_IMG(nodlist);
					}
					else {
						cout << "ERROR: la capa " << no_capas << " no existe";
						Sleep(1000);
						repetir = true;
					}
				}
				else {
					cout << "Debe ingresar solamente numeros positivos" << endl;
					Sleep(1000);
				}
			} while (repetir);
			repetir = true;
			system("pause");
			break;

		case 4:
			int no_imagen;
			Nodo_Arbol *nodAVL;
			system("cls");
			cout << "Ingrese el id del usuarios>> ";
			cin >> linea;
			nodAVL = Usuarios.buscarNodo(linea);
			if (nodAVL != NULL) {
				if (nodAVL->primero != NULL) {
					Nodo_c *aux_lista = nodAVL->primero;
					Lista_Doble_Circular lista_d_aux = new Lista_Doble_Circular(true);
					lista_d_aux.primero = nodAVL->primero;

					do {
						imagenes_usurio += cadena(aux_lista->id) + " ";
						aux_lista = aux_lista->Siguiente;
					} while (aux_lista != nodAVL->primero);

					cout << "Las imagenes que contiene el usuario " << linea << "son: " << imagenes_usurio << endl;
					cout << "Seleccione la imagen que desea graficar: ";
					cin >> linea;

					if (esNumero(linea)) {
						no_capas = atoi(linea.c_str());
						Nodo_c *IMG = lista_d_aux.buscarNodo(no_capas);
						if (IMG != NULL) {
							lista_d_aux.crear_IMG(IMG);
						}
					} else {
						cout << "Debe ingresar solamente numeros positivos" << endl;
						Sleep(1000);
					}
				} else {
					cout << "El usuario no posee ninguna imagen" << endl;
					Sleep(1000);
				}
			}
			imagenes_usurio = "";
			system("pause");
			break;

		case 5:
			cout << "Finalizando.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			break;

		default:
			cout << "Inserte una opcion valida!!" << endl;
			system("pause");
			break;
		}
	}
}

void mUsuarios() {
	int opcion = 0;
	string palabra, id_nuevo;

	while (opcion != 4) {
		system("cls");
		cout << "------------------MENU USURIOS------------------" << endl;
		cout << "|   1. AGREGAR USUARIO                         |" << endl;
		cout << "|   2. ELIMINAR USUARIO                        |" << endl;
		cout << "|   3. MODIFICAR USUARIO                       |" << endl;
		cout << "|   4. SALIR                                   |" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "ingrese la opcion que desee realizar: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			cout << "Ingrese el id del nuevo usuario>>";
			cin >> palabra;
			if (!Usuarios.existe(palabra)) {
				Usuarios.agregar(palabra);
				cout << "El usuario " << palabra << "fue agregado exitosamente!" << endl;
			} else {
				cout << "El usuario " << palabra << " ya existe, elija otro ID" << endl;
			}
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "Ingrese el id del usuario que desea eliminar>>";
			cin >> palabra;
			if (Usuarios.existe(palabra)) {
				Usuarios.my_delete(palabra);
				cout << "El usuario " << palabra << "fue agregado exitosamente!" << endl;
			}
			else {
				cout << "El usuario " << palabra << " ya existe, elija otro ID" << endl;
			}
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "Ingrese el id del usuario que desea modificar>>";
			cin >> palabra;
			if (Usuarios.existe(palabra)) {
				cout << "Ingrese el nuevo id >>" ;
				cin >> id_nuevo;
				if (!Usuarios.existe(id_nuevo)) {
					Usuarios.update2(palabra, id_nuevo);
				}else{
					cout << "El usuario " << id_nuevo << " ya existe, elija otro ID" << endl;
				}
			} else {
				cout << "El usuario " << palabra << " ya existe, elija otro ID" << endl;
			}
			system("pause");
			break;

		case 4:
			cout << "Regresando al menu principal.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			break;

		default:
			cout << "Inserte una opcion valida!!" << endl;
			system("pause");
			break;
		}
	}
}

void mImagenes() {
	int opcion = 0;
	string linea, id_img;
	string imagenes_usurio = "";

	while (opcion != 3) {
		system("cls");
		cout << "-----------------MENU IMAGENES-----------------" << endl;
		cout << "|   1. AGREGAR IMAGEN                         |" << endl;
		cout << "|   2. ELIMINAR IMAGEN                        |" << endl;
		cout << "|   3. SALIR                                  |" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "ingrese la opcion que desee realizar: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			/*cout << "Ingrese el id del nuevo usuario>>";
			cin >> palabra;
			if (!Usuarios.existe(palabra)) {
				Usuarios.agregar(palabra);
				cout << "El usuario " << palabra << "fue agregado exitosamente!" << endl;
			}
			else {
				cout << "El usuario " << palabra << " ya existe, elija otro ID" << endl;
			}*/
			system("pause");
			break;

		case 2:
			int no_imagen, no_capas;
			Nodo_Arbol *nodAVL;
			system("cls");
			cout << "Ingrese el id del usuario que al que desea ingresar>>";
			cin >> id_img;
			nodAVL = Usuarios.buscarNodo(id_img);
			if (nodAVL != NULL) {
				if (nodAVL->primero != NULL) {
					Nodo_c *aux_lista = nodAVL->primero;
					Lista_Doble_Circular lista_d_aux = new Lista_Doble_Circular(true);
					lista_d_aux.primero = nodAVL->primero;
					lista_d_aux.ultimo = nodAVL->ultimo;

					do {
						imagenes_usurio += cadena(aux_lista->id) + " ";
						aux_lista = aux_lista->Siguiente;
					} while (aux_lista != nodAVL->primero);

					cout << "Las imagenes que contiene el usuario " << linea << "son: " << imagenes_usurio << endl;
					cout << "Seleccione la imagen que desea eliminar: ";
					cin >> linea;

					if (esNumero(linea)) {
						no_capas = atoi(linea.c_str());
						Nodo_c *IMG = lista_d_aux.buscarNodo(no_capas);
						if (IMG != NULL) {
							lista_d_aux.eliminar(no_capas);
							Imagenes.eliminar(no_capas);
							Usuarios.update(id_img, lista_d_aux);
						}
					}
					else {
						cout << "Debe ingresar solamente numeros positivos" << endl;
						Sleep(1000);
					}
				}
				else {
					cout << "El usuario no posee ninguna imagen" << endl;
					Sleep(1000);
				}
			}
			imagenes_usurio = "";
			Usuarios.graficar();
			Imagenes.graf();
			system("pause");
			break;

		case 4:
			cout << "Regresando al menu principal.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			break;

		default:
			cout << "Inserte una opcion valida!!" << endl;
			system("pause");
			break;
		}
	}
}

void reportes() {
	int opcion = 0;
	string linea, id_img;
	string imagenes_usurio = "";
	bool repetir = true;

	while (opcion != 15) {
		system("cls");
		cout << "-----------------MENU REPORTES-----------------" << endl;
		cout << "|   1. LISTA DE IMAGENES                      |" << endl;
		cout << "|   2. ARBOL DE CAPAS                         |" << endl;
		cout << "|   3. ESPEJO DE CAPAS                        |" << endl;
		cout << "|   4. VER CAPA                               |" << endl;
		cout << "|   5. IMAGEN Y CAPA*                         |" << endl;
		cout << "|   6. ARBOL USUARIOS                         |" << endl;
		cout << "|   8. CAPAS HOJAS                            |" << endl;
		cout << "|   10. MOSTRAR CAPAS EN POSTORDEN            |" << endl;
		cout << "|   11. LISTA DE CAPAS POR RECORRIDO          |" << endl;
		cout << "|   13. ESPEJO DE USUARIOS                    |" << endl;
		cout << "|   14. LISTA DE USUARIOS POR RECORRIDO       |" << endl;
		cout << "|   15. SALIR                                 |" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "ingrese la opcion que desee realizar: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			cout << "Graficando.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			cout << endl;
			Imagenes.graf();
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "Graficando.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			cout << endl;
			Arbol_Capas.graficar();
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "Graficando.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			cout << endl;
			Arbol_Capas.graficar_Espejo();
			system("pause");
			break;

		case 4:
			do {
				Matriz matri = new Matriz(true);
				int no_capa;
				system("cls");
				cout << "Ingrese el numero de la capa capas>> ";
				cin >> linea;

				if (esNumero(linea)) {
					repetir = false;
					no_capa = atoi(linea.c_str());
					if (Arbol_Capas.existe(no_capa)) {
						Nodo_ABB *nodlist = Arbol_Capas.busNodo(no_capa);
						matri.graficar(nodlist->id, nodlist->principal);
					} else {
						cout << "La capa "<< no_capa << " no existe" << endl;
						repetir = true;
					}
				}
				else {
					cout << "Debe ingresar solamente numeros positivos" << endl;
					Sleep(1000);
				}
			} while (repetir);
			repetir = true;
			system("pause");
			break;

		case 5:
			int no_capas;
			do {
				system("cls");
				cout << "Ingrese el id de la imagen que desea graficar>> ";
				cin >> linea;

				if (esNumero(linea)) {
					repetir = false;
					no_capas = atoi(linea.c_str());
					Nodo_c *IMG = Imagenes.buscarNodo(no_capas);
					if (IMG != NULL) {
						Imagenes.crear_IMG2(IMG,Arbol_Capas.raiz);
					}
					else {
						cout << "ERROR: la imagen " << no_capas << " no existe";
						Sleep(1000);
						repetir = true;
					}
				}
				else {
					cout << "Debe ingresar solamente numeros positivos" << endl;
					Sleep(1000);
				}
			} while (repetir);
			system("pause");
			break;

		case 6:
			system("cls");
			cout << "Graficando.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			Usuarios.graficar();
			system("pause");
			break;

		case 8:
			system("cls");
			cout << "Capas que son hojas: ";
			cout << Arbol_Capas.bHojas();
			cout << endl;
			system("pause");
			break;

		case 10:
			system("cls");
			Arbol_Capas.PostOrden(Arbol_Capas.raiz);
			cout << "Capas en postorden: " << Arbol_Capas.posOrd << endl;
			graf_recorrido(Arbol_Capas.posOrd, Arbol_Capas.no_Nodos);
			Arbol_Capas.posOrd = "";
			system("pause");
			break;

		case 11:
			system("cls");
			Arbol_Capas.PreOrden(Arbol_Capas.raiz);
			Arbol_Capas.InOrden(Arbol_Capas.raiz);
			Arbol_Capas.PostOrden(Arbol_Capas.raiz);
			cout << "Capas en preorden: " << Arbol_Capas.preOrd << endl;
			cout << "Capas en inorden: " << Arbol_Capas.inOrd << endl;
			cout << "Capas en postorden: " << Arbol_Capas.posOrd << endl;
			Arbol_Capas.preOrd = "";
			Arbol_Capas.inOrd = "";
			Arbol_Capas.posOrd = "";
			system("pause");
			break;

		case 13:
			system("cls");
			cout << "Creando espejo de usuario.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			Usuarios.graficar_Espejo();
			system("pause");
			break;

		case 14:
			system("cls");
			Usuarios.PreOrden(Usuarios.raiz);
			Usuarios.InOrden(Usuarios.raiz);
			Usuarios.PostOrden(Usuarios.raiz);
			cout << "Usuarios en preorden: " << Usuarios.preOrd << endl;
			cout << "Usuarios en inorden: " << Usuarios.inOrd << endl;
			cout << "Usuarios en postorden: " << Usuarios.posOrd << endl;
			Usuarios.preOrd = "";
			Usuarios.inOrd = "";
			Usuarios.posOrd = "";
			system("pause");
			break;

		case 15:
			cout << "Regresando al menu principal.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			break;

		default:
			cout << "Inserte una opcion valida!!" << endl;
			system("pause");
			break;
		}
	}
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
				//cout << "la coordenada en fila es: " << palabra << endl;
				fila = atoi(palabra.c_str());
				encontradoF = true;
			}
			else if (encontradoC == false) {
				//cout << "la coordenada en columna es: " << palabra << endl;
				columna = atoi(palabra.c_str());
				encontradoC = true;
			}
			palabra = "";
		}
		else if (x == ';') {
			//cout << "El color de la celda es: " << palabra << endl;
			color = palabra;
			//cout << "Se crea el nodo en la matriz y se guarda en el ABB" << endl;
			Nodo_ABB *nodlist = Arbol_Capas.busNodo(ID);
			nodlist = matri.agregarMatriz(ID, fila, columna, color, nodlist);
			Arbol_Capas.modificar(ID, nodlist);
			encontradoC = false;
			encontradoF = false;
			palabra = "";
		}
		else if (x == '}') {
			//cout << "se reinician todas las variables" << endl;
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

			Imagenes.insertarNuevo(ID, Capas_IMG.primero);//tengo q mandar primero y ultimo
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
				Nodo_c *nodImg = ImagenesUsuario.buscarNodo(imagen);
				if (nodImg != NULL)
				{
					nodImg->colMax = actual->colMax;
					nodImg->filMax = actual->filMax;
				}
			}
			palabra = "";
		}
		else if (x == ';') {
			int imagen = atoi(palabra.c_str());
			Nodo_c *actual = Imagenes.buscarNodo(imagen);
			
			if (actual != NULL) {
				ImagenesUsuario.insertarNuevo(imagen, actual->primero_lista);
				Nodo_c *nodImg = ImagenesUsuario.buscarNodo(imagen);
				if (nodImg != NULL)
				{
					nodImg->colMax = actual->colMax;
					nodImg->filMax = actual->filMax;
				}
			}

			Usuarios.update(usuario, ImagenesUsuario);
			palabra = "";
		}
		else
		{
			palabra += x;
		}
	}
}

string splitear_Recorridos(string str, int no_capas) {
	string palabra = ""; 
	string strCapas = "";
	for (auto x : str) {
		if (no_capas != 0) {
			if (x == ' ') {
				if ( no_capas <= 1) {
					strCapas += palabra;
				} else {
					strCapas += palabra + ",";
				}
				palabra = "";
				no_capas--;
			} else {
				palabra += x;
			}
		} else {
			break;
		}
	}
	return strCapas;
}

void graf_recorrido(string str, int no_capas) {
	string palabra = "";
	int id;
	for (auto x : str) {
		if (no_capas != 0) {
			if (x == ' ') {
				id = atoi(palabra.c_str());
				Nodo_ABB *nodlist = Arbol_Capas.busNodo(id);
				Matriz matri = new Matriz(true);
				matri.graficar(nodlist->id, nodlist->principal);
				palabra = "";
				no_capas--;
			}
			else {
				palabra += x;
			}
		}
		else {
			break;
		}
	}
}

void Recorrido_Lim(int no_capas, int tipo_recorrido) {
	string contenido_recorrido = "", id_string = "";
	Lista_Doble_Circular Copia_Imagenes = Imagenes;
	Imagenes = new Lista_Doble_Circular(true);
	int id_temp = 0;

	switch (tipo_recorrido) {
	case 1:
		Arbol_Capas.PreOrden(Arbol_Capas.raiz);
		id_string = cadena(tipo_recorrido) + cadena(no_capas);
		id_temp = atoi(id_string.c_str());
		id_string += "{";
		contenido_recorrido =  splitear_Recorridos(Arbol_Capas.preOrd, no_capas);
		cout << "Se superpondran las capas: " << contenido_recorrido << endl;
		Arbol_Capas.preOrd = "";
		Sleep(500);

		break;
	case 2:
		Arbol_Capas.InOrden(Arbol_Capas.raiz);
		id_string = cadena(tipo_recorrido) + cadena(no_capas);
		id_temp = atoi(id_string.c_str());
		id_string += "{";
		contenido_recorrido = splitear_Recorridos(Arbol_Capas.inOrd, no_capas);
		cout << "Se superpondran las capas: " << contenido_recorrido << endl;
		Arbol_Capas.inOrd = "";
		Sleep(500);
		break;
	case 3:
		Arbol_Capas.PostOrden(Arbol_Capas.raiz);
		id_string = cadena(tipo_recorrido) + cadena(no_capas);
		id_temp = atoi(id_string.c_str());
		id_string += "{";
		contenido_recorrido = splitear_Recorridos(Arbol_Capas.posOrd, no_capas);
		cout << "Se superpondran las capas: " << contenido_recorrido << endl;
		Arbol_Capas.posOrd = "";
		Sleep(500);
		break;

	default:
		break;
	}
	splitear_Imagenes(id_string + contenido_recorrido + "}");
	Nodo_c *IMG = Imagenes.buscarNodo(id_temp);
	Imagenes.crear_IMG(IMG);
	Imagenes = Copia_Imagenes;
}

bool esNumero(string linea) {
	bool b = true;
	int longitud = linea.size();

	if (longitud == 0) {
		return false;
	}
	else if (longitud == 1 && !isdigit(linea[0])) {
		return false;
	}
	else {
		int i;
		if (linea[0] == '+') {
			i = 1;
		}
		else {
			i = 0;
		}

		while (i<longitud) {
			if (!isdigit(linea[i])) {
				return false;
			}
			i++;
		}
	}
	return true;
}

string cadena(int n) {
	stringstream flujo;
	flujo << n;
	return(flujo.str());
}