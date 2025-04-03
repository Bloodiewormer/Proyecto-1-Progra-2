#include "Material.h"

Material::Material(std::string identificador, std::string cantidad, std::string titulo, std::string autor, std::string palabrasClave, std::string tipoMaterial, std::string estado)
{
	this->identificador = identificador;
	this->cantidad = cantidad;
	this->titulo = titulo;
	this->autor = autor;
	this->palabrasClave = palabrasClave;
	this->tipoMaterial = tipoMaterial;
	this->estado = estado;
}
Material::~Material()
{
	// Destructor
}


