#include "Prestamo.h"

Prestamo::Prestamo(std::string fecha, Usuario* u, Material* m){
	this->usuario = u;
	this->material = m;
	this->fechaPrestamo = fecha;
	this->estado = "prestado";
	this->fechaDevolucion = "";
}

std::string Prestamo::getFechaPrestamo(){ return fechaPrestamo; }

std::string Prestamo::getFechaDevolucion(){ return fechaDevolucion; }

std::string Prestamo::getEstado(){ return estado; }

Usuario* Prestamo::getUsuario(){ return usuario; }

Material* Prestamo::getMaterial(){ return material; }

void Prestamo::devolver(std::string fechaActual) { 
	fechaDevolucion = fechaActual;
	estado = "devuelto";
}

std::string Prestamo::toString(){
	std::stringstream ss;
	ss << "Usuario: " << usuario->getCedula() << " | Material: " << material->getIdentificador()
		<< " | Fecha del Prestamo: " << fechaPrestamo
		<< " | Estado: " << estado;
	if (estado != "prestado") {
		ss << " | Fecha Devolucion: " << fechaDevolucion;
	}
	return ss.str();
}

std::string Prestamo::toCSV() const {
	std::stringstream ss;
	ss << usuario->getCedula() << "," << material->getIdentificador() << "," << fechaPrestamo << ","
		<< fechaDevolucion << "," << estado;
	return ss.str();
}

