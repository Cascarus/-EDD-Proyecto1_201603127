#include "AVL.h"

AVL::AVL(bool a)
{
}

int AVL::altura(Nodo_Arbol *N) {
	//Nodo_Arbol *temp = N;
	if (N == NULL)
		return 0;
	return N->altura;
}

int AVL::maxi(int a, int b) {
	return (a > b) ? a : b;
}

Nodo_Arbol* AVL::newNode(string key)
{
	Nodo_Arbol* node = new Nodo_Arbol();
	node->nick = key;
	node->izquierda = NULL;
	node->derecha = NULL;
	node->altura = 1; 

	return(node);
}

Nodo_Arbol *AVL::RotarDer(Nodo_Arbol *y) {
	Nodo_Arbol *x = y->izquierda;
	Nodo_Arbol *T2 = x->derecha;

	x->derecha = y;
	y->izquierda = T2;

	y->altura = maxi(altura(y->izquierda), altura(y->derecha)) + 1;
	x->altura = maxi(altura(x->izquierda), altura(x->derecha)) + 1;

	return x;
}

Nodo_Arbol *AVL::RotarIzq(Nodo_Arbol *x) {
	Nodo_Arbol *y = x->derecha;
	Nodo_Arbol *T2 = y->izquierda;

	y->izquierda = x;
	x->derecha = T2;

	x->altura = maxi(altura(x->izquierda), altura(x->derecha)) + 1;
	y->altura = maxi(altura(y->izquierda), altura(y->derecha)) + 1;

	return y;
}

int AVL::getBalance(Nodo_Arbol *N) {
	if (N == NULL) {
		return 0;
	}
	else {
		return (altura(N->izquierda) - altura(N->derecha));
	}
}

Nodo_Arbol *AVL::insertar(Nodo_Arbol *N, string nick) {
	Nodo_Arbol *Nodo = new Nodo_Arbol();
	Nodo->altura = 1;
	Nodo->nick = nick;
	//Nodo->inicio = NULL;

	if (N == NULL) {
		return newNode(nick);
	}

	if (nick.compare(N->nick) < 0) {
		N->izquierda = insertar(N->izquierda, nick);
	}
	else if (nick.compare(N->nick) > 0) {
		N->derecha = insertar(N->derecha, nick);
	}
	else {
		return N;
	}

	N->altura = 1 + maxi(altura(N->izquierda), altura(N->derecha));
	int balance = getBalance(N);

	if (balance > 1 && nick.compare(N->izquierda->nick) < 0) {
		return RotarDer(N);
	}

	if (balance < -1 && nick.compare(N->derecha->nick) > 0) {
		return RotarIzq(N);
	}

	if (balance > 1 && nick.compare(N->izquierda->nick) > 0) {
		N->izquierda = RotarIzq(N->izquierda);
		return RotarDer(N);
	}

	if (balance < -1 && nick.compare(N->derecha->nick) < 0) {
		N->derecha = RotarDer(N->derecha);
		return RotarIzq(N);
	}

	return N;
}

void AVL::agregar(string nombre) {
	raiz = insertar(raiz, nombre);
}

Nodo_Arbol *AVL::mini(Nodo_Arbol *Nodo) {
	Nodo_Arbol *current = Nodo;

	while (current->derecha != NULL) {
		current = current->derecha;
	}
	return current;
}

Nodo_Arbol *AVL::eliminar(Nodo_Arbol *Raiz, string nombre) {
	if (Raiz == NULL) {
		return Raiz;
	}
	string data = Raiz->nick;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);

	if (nombre.compare(data) < 0) {
		Raiz->izquierda = eliminar(Raiz->izquierda, nombre);
	}
	else if (nombre.compare(data) > 0) {
		Raiz->derecha = eliminar(Raiz->derecha, nombre);
	}
	else {
		if ((Raiz->izquierda == NULL) || (Raiz->derecha == NULL)) {
			
			Nodo_Arbol *temp = Raiz->izquierda ?
							   Raiz->izquierda :
							   Raiz->derecha;

			if (temp == NULL) {
				temp = Raiz;
				Raiz = NULL;
			}
			else {
				*Raiz = *temp;
			}
			free(temp);
		}
		else {
			Nodo_Arbol *temp = mini(Raiz->izquierda);
			Raiz->nick = temp->nick;
			data = temp->nick;
			std::transform(data.begin(), data.end(), data.begin(), ::tolower);
			Raiz->izquierda = eliminar(Raiz->izquierda, data);
		}
	}

	if (Raiz == NULL) {
		return Raiz;
	}

	Raiz->altura = maxi(altura(Raiz->izquierda), altura(Raiz->derecha)) + 1;

	int balance = getBalance(Raiz);

	//Izq-Izq
	if (balance >1 && getBalance(Raiz->izquierda) >= 0) {
		return RotarDer(Raiz);
	}

	//Izq-Der
	if (balance > 1 && getBalance(Raiz->izquierda) < 0) {
		Raiz->izquierda = RotarIzq(Raiz->izquierda);
		return RotarDer(Raiz);
	}

	//Der-Der
	if (balance < -1 && getBalance(Raiz->derecha) <= 0) {
		return RotarIzq(Raiz);
	}

	//Der-Izq
	if (balance < -1 && getBalance(Raiz->derecha) > 0) {
		Raiz->derecha = RotarDer(Raiz->derecha);
		return RotarIzq(Raiz);
	}

	return Raiz;
}

void AVL::my_delete(string nombre) {
	string data = nombre;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	raiz = eliminar(raiz, data);
}

void AVL::update(string nombre, Lista_Doble_Circular actual) {
	string data = nombre;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	actualizar(raiz, data, actual);
}

void AVL::actualizar(Nodo_Arbol *current, string nick, Lista_Doble_Circular actual) {
	if (current != NULL) {
		string data = current->nick;
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
		if (data == nick) {
			current->primero = actual.primero;
			current->ultimo = actual.ultimo;
		}
		else {
			actualizar(current->izquierda, nick, actual);
			actualizar(current->derecha, nick, actual);
		}
	}
}

Nodo_Arbol *AVL::buscarNodo(string nick) {
	Nodo_Arbol *current = raiz;
	string data = nick;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	Nodo_Arbol *temp = buscarNod(raiz, data);

	if (temp != NULL) {
		cout<<"Se ha encontrado: " << temp->nick<<endl;
		return temp;
	}
	else {
		cout<<"No se ha encontrado: " << nick<<endl;
		return NULL;
	}

}

bool AVL::existe(string usuario) {
	string data = usuario;
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);

	Nodo_Arbol *temp = buscarNod(raiz, data);

	if (temp != NULL) {
		cout << "Se ha encontrado: " << temp->nick << endl;
		return true;
	}
	else {
		cout << "No se ha encontrado: " << usuario<<endl;
		return false;
	}
}

Nodo_Arbol *AVL::buscarNod(Nodo_Arbol *raiz, string nick) {
	if (raiz != NULL) {
		string data = raiz->nick;
		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
		if (nick.compare(data) == 0) {
			return raiz;
		}if (nick.compare(data) < 0) {
			return buscarNod(raiz->izquierda, nick);
		}
		else if (nick.compare(data) > 0) {
			return buscarNod(raiz->derecha, nick);
		}
	}else {
		return NULL;
	}
	return raiz;
}


void AVL::graficar() {

		grafica = "";

		ofstream arch;

		arch.open("Arbol_AVL.dot");
		arch<<"digraph g{"<<endl;
		//arch<<"\tnode [style=filled,color=orangered2];\n";

		recorrer(raiz);

		arch<<grafica;
		arch<<"}"<<endl;
		arch.close();
		system("dot -Tpng Arbol_AVL.dot -o Arbol_AVL.png");
		system("Arbol_AVL.png");
}

void AVL::recorrer(Nodo_Arbol *inicio) {
	if (inicio != NULL) {
		if (inicio->izquierda != NULL) {
			grafica += "\tNode" + cadena(inicio->hash) + ":C0->" + "Node" + cadena(inicio->izquierda->hash) + "; \n";
		}
		if (inicio->derecha != NULL) {
			grafica += "\tNode" + cadena(inicio->hash) + ":C1->" + "Node" + cadena(inicio->derecha->hash) + "; \n";
		}
		if (inicio->primero != NULL) {
			Lista_Doble_Circular lista = new Lista_Doble_Circular(true);
			grafica += "\tNode" + cadena(inicio->hash) + "->" + "Node_" + inicio->nick + "_" + cadena(inicio->primero->id) + "[style=dotted]; \n";
			grafica += lista.recorrer2(inicio->primero, inicio->nick);
		}
		recorrer(inicio->izquierda);
		recorrer(inicio->derecha);
		grafica += "\n \tNode" + cadena(inicio->hash) + "[shape=record,width=.9,height=.5,style=filled,fillcolor=orangered2,label = \"<C0>|Usuario: " + inicio->nick + "|<C1>\"] \n";
	}
}

string AVL::cadena(int n) {
	stringstream flujo;
	flujo << n;
	return(flujo.str());
}