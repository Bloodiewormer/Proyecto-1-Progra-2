#include "Material.h"



Material::Material(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, int diasPrestamo, std::string tipo)
	:identificador(identificador), titulo(titulo), palabrasClave(palabrasClave), autores(autores), diasPrestamo(diasPrestamo), tipo(tipo)
{
	// Constructor
	this->identificador = identificador;
	this->titulo = titulo;
	this->palabrasClave = palabrasClave;
	this->autores = autores;
	this->diasPrestamo = diasPrestamo;
	this->tipo = tipo;
}

Material::~Material()
{
}

std::string Material::getIdentificador() const
{
	return identificador;
}


