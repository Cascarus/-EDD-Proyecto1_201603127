#include "Binario.h"

Nodo_ABB *nuevoNod(int dato) {
	Nodo_ABB *temp = new Nodo_ABB();
	temp->id = dato;
	temp->izquierda = temp->derecha = NULL;
	temp->principal = temp->columnas = temp->filas = NULL;
	return temp;
}

bool Binario::existeB(Nodo_ABB *raiz, int dato) {
	
	if (raiz == NULL) {
		return false;
	}

	if (raiz->id == dato) {
		return true;
	} else {
		if (dato < raiz->id) {
			return existeB(raiz->izquierda, dato);
		}
		else {
			return existeB(raiz->derecha, dato);
		}
	}
}

bool Binario::existe(int dato) {
	return existeB(raiz, dato);
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
	if (!existe(dato)) {
		raiz = insertar(raiz, dato);
		no_Nodos++;
	}
	else {
		cout << "El dato ya existe" << endl;
	}
	
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
		raiz->principal = temp->principal;
		raiz->filas = temp->filas;
		raiz->columnas = temp->columnas;
		raiz->izquierda = eliminar(raiz->izquierda, temp->id);
	}

		return raiz;
}

void Binario::elim(int dato) {
	if (existe(dato)) {
		raiz = eliminar(raiz, dato);
		no_Nodos--;
	} else {
		cout << "El dato " << dato << " no existe" << endl;
	}
}

Nodo_ABB *Binario::buscarNodo(Nodo_ABB *raiz, int dato) {
	if (raiz == NULL) {
		return NULL;
	}

	if (raiz->id == dato) {
		return raiz;
	}
	else {
		if (dato < raiz->id) {
			return buscarNodo(raiz->izquierda, dato);
		}
		else {
			return buscarNodo(raiz->derecha, dato);
		}
	}
}

Nodo_ABB *Binario::busNodo(int dato) {
	if (existe(dato)) {
		return buscarNodo(raiz, dato);
	}
	return NULL;
}

Nodo_ABB *Binario::ModNodo(Nodo_ABB *raiz,  int dato, Nodo_ABB *matriz) {
	
	if (raiz->id == dato) {
		raiz->principal = matriz->principal;
		raiz->columnas = matriz->columnas;
		raiz->filas = matriz->filas;
		raiz->contenido = matriz->contenido;
		return raiz;
	}
	else {
		if (dato < raiz->id) {
			raiz-> izquierda = ModNodo(raiz->izquierda, dato, matriz);
		}
		else {
			raiz->derecha = ModNodo(raiz->derecha, dato, matriz);
		}
	}
	return raiz;
}

void Binario::modificar(int dato, Nodo_ABB *matriz) {
	if (existe(dato)){
		raiz = ModNodo(raiz, dato, matriz);
	}
}

//Crear Arbol espejo usando un segundo nodo para graficarlo cuando se pida
void Binario::Espejo(Nodo_ABB *raiz_E) {
	if (raiz_E == NULL)
		return;
	else
	{
		Nodo_ABB *temp;

		Espejo(raiz_E->izquierda);
		Espejo(raiz_E->derecha);

		temp = raiz_E->izquierda;
		raiz_E->izquierda = raiz_E->derecha;
		raiz_E->derecha = temp;
	}
}

void Binario::graficar() {

	grafica = "";

	ofstream arch;

	arch.open("ABB.dot");
	arch << "digraph g{" << endl;
	arch << "\tnode [shape=record,width=.9,height=.5,style=filled,fillcolor=orangered2];\n";

	grafica = recorrer(raiz);

	arch << grafica;
	arch << "}" << endl;
	arch.close();
	system("dot -Tpng ABB.dot -o ABB.png");
	system("ABB.png");
}

//Crea la grafica del arbol espejo
void Binario::graficar_Espejo() {

	grafica = "";
	//crea una "copia" de la raiz en el espejo para que no altere la raiz principal
	raiz_Espejo = raiz;
	Espejo(raiz_Espejo); //ejecuta el metodo de espejo que cambia las direcciones de los punteros

	ofstream arch;

	arch.open("ABB_Espejo.dot");
	arch << "digraph g{" << endl;
	arch << "\tnode [shape=record,width=.9,height=.5,style=filled,fillcolor=orangered2];\n";
	grafica = recorrer(raiz);
	arch << grafica;
	arch << "}" << endl;
	arch.close();
	system("dot -Tpng ABB_Espejo.dot -o ABB_Espejo.png");
	system("ABB_Espejo.png");
	Espejo(raiz_Espejo);
}

string Binario::recorrer(Nodo_ABB *inicio) {
	if (inicio != NULL) {

		if (inicio->izquierda != NULL) {
			grafica += "\tNode" + cadena(inicio->id) + ":C0->" + "Node" + cadena(inicio->izquierda->id) + "; \n";
		}
		if (inicio->derecha != NULL) {
			grafica += "\tNode" + cadena(inicio->id) + ":C1->" + "Node" + cadena(inicio->derecha->id) + "; \n";
		}

		recorrer(inicio->izquierda);
		recorrer(inicio->derecha);
		grafica += "\n \tNode" + cadena(inicio->id) + "[label = \"<C0>|Capa_" + cadena(inicio->id) + "|<C1>\"] \n";
	}
	return grafica;
}

void Binario::PreOrden(Nodo_ABB *raiz) {
	if (raiz!= NULL) {
		//cout << raiz->id << " ";
		preOrd += cadena(raiz->id) + " ";

		PreOrden(raiz->izquierda);
		PreOrden(raiz->derecha);
	}
}

void Binario::InOrden(Nodo_ABB *raiz) {
	if (raiz != NULL) {
		InOrden(raiz->izquierda);
		
		//cout << raiz->id << " ";
		inOrd += cadena(raiz->id) + " ";

		InOrden(raiz->derecha);
	}
}

void Binario::PostOrden(Nodo_ABB *raiz) {
	if (raiz != NULL) {
		PostOrden(raiz->izquierda);
		PostOrden(raiz->derecha);

		//cout << raiz->id << " ";
		posOrd += cadena(raiz->id) + " ";
	}
}

string Binario::cadena(int n) {
	stringstream flujo;
	flujo << n;
	return(flujo.str());
}