#include "Lista_Simple.h"

void Lista_Simple::agregar(int dato) {
	Nodo_Lista *nuevo = new Nodo_Lista();
	nuevo->dato = dato;

	if (primero == NULL) {
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else {
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
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

string Lista_Simple::cadena(int n) {
	stringstream flujo;
	flujo << n;
	return(flujo.str());
}