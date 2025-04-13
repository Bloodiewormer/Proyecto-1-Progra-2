#pragma once
#include <iostream>
#include "Nodo.h"
#include <sstream>
#include "CustomException.h"
template <class T>
class Lista {
private:
	Nodo<T>* first;
	int length;
public:
	Lista() {
		first = nullptr;
		length = 0;
	}

	~Lista() {

	}

	int getLength() const {
		return length;
	}

	bool isEmpty() const {
		return first == nullptr;
	}

	void addBegin(T* data) {
		Nodo<T>* aux = new Nodo<T>(data);
		if (data == nullptr) {
			throw InvalidInputException("Data cannot be null");
		}
		if (!isEmpty()) {
			aux->setNext(first);
			first = aux;
			length++;
		}
		else{
			first = aux;
			length++;
		}
	}

	T* get(int index) const {
		Nodo<T>* aux = first;
		if (index >= length) {
			throw IndexOutOfBoundsException("Index out of bounds");
		}
		if (index == 0) {
			return aux->getData(); 
		}
		for (int idx = 0; idx < index; idx++) {
			aux = aux->getNext();
		}
		return aux->getData();
	}

	void remove(T* data) {
		if (first == nullptr) {
			return;
		}
		if (first->getData() == data) {
			Nodo<T>* aux = first;
			first = first->getNext();
			delete aux;
			length--;
			return;
		}
		Nodo<T>* aux = first;
		while (aux->getNext() != nullptr) {
			if (aux->getNext()->getData() == data) {
				Nodo<T>* aux2 = aux->getNext();
				aux->setNext(aux2->getNext());
				delete aux2;
				length--;
				return;
			}
			aux = aux->getNext();
		}
	}

	void remove(int index) {
		if (first == nullptr) {
			return;
		}
		if (index >= length) {
			throw IndexOutOfBoundsException("Index out of bounds");
		}
		if (index == 0) {
			Nodo<T>* aux = first;
			first = first->getNext();
			delete aux;
			length--;
			return;
		}
		Nodo<T>* aux = first;
		for (int idx = 0; idx < index - 1; idx++) {
			aux = aux->getNext();
		}
		Nodo<T>* aux2 = aux->getNext();
		aux->setNext(aux2->getNext());
		delete aux2;
		length--;
	}

	int getLength() {
		return length;
	}

	bool contains(T* data) {
		Nodo<T>* aux = first;
		while (aux != nullptr) {
			if (aux->getData() == data) {
				return true;
			}
			aux = aux->getNext();
		}
		return false;
	}

	std::string toString() const {
		std::ostringstream s;
		Nodo<T>* aux = first;
		while (aux != nullptr) {
			s << *aux->getData() << std::endl; //aqui se usa la sobrecarga de operador << si la clase no tiene la sobrecarga de operador << se mostra el puntero
			aux = aux->getNext();
		}
		return s.str();
	}
};

//funny
// with this  you can acces a tostring method in string XD

//class string :public std::string {
//public:
//	string(std::string str) : std::string(str) {}
//	string() : std::string() {}
//	~string() {}
//	std::string toString() {
//		return *this;
//	}
//};

