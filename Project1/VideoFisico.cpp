#include "VideoFisico.h"



VideoFisico::VideoFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoMaterial, std::string estado, int dias, std::string formato, int duracion, std::string resolucion)
	:MaterialFisico(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, dias), formato(formato), duracion(duracion), resolucion(resolucion)
{
	// Constructor
	this->formato = formato;
	this->duracion = duracion;
	this->resolucion = resolucion;
}

VideoFisico::~VideoFisico()
{
	// Destructor
}

std::string VideoFisico::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Video Fisico: " << std::endl;
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
	oss << "Formato: " << formato << std::endl;
	oss << "Duracion: " << duracion << std::endl;
	oss << "Resolucion: " << resolucion << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}
