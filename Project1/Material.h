#pragma once
#include <iostream>
#include <sstream>
#include "Lista.h"
class Material{
protected:
	std::string identificador; //Este es el identificador unico de la biblioteca, todos los demas datos se pueden repetir
	std::string titulo;
	Lista<std::string> palabrasClave; //Lista de palabras clave
	Lista<std::string> autores; //Lista de autores 
public:
	Material(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores);
	~Material();
	virtual std::string toString() const = 0;
};
	

