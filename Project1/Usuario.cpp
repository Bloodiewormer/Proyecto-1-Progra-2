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

std::string Usuario::getNombre() const
{
	return nombre;
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

std::string Usuario::toCSV() const
{
	std::ostringstream oss;
	oss << cedula << "," << nombre << "," << apellido << "," << (estado ? "Activo" : "Inactivo") << std::endl;
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

void Usuario::agregarHistorial(const std::string& linea)
{
	historial.addBegin(new std::string(linea));
}

void Usuario::mostrarHistorial()
{
	if (historial.isEmpty()) {
		std::cout << "No hay historial de prestamos." << std::endl;
		return;
	}
	for (int i = 0; i < historial.getLength(); i++) {
		std::cout << *historial.get(i) << std::endl; 
	}
}

std::ostream& operator<<(std::ostream& os, const Usuario& usuario)
{
	os << "====================" << std::endl;
	os << "Usuario: " << std::endl;
	os << "Cedula: " << usuario.cedula << std::endl;
	os << "Nombre: " << usuario.nombre << std::endl;
	os << "Apellido: " << usuario.apellido << std::endl;
	os << "Estado: " << (usuario.estado ? "Activo" : "Inactivo") << std::endl;
	os << "====================" << std::endl;
	return os;
}
