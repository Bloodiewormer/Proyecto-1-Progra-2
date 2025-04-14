#include "GestorPrestamo.h"
#include <cstdio>  

int convertirFechaADias(const std::string& fecha) {
	int dia = 0, mes = 0, anio = 0;
	if (sscanf_s(fecha.c_str(), "%d/%d/%d", &dia, &mes, &anio) != 3) {
		throw std::invalid_argument("Formato de fecha inv�lido. Debe ser dd/mm/aaaa");
	}
	return anio * 365 + mes * 30 + dia; // Aproximaci�n simple
}

void GestorPrestamo::registrarPrestamo(std::string fechaActual, Usuario* u, Material* m){
	Prestamo* nuevo = new Prestamo(fechaActual, u, m);
	listaPrestamos.addBegin(nuevo);
}

void GestorPrestamo::devolverMaterial(std::string idUsuario, std::string idMaterial, std::string fechaActual){
	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getUsuario()->getCedula() == idUsuario && prestamo->getMaterial()->getIdentificador() == idMaterial) {

			if (prestamo->getEstado() != "prestado") {
				std::cout << "Este material ya fue devuelto." << std::endl;
				return;
			}

			// L�gica de d�as m�ximos seg�n tipo
			std::string tipo = prestamo->getMaterial()->getTipo();
			int maxDias = 0;
			if (tipo == "Libro") maxDias = 7;
			else if (tipo == "Revista") maxDias = 2;
			else if (tipo == "Articulo") maxDias = 3;
			else if (tipo == "Video") maxDias = 5;

			// C�lculo de d�as transcurridos
			int diasPrestamo = convertirFechaADias(fechaActual) - convertirFechaADias(prestamo->getFechaPrestamo());

			// Registrar devoluci�n
			prestamo->devolver(fechaActual);

			// Verificar si hubo retraso
			if (diasPrestamo > maxDias) {
				std::string registro = "Devuelto tarde: " + fechaActual + " - " + idMaterial;
				prestamo->getUsuario()->agregarHistorial(registro);
			}

			std::cout << "Material devuelto correctamente." << std::endl;
			return;
		}
	}
	std::cout << "Prestamo no encontrado." << std::endl;
}

void GestorPrestamo::mostrarPrestamos(){
	if (listaPrestamos.isEmpty()) {
		std::cout << "No hay prestamos registrados." << std::endl;
	}
	else {
		for (int i = 0; i < listaPrestamos.getLength(); i++) {
			Prestamo* prestamo = listaPrestamos.get(i);
			std::cout << prestamo->toString() << std::endl;
		}
	}
}

void GestorPrestamo::mostrarPrestamosPorUsuario(std::string idUsuario){
	if (idUsuario.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getUsuario()->getCedula() == idUsuario) {
			std::cout << prestamo->toString() << std::endl;
		}
	}
}

void GestorPrestamo::mostrarPrestamosPorMaterial(std::string idMaterial){
	if (idMaterial.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getMaterial()->getIdentificador() == idMaterial) {
			std::cout << prestamo->toString() << std::endl;
		}
	}
}
