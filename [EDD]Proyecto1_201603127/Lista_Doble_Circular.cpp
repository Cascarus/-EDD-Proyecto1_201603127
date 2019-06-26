#include "Lista_Doble_Circular.h"

void Lista_Doble_Circular::insertarNuevo(int dato, Nodo_Lista *&lista) {
	Nodo_c *nuevo = new Nodo_c();
	nuevo->id = dato;
	nuevo->primero_lista = lista;

	if (primero == NULL) {
		primero = nuevo;
		ultimo = nuevo;
		primero->Siguiente = primero;
		nuevo->Anterior = ultimo;

	}
	else if (dato < primero->id) {
		nuevo->Siguiente = primero;
		nuevo->Anterior = ultimo;
		primero->Anterior = nuevo;
		ultimo->Siguiente = nuevo;
		primero = nuevo;
	}
	else if (dato >= ultimo->id) {
		ultimo->Siguiente = nuevo;
		nuevo->Anterior = ultimo;
		ultimo = nuevo;
		ultimo->Siguiente = primero;
		primero->Anterior = ultimo;
	}
	else {
		Nodo_c *temp = primero;

		do {
			if (temp->Siguiente->id > dato) {
				nuevo->Siguiente = temp->Siguiente;
				temp->Siguiente = nuevo;
				nuevo->Siguiente->Anterior = nuevo;
				nuevo->Anterior = temp;
				break;
			}
			else if (temp->Siguiente->id == dato) {
				nuevo->Siguiente = temp->Siguiente->Siguiente;
				temp->Siguiente->Siguiente = nuevo;
				nuevo->Anterior = temp->Siguiente;
				nuevo->Siguiente->Anterior = nuevo;
				break;
			}
			else {
				temp = temp->Siguiente;
			}
		} while (temp != ultimo);
	}
}

void Lista_Doble_Circular::mostrar() {
	Nodo_c *actual = new Nodo_c();
	actual = primero;

	do {
		//System.out.println(actual.principal.terreno);
		cout << actual->id<<endl;
		actual = actual->Siguiente;
	} while (actual != primero);
}

Nodo_c *Lista_Doble_Circular::buscarNodo(int dato) {
	Nodo_c *actual = new Nodo_c();
	actual = primero;
	bool encontrado = false;
	do {
		if (actual->id == dato) {
			encontrado = true;
			//System.out.println("Se encontro el Nodo: " + dato);
			cout << "Se encontro el Nodo: " << dato << endl;
			break;

		}
		actual = actual->Siguiente;
	} while (actual != primero);
	if (encontrado) {
		return actual;
	}
	return NULL;
}


/* con este metodo tengo que crear un nodo del mismo tipo antes de meter las capas
	luego de haber creado el nodo, creo la lista de capas y le paso al nodo el primero 
	de esa lista de capas y por ultimo ya mando a modificar el nodo para que tengas todas las 
	capas que requiere esa imagen
*/
void Lista_Doble_Circular::ModNodo(int dato, Nodo_c *matri) {
	Nodo_c *actual = new Nodo_c();
	actual = primero;
	bool encontrado = false;
	do {
		if (actual->id == dato) {
			encontrado = true;
			//System.out.println("Se encontro el Nodo: " + dato);
			cout << "Se encontro el Nodo: " << dato << endl;
			actual = matri;
			//actual->principal = matri.principal;
			//actual.columnas = matri.columnas;
			//actual.filas = matri.filas;

			break;

		}
		actual = actual->Siguiente;
	} while (actual != primero);
}

void Lista_Doble_Circular::eliminar(int x) {

	if (primero != NULL) {
		if (primero == ultimo) {
			if (x == primero->id) {
				primero = NULL;
				ultimo = NULL;
			}
			else {
				//System.out.println("Nodo no existe");
				cout << "Nodo no existe" << endl;
			}
		}
		else if (x == primero->id) {
			Nodo_c *temporal = primero;

			primero = primero->Siguiente;
			temporal->Siguiente->Anterior = temporal->Anterior;
			temporal->Anterior->Siguiente = temporal->Siguiente;
			temporal->Anterior = NULL;
			temporal->Siguiente = NULL;
			temporal = NULL;
			free(temporal);

		}
		else if (x == ultimo->id) {
			Nodo_c *temporal = ultimo;
			ultimo = ultimo->Anterior;
			temporal->Siguiente->Anterior = temporal->Anterior;
			temporal->Anterior->Siguiente = temporal->Siguiente;
			temporal->Anterior = NULL;
			temporal->Siguiente = NULL;
			temporal = NULL;
			free(temporal);
		}
		else {
			Nodo_c *temporal = primero;

			do {
				if (temporal->id == x) {
					temporal->Anterior->Siguiente = temporal->Siguiente;
					temporal->Siguiente->Anterior = temporal->Anterior;
					temporal->Siguiente = NULL;
					temporal->Anterior = NULL;
					break;
				}
				else {
					temporal = temporal->Siguiente;
				}
			} while (temporal != ultimo);

			if (temporal == ultimo) {
				//System.out.println("No existe el nodo");
				cout << "Nodo no existe" << endl;
			}
			else {
				//System.out.println("el nodo ha sido eliminado existosamente");
				cout << "el nodo ha sido eliminado existosamente" << endl;
			}
		}
	}
	else {
		//System.out.println("Ya no hay nada que eliminar");
		cout << "Ya no hay nada que eliminar" << endl;
	}
}

void Lista_Doble_Circular::graf() {

		relaciones = "";
		labels = "";
		listas = "";
		ranks = "";

		ofstream arch;
		arch.open("Circular_doble.dot");
		arch << "digraph G {" << endl;
		arch << "\tnode [shape=record,width=.9,height=.5];" << endl;
		recorrer(primero);
		arch << relaciones;
		arch << labels;
		arch << "// empiezan las relaciones de listas con las imagenes" << endl;
		arch << listas;
		arch << ranks;
		arch << "}" << endl;
		arch.close();
		system("dot -Tpng Circular_doble.dot -o Circular_Doble.png -Gcharset=latin1");
		system("Circular_Doble.png");
}

void Lista_Doble_Circular::recorrer(Nodo_c *primero) {
	Nodo_c *current = primero;
	if (current != NULL) {
		ranks = "{ rank = same; Node" + cadena(current->id);
		do {
			relaciones += "\tNode" + cadena(current->id) + "->" + "Node" + cadena(current->Siguiente->id) + "; \n";
			relaciones += "\tNode" + cadena(current->id) + "->" + "Node" + cadena(current->Siguiente->id) + "[dir=back]; \n";

			if (current->primero_lista != NULL) {
				relaciones += "\tNode" + cadena(current->id) + "->" + "NodeCapa_" + cadena(current->primero_lista->dato) + "_" + cadena(current->id) + "; \n";
				Lista_Simple lista = new Lista_Simple(true);
				listas += lista.recorrer2(current->id, current->primero_lista);
			}

			labels += "\n \tNode" + cadena(current->id) + "[label = \"imagen_" + cadena(current->id) + "\"] \n";
			ranks += ",Node" + cadena(current->id);
			current = current->Siguiente;
		} while (current != primero);
		ranks += "};\n";
	}

}

string Lista_Doble_Circular::recorrer2(Nodo_c *&primero, string nick) {
	Nodo_c *current = primero;
	relaciones = "";
	labels = "";
	string todo = "";

	if (current != NULL) {
		do {
			if (current->Siguiente != primero) {
				relaciones += "\tNode_" + nick + "_" + cadena(current->id) + "->" + "Node_" + nick + "_" + cadena(current->Siguiente->id) + "; \n";
			}
			labels += "\n \tNode_" + nick + "_" + cadena(current->id) + "[shape=record,width=.9,height=.5,label = \"imagen_" + cadena(current->id) + "\"] \n";
			current = current->Siguiente;
		} while (current != primero);
	}
	todo = relaciones + labels;
	return todo;
}

void Lista_Doble_Circular::crear_IMG(Nodo_c *nodo) {
	Matriz imagen_completa = new Matriz(true);
	Nodo_Lista *temporal = nodo->primero_lista;
	string contenido, linea;
	
	if (temporal != NULL) {

		for (int fil = 0; fil <= nodo->filMax; fil++) {
			for (int col = 0; col <= nodo->colMax; col++) {
				imagen_completa.Insertar(nodo->id, fil + 1, col + 1, "#FFFFFF");
			}
		}

		while (temporal != NULL)
		{
			contenido = temporal->capa->contenido;
			splitear_Capas(contenido, imagen_completa, nodo->id);
			temporal = temporal->siguiente;
		}
	}

	imagen_completa.graficar2(nodo->id, imagen_completa.Cprincipal);
}

void Lista_Doble_Circular::splitear_Capas(string str, Matriz imagen_completa, int id) {
	string palabra = "";
	bool encontradoF, encontradoC;
	int fila, columna;
	string color;

	for (auto x : str) {
		if (x == '{') {
			encontradoC = false;
			encontradoF = false;
			palabra = "";
		} else if (x == ',') {

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
		} else if (x == ';') {
			color = palabra;
			imagen_completa.Insertar(id, fila, columna, color);
			encontradoC = false;
			encontradoF = false;
			palabra = "";
		} else if (x == '}') {
			fila = 0;
			columna = 0;
			encontradoC = false;
			encontradoF = false;
		} else if (x == '\n') {
			palabra = "";
		} else {
			palabra += x;
		}
	}
}

string Lista_Doble_Circular::cadena(int n) {
	stringstream flujo;
	flujo << n;
	return(flujo.str());
}