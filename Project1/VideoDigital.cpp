#include "VideoDigital.h"

VideoDigital::VideoDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, std::string tamano, std::string duracion, std::string resolucion)
	: MaterialDigital(identificador, titulo, palabrasClave, autores, tipoArchivo, tamano), duracion(duracion), resolucion(resolucion)
{
	// Constructor
}

VideoDigital::~VideoDigital()
{
	// Destructor
}

std::string VideoDigital::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Video Digital: " << std::endl;
	oss << "Identificador: " << identificador << std::endl;
	oss << "Titulo: " << titulo << std::endl;
	oss << "Autores: " << std::endl;
	for (int i = 0; i < autores.getLength(); i++)
	{
		oss << "Autor: " << autores.get(i) << std::endl;
	}
	oss << "Palabras Clave: " << std::endl;
	for (int i = 0; i < palabrasClave.getLength(); i++)
	{
		oss << "Palabra Clave: " << palabrasClave.get(i) << std::endl;
	}
	oss << "Tipo de Archivo: " << tipoArchivo << std::endl;
	oss << "Tamano: " << tamano << std::endl;
	oss << "Duracion: " << duracion << std::endl;
	oss << "Resolucion: " << resolucion << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}
