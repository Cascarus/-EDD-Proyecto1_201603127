#include "Lista_Doble_Circular.h"

void Lista_Doble_Circular::insertarNuevo(int dato) {
	Nodo_c *nuevo = new Nodo_c();
	nuevo->id = dato;
	//nuevo.principal = principal;

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

void Lista_Doble_Circular::recorrer(Nodo_c *primero) {
	Nodo_c *current = primero;
	if (current != NULL) {
		do {
			relaciones += "\tNode" + cadena(current->id) + "->" + "Node" + cadena(current->Siguiente->id) + "; \n";
			relaciones += "\tNode" + cadena(current->id) + "->" + "Node" + cadena(current->Siguiente->id) + "[dir=back]; \n";
			labels += "\n \tNode" + cadena(current->id) + "[label = \"imagen_" + cadena(current->id) + "\"] \n";
			current = current->Siguiente;
		} while (current != primero);
	}

}

void Lista_Doble_Circular::graf() {

		relaciones = "";
		labels = "";

		ofstream arch;
		arch.open("Circular_doble.dot");
		arch << "digraph G {" << endl;
		arch << "\tnode [shape=record,width=.9,height=.5];" << endl;
		recorrer(primero);
		arch << relaciones;
		arch << labels;
		arch << "}" << endl;
		arch.close();
		system("dot -Tpng Circular_doble.dot -o Circular_Doble.png -Gcharset=latin1");
		system("Circular_Doble.png");
}

string Lista_Doble_Circular::cadena(int n) {
	stringstream flujo;
	flujo << n;
	return(flujo.str());
}

