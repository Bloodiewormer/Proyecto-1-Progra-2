#include "MaterialFisico.h"




MaterialFisico::MaterialFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoMaterial, std::string estado, int dias)
	:Material(identificador, titulo, palabrasClave, autores, dias, tipoMaterial), estado(estado)
{
	// Constructor
	this->estado = estado;
}



MaterialFisico::~MaterialFisico()
{
	// Destructor
}
