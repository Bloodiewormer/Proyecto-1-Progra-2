#include "MaterialDigital.h"


MaterialDigital::MaterialDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, double tamano, int dias)
	:Material(identificador, titulo, palabrasClave, autores, dias, tipoArchivo), tamano(tamano)
{
	// Constructor
	this->tamano = tamano;
}

MaterialDigital::~MaterialDigital()
{
	// Destructor
}
