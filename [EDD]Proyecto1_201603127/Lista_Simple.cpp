#include "Lista_Simple.h"

void Lista_Simple::agregar(int dato, Nodo_ABB *&capa) {
	Nodo_Lista *nuevo = new Nodo_Lista();
	nuevo->dato = dato;
	nuevo->capa = capa;
	if (primero == NULL) {
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else {
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	buscar_dim_mayores(capa);
}

void Lista_Simple::eliminar(int dato) {
	
	Nodo_Lista *actual = primero;
	Nodo_Lista *anterior = new Nodo_Lista();
	bool encontrado = false;

	if (primero != NULL) {
		if (primero->dato == dato) {
			primero = primero->siguiente;
			encontrado = true;
		}else {
			while (actual != NULL)
			{
				if (ultimo->dato == actual->dato && actual->dato == dato) {
					anterior->siguiente = NULL;
					ultimo = anterior;
					encontrado = true;
					break;
				}
				else if (actual->dato == dato) {
					anterior->siguiente = actual->siguiente;
					encontrado = true;
					break;
				}
				anterior = actual;
				actual = actual->siguiente;
			}
		}
		if (encontrado) {
			cout << "Se ha eliminado la capa " << dato << " exitosamente" << endl;
		}
		else {
			cout << "La capa " << dato << " no existe" << endl;
		}
	}
	else {
		cout << "La lista no tiene ninguna capa" << endl;
	}
}

void Lista_Simple::buscar_dim_mayores(Nodo_ABB *&capa) {
	if (capa->colMax > colMax) {
		colMax = capa->colMax;
	}
	if (capa->filMax > filaMax) {
		filaMax = capa->filMax;
	}
}

void Lista_Simple::graficar() {
	string grafica = "";
	ofstream archivo;
	archivo.open("Lista_simple.dot");
	archivo << "digraph {\n rankdir=TB;\n";
	grafica = recorrer(primero);
	archivo << grafica;
	archivo << "}\n";
	archivo.close();

	system("dot -Tpng Lista_simple.dot -o Lista_simple.png -Gcharset=latin1");
	system("Lista_simple.png");
}

string Lista_Simple::recorrer(Nodo_Lista *raiz) {
	string graf = "";
	Nodo_Lista *actual = raiz;
	if (raiz != NULL) {
		if(actual->siguiente != NULL){
			graf += "\tNodeCapa_" + cadena(actual->dato) + "->" + "NodeCapa_" + cadena(actual->siguiente->dato) + "[constraint=false]; \n";	
		} 
		graf += "\tNodeCapa_" + cadena(actual->dato) + "[shape=box,style=filled,color=chartreuse1  , label = \"Capa_" + cadena(actual->dato) + " \"] \n";
		graf += recorrer(actual->siguiente);
	}
	return graf;
}

string Lista_Simple::recorrer2(int no,Nodo_Lista *raiz) {
	string graf = "";
	Nodo_Lista *actual = raiz;
	if (raiz != NULL) {
		if (actual->siguiente != NULL) {
			graf += "\tNodeCapa_" + cadena(actual->dato) + "_" + cadena(no) + "->" + "NodeCapa_" + cadena(actual->siguiente->dato) + "_" + cadena(no) + "; \n";
		}
		graf += "\tNodeCapa_" + cadena(actual->dato) + "_" + cadena(no) + "[shape=box,style=filled,color=chartreuse1  , label = \"Capa_" + cadena(actual->dato) + " \"] \n";
		graf += recorrer2(no,actual->siguiente);
	}
	return graf;
}

string Lista_Simple::recorrer3(int no, Nodo_Lista *raiz) {
	string graf = "";
	Nodo_Lista *actual = raiz;
	if (raiz != NULL) {
		if (actual->siguiente != NULL) {
			graf += "\tNodeCapa_" + cadena(actual->dato) + "_" + cadena(no) + "->" + "NodeCapa_" + cadena(actual->siguiente->dato) + "_" + cadena(no) + "[constraint=true]; \n";
		}
		graf += "\tNodeCapa_" + cadena(actual->dato) + "_" + cadena(no) + "->" + "Node" + cadena(actual->dato) + ":C3" + "[style=dotted]; \n";
		graf += "\tNodeCapa_" + cadena(actual->dato) + "_" + cadena(no) + "[shape=box,style=filled,color=chartreuse1  , label = \"Capa_" + cadena(actual->dato) + " \"] \n";
		graf += recorrer3(no, actual->siguiente);
	}
	return graf;
}


string Lista_Simple::cadena(int n) {
	stringstream flujo;
	flujo << n;
	return(flujo.str());
}