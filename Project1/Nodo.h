#pragma once
template <class T>
class Nodo {
private:
	Nodo* siguiente;  // Puntero al siguiente nodo
	T* elemento;      // Puntero al objeto que "almacena"
public:
	Nodo(Nodo<T>* sig, T* ele) { 
		siguiente = sig;
		elemento = ele;
	};
	Nodo(T* ele) {
		elemento = ele;
		siguiente = nullptr;
	};
	virtual ~Nodo() {
	
	};
	Nodo<T>* obtenerSiguiente() {
		return siguiente;
	};
	T* obtenerElemento() {
		return elemento;
	};
	void setElemento(T*) {
		elemento = ele;
	};
	void setSiguiente(Nodo<T>*) {
		siguiente = sig;
	};
};