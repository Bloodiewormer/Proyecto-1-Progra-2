#include "ArticuloFisico.h"





ArticuloFisico::ArticuloFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoMaterial, std::string estado, int dias, std::string tipoArticulo)
	:MaterialFisico(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, dias), tipoArticulo(tipoArticulo)
{
	// Constructor
	this->tipoArticulo = tipoArticulo;
}

ArticuloFisico::~ArticuloFisico()
{
	// Destructor
}

std::string ArticuloFisico::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Articulo Fisico: " << std::endl;
	oss << "Tipo Articulo: " << tipoArticulo << std::endl;
	oss << "Identificador: " << identificador << std::endl;
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
	oss << "Tipo de Material: " << tipo << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}

std::string ArticuloFisico::getTipo(){ return "Articulo Fisico"; }
