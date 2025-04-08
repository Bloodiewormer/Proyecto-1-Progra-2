#include "ArticuloDigital.h"





ArticuloDigital::ArticuloDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, double tamano, int dias, std::string TipoArticulo)
	:MaterialDigital(identificador, titulo, palabrasClave, autores, tipoArchivo, tamano, dias), TipoArticulo(TipoArticulo) 
{
	// Constructor
	this->TipoArticulo = TipoArticulo;
}

ArticuloDigital::~ArticuloDigital()
{
	// Destructor
}

std::string ArticuloDigital::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Tipo Articulo: " << TipoArticulo << std::endl;
	oss << "Articulo Digital: " << std::endl;
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
	oss << "Tipo Archivo: " << tipo << std::endl;
	oss << "Tamano: " << tamano << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}