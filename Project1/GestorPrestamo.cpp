#include "GestorPrestamo.h"
#include <cstdio>  
//
//int convertirFechaADias(const std::string& fecha) {
//	int dia = 0, mes = 0, anio = 0;
//	if (sscanf_s(fecha.c_str(), "%d/%d/%d", &dia, &mes, &anio) != 3) {
//		throw std::invalid_argument("Formato de fecha inválido. Debe ser dd/mm/aaaa");
//	}
//	return anio * 365 + mes * 30 + dia; // Aproximación simple
//}

void GestorPrestamo::registrarPrestamo(Time fechaActual, Usuario* u, Material* m){
	Prestamo* nuevo = new Prestamo(fechaActual, u, m);
	listaPrestamos.addBegin(nuevo);
}

void GestorPrestamo::devolverMaterial(Time fechaActual, std::string idUsuario, std::string idMaterial){
	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getUsuario()->getCedula() == idUsuario && prestamo->getMaterial()->getIdentificador() == idMaterial) {

			if (prestamo->getEstado() != "prestado") {
				std::cout << "Este material ya fue devuelto." << std::endl;
				return;
			}

			// Lógica de días máximos según tipo

			int maxDias = prestamo->getMaterial()->getDiasPrestamo();
			//int maxDias = 0;
			//if (tipo == "Libro") maxDias = 7;
			//else if (tipo == "Revista") maxDias = 2;
			//else if (tipo == "Articulo") maxDias = 3;
			//else if (tipo == "Video") maxDias = 5;

			// Cálculo de días transcurridos
			//int diasPrestamo = convertirFechaADias(fechaActual) - convertirFechaADias(prestamo->getFechaPrestamo());
			int diasPrestamo = fechaActual.getDia() - prestamo->getMaterial()->getDiasPrestamo();

			// Registrar devolución
			prestamo->devolver(fechaActual);

			
			// Verificar si hubo retraso
			if (diasPrestamo > maxDias) {
				//std::string registro = "Devuelto tarde: " + fechaActual.toString() + " - " + idMaterial;
				std::string registro = "Devuelto tarde: " + fechaActual.toString() + " - Id de material" + idMaterial + " - Retraso de " + std::to_string(diasPrestamo - maxDias) + " dias";
				prestamo->getUsuario()->agregarHistorial(registro);
				prestamo->getMaterial()->agregarHistorial(registro);
			}else
			{
				std::string registro = "Devuelto a tiempo: " + fechaActual.toString() + " - Id de material " + idMaterial ;
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
		/*for (int i = 0; i < listaPrestamos.getLength(); i++) {
			Prestamo* prestamo = listaPrestamos.get(i);
			std::cout << prestamo->toString() << std::endl;
		}*/

		std::cout << listaPrestamos.toString() << std::endl;
	}
}

void GestorPrestamo::mostrarPrestamosPorUsuario(std::string idUsuario){
	if (idUsuario.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	Usuario* usuario = nullptr;
	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getUsuario()->getCedula() == idUsuario) {
			usuario = prestamo->getUsuario();
			break;
		}
	}
	if (usuario == nullptr) {
		
		throw InvalidInputException("Usuario no encontrado");
	}
	usuario->mostrarHistorial();
}

void GestorPrestamo::mostrarPrestamosPorMaterial(std::string idMaterial){
	if (idMaterial.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	Material* material = nullptr;
	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getMaterial()->getIdentificador() == idMaterial) {
			//std::cout << prestamo->toString() << std::endl;
			 material = prestamo->getMaterial();
			 break;
		}
	}
	if (material == nullptr) {
		throw InvalidInputException("Material no encontrado");
	}
	material->mostrarHistorial();
}
