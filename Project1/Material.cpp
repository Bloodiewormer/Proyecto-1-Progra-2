#include "Material.h"

Material::Material(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores)
{
	this->identificador = identificador;
	this->titulo = titulo;
	this->palabrasClave = palabrasClave;
	this->autores = autores;

}

Material::~Material()
{
}
