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
Lista_Simple Capas_IMG = new Lista_Simple(true);
Binario Arbol_Capas = new Binario(true);
Matriz matri = new Matriz(true);

int ID, fila, columna;
string color, contenido;
bool encontradoF, encontradoC;

void Graficar();
void insertar();
void Turno();
void splitear(string s);
string cadena(int numero);

int main() {
	/*
	int opcion = 0;
	while (opcion != 4) {
		system("cls");
		cout << "1. INSETAR" << endl;
		cout << "2. AVANZAR TURNO" << endl;
		cout << "3. GRAFICAR" << endl;
		cout << "4. SALIR" << endl;
		cout << "ingrese la opcion que desee realizar: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			insertar();
			system("pause");
			break;

		case 2:
			int tur;
			system("cls");
			cout << "ingrese el numero de turnos quiere avanzar...";
			cin >> tur;
			for (int a = 0;a < tur;a++) {
				Turno();
			}
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "Graficando.";
			for (int a = 0; a < 10; a++) {
				Sleep(100);
				cout << ".";
			}
			Graficar();
			cout << endl;
			system("pause");
			break;

		case 4:
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
	}*/
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
	/*
	Arbol_Capas.add(5);
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

	ifstream inFile;
	inFile.open(ruta);

	contenido = "";
	
	if (inFile) {
		while (inFile>>palabra)
		{
			contenido += palabra = "\n";
			splitear(palabra);
		}
		Nodo_ABB *nodlist = Arbol_Capas.busNodo(1);
		Matriz matri = new Matriz(true);
		matri.graficar(nodlist->id, nodlist->principal);
	}
	else {
		cout << "No se pudo abrir el archivo!!"<<endl;
	}
	inFile.close();

	

	system("pause");
	return 0;
}

void splitear(string str) {
	string palabra = "";
	for (auto x: str) {
		if (x == '{') {
			cout << "Se crea el nodo ABB con id: " << palabra << endl;
			ID = atoi(palabra.c_str());
			Arbol_Capas.add(ID);
			matri = new Matriz(true);
			palabra = "";
		}
		else if (x == ',') {

			if (encontradoF == false) {
				cout << "la coordenada en fila es: "<< palabra << endl;
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
			cout << "Se crea el nodo en la matriz y se guarda en el ABB" <<endl;
			Nodo_ABB *nodlist = Arbol_Capas.busNodo(ID);
			nodlist = matri.agregarMatriz(ID, fila, columna, color, nodlist);
			Arbol_Capas.modificar(ID, nodlist);
			encontradoC = false;
			encontradoF = false;
			palabra = "";
		}
		else if (x == '}') {
			cout << "se reinician todas las variables" << endl;
			/*Nodo_ABB *nodlist = Arbol_Capas.busNodo(ID);
			nodlist->contenido = contenido;
			Arbol_Capas.modificar(ID, nodlist);*/
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
	cout<<"???"<<palabra<<endl;
}

/*
void insertar() {
	int opcion = 0;
	int valor = 0;
	int cliente, carreta, caja;
	while (opcion != 7) {
		system("cls");
		cout << "1. INSETAR MATRIZ" << endl;
		cout << "2. INSERTAR CARRETILLAS" << endl;
		cout << "3. INSERTAR CAJAS" << endl;
		cout << "4. MOSTRAR CLIENTES" << endl;
		cout << "5. MOSTRAR CARRETILLAS" << endl;
		cout << "6. MOSTRAR CAJAS" << endl;
		cout << "7. REGRESAR" << endl;
		cout << "ingrese la opcion que desee realizar: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			cout << "Ingrese las coordenadas desea ingresar: ";
			cin >> valor;
			for (int a = 0; a < valor; a++) {
				cout << "Ingrese un cliente (No se puden repetir).....";
				cin >> cliente;
				Cola_Espera.agregarCliente(cliente);
				bitacora += "Llega cliente " + cadena(cliente) + " y se agrega a la cola de espera\n";
			}
			cout << "se ha ingresado " << valor << " clientes correctamente al sistema! " << endl; //<< " en la pila " << car<< endl;
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "Cuantas carretas desea ingresar: ";
			cin >> valor;
			for (int a = 0; a < valor; a++) {
				cout << "Ingrese una carretilla (No se puden repetir).....";
				cin >> carreta;
				random = rand() % 2 + 1;
				if (random == 1) {
					carreta1.push(carreta);
				}
				else {
					carreta2.push(carreta);
				}
			}
			cout << "se han ingresado " << valor << " carretilla correctamente al sistema! " << endl; //<< " en la pila " << car<< endl;
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "Cuantas cajas desea ingresar: ";
			cin >> valor;
			for (int a = 0; a < valor; a++) {
				cout << "Ingrese una caja (No se puden repetir).....";
				cin >> caja;
				random = rand() % 10 + 1;
				Cajas.agregar(caja, random);
			}
			cout << "se han ingresado " << valor << " cajas correctamente al sistema! " << endl; //<< " en la pila " << car<< endl;
			system("pause");
			break;

		case 4:
			system("cls");
			cout << "Clientes en cola de espera de carretas " << endl;
			Cola_Espera.mostrar();
			system("pause");
			break;

		case 5:
			system("cls");
			cout << "Carretillas en Pila #1 " << endl;
			carreta1.mostrar();
			cout << "\n\n Carretillas en Pila #2 " << endl;
			carreta2.mostrar();
			system("pause");
			break;

		case 6:
			system("cls");
			cout << "Cajas en el sistema " << endl;
			Cajas.mostrar();
			system("pause");
			break;

		case 7:
			break;

		default:
			cout << "Inserte una opcion valida!!" << endl;
			system("pause");
			break;
		}
	}
}

void Turno() {
	int cliente, carreta;
	turnos++;

	cout << "---------------------Turno " << turnos << "---------------------" << endl;
	cout << bitacora;
	bitacora = "";

	//CIENTE AGARRA CARRETA
	if (!Cola_Espera.isNull()) {
		if (!carreta1.isNull() || !carreta2.isNull()) {
			cliente = Cola_Espera.sacarCliente();

			if (!carreta1.isNull() && !carreta2.isNull()) {
				random = rand() % 2 + 1;
				if (random == 1) {
					carreta = carreta1.pop();
				}
				else {
					carreta = carreta2.pop();
				}
			}
			else if (carreta2.isNull()) {
				carreta = carreta1.pop();
			}
			else {
				carreta = carreta2.pop();
			}
			Compras.agregar(cliente, carreta);
			cout << "Cliente " << cliente << " toma la carreta " << carreta << " y se incorpora a la lista de compras" << endl;
		}
	}

	//GENERAR NUMERO ALEATORIO Y SACARLO SI SE PUEDE
	if (!Compras.isNull()) {
		random = rand() % 20;
		cout << "El random es..." << random << endl;
		if (Compras.VerificarTamanio(random + 1)) {
			cliente = Compras.sacarCliente(random + 1);
			carreta = Compras.sacarCarreta(random + 1);
			Compras.sacar(random + 1);
			Cola_Pago.agregarEspera(cliente, carreta);
			cout << "Cliente " << cliente << " entra a la cola de pagos" << endl; //componer el cliente 
		}
	}

	//AVANZAR TURNOS EN CAJA
	Cajas.avanzarTurno();

	//PASAR CLIENTES DE COLA DE PAGOS A CAJA DISPONIBLE 
	nodo_doble *actual = new nodo_doble();
	actual = Cajas.primero;
	if (!Cajas.isNull()) {
		while (actual != NULL) {
			int no_caja = actual->no_caja;

			//INGRESA CLIENTE A CAJA
			if (actual->estado == true) {
				if (!Cola_Pago.isNull()) {
					cliente = Cola_Pago.sacarEsperaCliente();
					carreta = Cola_Pago.sacarCarreta();
					Cola_Pago.sacarPagar();
					Cajas.LlegaCliente(no_caja, cliente, carreta);
					cout << "El cliente " << cliente << " pasa a la caja " << no_caja << endl;
				}
			}

			//LIBERAR CAJA
			if (actual->liberar == true) {
				cliente = Cajas.ObtenerCliente(no_caja);
				carreta = Cajas.ObtenerCarreta(no_caja);
				Cajas.LiberarCaja(no_caja);
				cout << "Cliente " << cliente << " sale de la caja. Libera carreta " << carreta << " y caja " << no_caja << endl;
				random = rand() % 2 + 1;
				if (random == 1) {
					carreta1.push(carreta);
				}
				else {
					carreta2.push(carreta);
				}
			}

			actual = actual->siguiente;
		}
	}



}

void Graficar() {
	string grafica = "";
	ofstream archivo;
	archivo.open("Practica_1.dot");
	archivo << "digraph {\n";
	if (!Cola_Espera.isNull()) {
		archivo << "subgraph Cola_Espera{\n";
		archivo << Cola_Espera.recorre(1);
		archivo << "}\n";
	}
	archivo << "subgraph Pilas_Carretas{\n";
	if (!carreta1.isNull()) {
		archivo << carreta1.recorre(1);
	}
	if (!carreta2.isNull()) {
		archivo << carreta2.recorre(2);
	}
	archivo << "}\n";

	if (!Compras.isNull()) {
		archivo << "subgraph Compras{\n";
		archivo << Compras.recorre();
		archivo << "}\n";
	}

	if (!Cola_Pago.isNull()) {
		archivo << "subgraph Pago{\n";
		archivo << Cola_Pago.recorre(2);
		archivo << "}\n";
	}

	if (!Cajas.isNull()) {
		archivo << "subgraph Cajas{\n";
		archivo << Cajas.recorre();
		archivo << "}\n";
	}

	archivo << "}";
	archivo.close();

	system("dot -Tpng Practica_1.dot -o Practica_1.png -Gcharset=latin1");
	system("Practica_1.png");
}

string cadena(int n) {
	stringstream flujo;
	flujo << n;
	return(flujo.str());
}*/