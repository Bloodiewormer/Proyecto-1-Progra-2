#include "Prestamo.h"

//Prestamo::Prestamo(std::string fecha, Usuario* u, Material* m){
//	this->usuario = u;
//	this->material = m;
//	this->fechaPrestamo = fecha;
//	this->estado = "prestado";
//	this->fechaDevolucion = "";
//}
//
//std::string Prestamo::getFechaPrestamo(){ return fechaPrestamo; }
//
//std::string Prestamo::getFechaDevolucion(){ return fechaDevolucion; }

Prestamo::Prestamo(Time fechaAct, Usuario* usuario, Material* material)
{
	this->usuario = usuario;
	this->material = material;
	this->fechaPrestamo = fechaAct;
	this->estado = "prestado";

	int diasPrestamo = material->getDiasPrestamo();
	this->fechaDevolucion = Time(fechaAct.getDia() + diasPrestamo);
	
}

std::string Prestamo::getEstado(){ return estado; }

Usuario* Prestamo::getUsuario(){ return usuario; }

Material* Prestamo::getMaterial(){ return material; }

Time Prestamo::getFechaPrestamo()
{
	return fechaPrestamo;
}

void Prestamo::devolver(Time fechaActual) { 
	fechaDevolucion = fechaActual;
	estado = "devuelto";
}

std::string Prestamo::toString() const{
	std::stringstream ss;
	ss << "Usuario: " << usuario->getCedula() << " | Material: " << material->getIdentificador()
		<< " | Fecha del Prestamo: " << fechaPrestamo.toString()
		<< " | Estado: " << estado;
	if (estado != "prestado") {
		ss << " | Fecha Devolucion: " << fechaDevolucion.toString();
	}
	return ss.str();
}

std::string Prestamo::toCSV() const {
	std::stringstream ss;
	ss << usuario->getCedula() << "," << material->getIdentificador() << "," << fechaPrestamo.getDia() << ","
		<< fechaDevolucion.getDia() << "," << estado;
	return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo)
{
	os << prestamo.toString();
	return os;
}
