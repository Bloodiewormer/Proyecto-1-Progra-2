#include "Libro.h"

Libro::Libro(std::string identificador, std::string cantidad, std::string titulo, std::string autor, std::string palabrasClave, std::string tipoMaterial, std::string estado, std::string isbn, std::string editorial): Material(identificador, cantidad, titulo, autor, palabrasClave, tipoMaterial, estado) { 
	this->isbn = isbn;
	this->editorial = editorial;
}

Libro::~Libro() {
	// Destructor
}

std::string Libro::toString() const {
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Libro: " << std::endl;
	oss << "Identificador: " << identificador << std::endl;
	oss << "Cantidad: " << cantidad << std::endl;
	oss << "Titulo: " << titulo << std::endl;
	oss << "Autor: " << autor << std::endl;
	oss << "Palabras Clave: " << palabrasClave << std::endl;
	oss << "Tipo de Material: " << tipoMaterial << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "ISBN: " << isbn << std::endl;
	oss << "Editorial: " << editorial << std::endl;
	oss << "====================" << std::endl;
	return oss.str();

}