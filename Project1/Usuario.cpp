#include "Usuario.h"

Usuario::Usuario(std::string cedula, std::string nombre, std::string apellido, bool estado){
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellido = apellido;
	this->estado = estado;
}

Usuario::~Usuario(){
	// Destructor
}

std::string Usuario::getCedula() const{
	return cedula;
}

bool Usuario::getEstado() const{
	return estado;
}

void Usuario::setEstado(bool estado){
	this->estado = estado;
}

std::string Usuario::toString() const{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Usuario: " << std::endl;
	oss << "Cedula: " << cedula << std::endl;
	oss << "Nombre: " << nombre << std::endl;
	oss << "Apellido: " << apellido << std::endl;
	oss << "Estado: " << (estado ? "Activo" : "Inactivo") << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}

std::string Usuario::toStringCSV() const
{
	std::ostringstream oss;
	oss << cedula << ";" << nombre << ";" << apellido << ";" << (estado ? "Activo" : "Inactivo") << std::endl;
	return oss.str();
}

void Usuario::setCedula(std::string cedula)
{
	this->cedula = cedula;
}

void Usuario::setNombre(std::string nombre)
{
	this->nombre = nombre;
}

void Usuario::setApellido(std::string apellido)
{
	this->apellido = apellido;
}