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

std::ostream& operator<<(std::ostream& os, const Usuario& usuario)
{
	os << "====================" << std::endl;
	os << "Usuario: " << std::endl;
	os << "Cedula: " << usuario.getCedula() << std::endl;
	os << "Nombre: " << usuario.nombre << std::endl;
	os << "Apellido: " << usuario.apellido << std::endl;
	os << "Estado: " << (usuario.estado ? "Activo" : "Inactivo") << std::endl;
	os << "====================" << std::endl;
	return os;
	
}
