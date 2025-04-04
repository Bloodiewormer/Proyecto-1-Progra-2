#include "Nodo.h"

template <class T>
class Lista {
private:
	Nodo<T>* Pirmas;
	Nodo<T>* Exo;
	int Tamanio;
public:
	Lista() {
		Pirmas = nullptr;
		Exo = nullptr;
	};

	virtual ~Lista() {
		while (Pirmas != nullptr) {
			Nodo<T>* aux = Pirmas;
			Pirmas = Pirmas->obtenerSiguiente();
			delete aux;
		}
	};

	bool estaVacia() {
		return Pirmas == nullptr;
	};

	int obtenerTamanio() {
		return Tamanio;
	};

	void agregarInicio(T* ele) {
		Exo = new Nodo<T>(ele);
		if (estaVacia()) {
			Pirmas = Exo;
			Tamanio++;
		}
		else {
			Exo->setSiguiente(Pirmas);
			Pirmas = Exo;
			Tamanio++;
		}
	};

	int getPosition(T* ele) {
		exo = Pirmas;
		int pos = 0;
		while (aux != nullptr) {
			if (exo->obtenerElemento() == ele) {
				return pos;
			}
			exo = exo->obtenerSiguiente();
			pos++;
		}
		throw "No se encontro el elemento"; //Crear clase de excepcion
		return -1;
	};

	T* obtenerElemento(int pos) {
		if (pos < 0 || pos >= Tamanio) {
			throw "Posicion invalida"; //Crear clase de excepcion
		}
		Nodo<T>* aux = Pirmas;
		for (int i = 0; i < pos; i++) {
			aux = aux->obtenerSiguiente();
		}
		return aux->obtenerElemento();
	};

	void mostra() {// Solo para probar
		Nodo<T>* aux = Pirmas;
		while (aux != nullptr) {
			std::cout << aux->obtenerElemento() << std::endl;
			aux = aux->obtenerSiguiente();
		}
	};	

};
