#include "MaterialDigital.h"

MaterialDigital::MaterialDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, std::string tamano)
: Material(identificador, titulo, palabrasClave, autores), tipoArchivo(tipoArchivo), tamano(tamano)
{
}

MaterialDigital::~MaterialDigital()
{
	// Destructor
}
