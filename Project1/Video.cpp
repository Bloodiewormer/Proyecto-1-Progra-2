#include "Video.h"


Video::Video(std::string identificador, std::string cantidad, std::string titulo, std::string autor, std::string palabrasClave, std::string tipoMaterial, std::string estado, std::string duracion, std::string formato, std::string tipo, std::string tema)
{
	this->identificador = identificador;
	this->cantidad = cantidad;
	this->titulo = titulo;
	this->autor = autor;
	this->palabrasClave = palabrasClave;
	this->tipoMaterial = tipoMaterial;
	this->estado = estado;
	this->duracion = duracion;
	this->formato = formato;
	this->tipo = tipo;
	this->tema = tema;
}

Video::~Video()
{
}

std::string Video::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Video: " << std::endl;
	oss << "Identificador: " << identificador << std::endl;
	oss << "Cantidad: " << cantidad << std::endl;
	oss << "Titulo: " << titulo << std::endl;
	oss << "Autor: " << autor << std::endl;
	oss << "Palabras Clave: " << palabrasClave << std::endl;
	oss << "Tipo de Material: " << tipoMaterial << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "Duracion: " << duracion << std::endl;
	oss << "Formato: " << formato << std::endl;
	oss << "Tipo: " << tipo << std::endl;
	oss << "Tema: " << tema << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}
