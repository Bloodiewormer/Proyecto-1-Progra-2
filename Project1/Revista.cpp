#include "Revista.h"

Revista::Revista(std::string identificador, std::string cantidad, std::string titulo, std::string autor, std::string palabrasClave, std::string tipoMaterial, std::string estado, std::string volumen, std::string numero)
{
	this->identificador = identificador;
	this->cantidad = cantidad;
	this->titulo = titulo;
	this->autor = autor;
	this->palabrasClave = palabrasClave;
	this->tipoMaterial = tipoMaterial;
	this->estado = estado;
	this->volumen = volumen;
	this->numero = numero;

}

Revista::~Revista()
{
	// Destructor
}

std::string Revista::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Revista: " << std::endl;
	oss << "Identificador: " << identificador << std::endl;
	oss << "Cantidad: " << cantidad << std::endl;
	oss << "Titulo: " << titulo << std::endl;
	oss << "Autor: " << autor << std::endl;
	oss << "Palabras Clave: " << palabrasClave << std::endl;
	oss << "Tipo de Material: " << tipoMaterial << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "Volumen: " << volumen << std::endl;
	oss << "Numero: " << numero << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}