#include "Binario.h"

Nodo_ABB *nuevoNod(int dato) {
	Nodo_ABB *temp = new Nodo_ABB();
	temp->id = dato;
	temp->izquierda = temp->derecha = NULL;
	temp->principal = temp->columnas = temp->filas = NULL;
	return temp;
}

Nodo_ABB *Binario::insertar(Nodo_ABB *raiz,int dato) {

	if (raiz == NULL) {
		return nuevoNod(dato);
	}

	if (dato < raiz->id) {
		raiz->izquierda = insertar(raiz->izquierda, dato);
	} else {
		raiz->derecha = insertar(raiz->derecha, dato);
	}
	return raiz;
}

void Binario::add(int dato) {
	raiz = insertar(raiz,dato);
}

Nodo_ABB *minValue(Nodo_ABB *nodo)
{
	Nodo_ABB *current = nodo;

	while (current && current->derecha != NULL)
		current = current->derecha;

	return current;
}

Nodo_ABB *Binario::eliminar(Nodo_ABB *raiz, int dato) {

	if (raiz == NULL) {
		return raiz;
	}

	if (raiz->id > dato) {
		raiz->izquierda = eliminar(raiz->izquierda, dato);
		return raiz;
	} else if(raiz->id < dato) {
		raiz->derecha = eliminar(raiz->derecha, dato);
		return raiz;
	}
	else {
		if (raiz->izquierda == NULL) {
			Nodo_ABB *temp = raiz->derecha;
			free(raiz);
			return temp;

		}
		else if (raiz->derecha == NULL) {
			Nodo_ABB *temp = raiz->izquierda;
			free(raiz);
			return temp;
		}

		Nodo_ABB *temp = minValue(raiz->izquierda);
		raiz->id = temp->id;
		raiz->izquierda = eliminar(raiz->izquierda, temp->id);
	}

		return raiz;
}

void Binario::elim(int dato) {
	raiz = eliminar(raiz, dato);
}

void Binario::graficar() {

	grafica = "";

	ofstream arch;

	arch.open("ABB.dot");
	arch << "digraph g{" << endl;
	arch << "\tnode [shape=record,width=.9,height=.5,style=filled,color=orangered2];\n";

	grafica = recorrer(raiz);

	arch << grafica;
	arch << "}" << endl;
	arch.close();
	system("dot -Tpng ABB.dot -o ABB.png");
	system("ABB.png");
}

string Binario::recorrer(Nodo_ABB *inicio) {
	if (inicio != NULL) {
		if (inicio->izquierda != NULL) {
			grafica += "\tNode" + cadena(inicio->id) + "->" + "Node" + cadena(inicio->izquierda->id) + "; \n";
		}
		if (inicio->derecha != NULL) {
			grafica += "\tNode" + cadena(inicio->id) + "->" + "Node" + cadena(inicio->derecha->id) + "; \n";
		}
		/*if (inicio.inicio != null) {
		Lista_Simple lista = new Lista_Simple();
		grafica += "\tNode" + inicio.hashCode() + "->" + "Node" + inicio.inicio.hashCode() + "[style=dotted]; \n";
		grafica += lista.recorre(inicio.inicio);
		}*/
		recorrer(inicio->izquierda);
		recorrer(inicio->derecha);
		grafica += "\n \tNode" + cadena(inicio->id) + "[label = \"Capa_" + cadena(inicio->id) + "\"] \n";
	}
	return grafica;
}

string Binario::cadena(int n) {
	stringstream flujo;
	flujo << n;
	return(flujo.str());
}