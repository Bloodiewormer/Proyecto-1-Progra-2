#include "Prestamo.h"


Prestamo::Prestamo(int id,Time fechaAct, Usuario* usuario, Material* material)
{
	this->idPrestamo = id;
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

int Prestamo::getIdPrestamo()
{
	return idPrestamo;
}

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
	ss  << "==================================="
		<< "\nPrestamo ID: " << idPrestamo
		<< "\nUsuario: " << usuario->getCedula()
		<< "\nMaterial: " << material->getIdentificador()
		<< "\nFecha del Prestamo: " << fechaPrestamo.toString()
		<< "\nEstado: " << estado;
	if (estado != "prestado") {
		ss << "\nFecha Devolucion: " << fechaDevolucion.toString();
	}
	ss << "\n===================================";


	return ss.str();
}

std::string Prestamo::toStringCSV() const {
	std::stringstream ss;
	ss << idPrestamo << "," << usuario->getCedula() << "," << material->getIdentificador() << "," << fechaPrestamo.getDia() << ","
		<< fechaDevolucion.getDia() << "," << estado;
	return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo)
{
	os << prestamo.toString();
	return os;
}
