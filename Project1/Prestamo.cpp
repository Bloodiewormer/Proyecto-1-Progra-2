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


	bool tarde;
	int cantDiasPrestamo = material->getDiasPrestamo();
	if (fechaDevolucion.getDia() > fechaPrestamo.getDia() + cantDiasPrestamo) {
		tarde = true;
	}
	else {
		tarde = false;
	}

	std::stringstream ss;

	ss << "===================================\n";
	ss << "ID Prestamo: " << idPrestamo << "\n";
	ss << "Usuario: " << usuario->getNombre() << "\n";
	ss << "Material: " << material->getTitulo() << "\n";
	ss << "Fecha de prestamo: " << fechaPrestamo.toString() << "\n";
	ss << "Fecha de devolucion: " << fechaDevolucion.toString() << "\n";
	ss << "Estado: " << estado << "\n";
	if (estado == "prestado") {
		ss << "El material no ha sido devuelto\n";
	}
	else {
		if (tarde) {
			ss << "El material fue devuelto tarde\n";
		}
		else {
			ss << "El material fue devuelto a tiempo\n";
		}
	}
	ss << "===================================";


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
