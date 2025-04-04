#include "MaterialFisico.h"

MaterialFisico::MaterialFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string cantidad, std::string tipoMaterial, std::string estado)
: Material(identificador, titulo, palabrasClave, autores), cantidad(cantidad), tipoMaterial(tipoMaterial), estado(estado)
{
}

MaterialFisico::~MaterialFisico()
{
	// Destructor
}
