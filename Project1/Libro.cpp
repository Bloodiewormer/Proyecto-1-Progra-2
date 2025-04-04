#include "Libro.h"

Libro::Libro(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string cantidad, std::string tipoMaterial, std::string estado, std::string isbn, std::string editorial)
	: MaterialFisico(identificador, titulo, palabrasClave, autores, cantidad, tipoMaterial, estado), isbn(isbn), editorial(editorial)
{
	// Constructor
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
	for (int i = 0; i < autores.getLength(); i++)
	{
		oss << "Autor: " << autores.get(i) << std::endl;
	}
	oss << "Palabras Clave: " << std::endl;
	for (int i = 0; i < palabrasClave.getLength(); i++)
	{
		oss << "Palabra Clave: " << palabrasClave.get(i) << std::endl;
	}
	oss << "Tipo de Material: " << tipoMaterial << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "ISBN: " << isbn << std::endl;
	oss << "Editorial: " << editorial << std::endl;
	oss << "====================" << std::endl;
	return oss.str();

}