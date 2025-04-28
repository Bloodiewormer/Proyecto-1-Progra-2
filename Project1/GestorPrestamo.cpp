#include "GestorPrestamo.h"
#include <cstdio>  


void GestorPrestamo::registrarPrestamo(Time fechaActual, Usuario* u, Material* m){
	if (u == nullptr || m == nullptr) {
		throw ObjectCreationException("Usuario o material no pueden ser nulos");
	}
	if (u->getEstado() == false) {
		throw ObjectCreationException("Usuario inactivo");
	}
	if (m->getDisponibilidad() == "prestado") {
		throw ObjectCreationException("Material ya prestado");
	}

	//generar un ID unico para el prestamo
	int idPrestamo = listaPrestamos.getLength() + 1;

	//comprobar si el material ya fue prestado
	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getMaterial()->getIdentificador() == m->getIdentificador() && prestamo->getEstado() == "prestado") {
			throw ObjectCreationException("El material ya fue prestado");
		}
	}

	Prestamo* nuevo = new Prestamo(idPrestamo,fechaActual, u, m);
	m->setDisponibilidad("prestado");
	listaPrestamos.addBegin(nuevo);
}

void GestorPrestamo::registrarPrestamoCreado(Prestamo* p){
	if (p != nullptr) {
		listaPrestamos.addBegin(p);
	}
	else {
		throw ObjectCreationException("Prestamo no creado");
	}
}

void GestorPrestamo::devolverMaterial(int idP, Time fechaActual, std::string idUsuario) {
	
	// realmente idUsuario no es necesario, la comprobacion se debe hacer antes pues este metodo solo se encarga de devolver el material

	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getUsuario()->getCedula() == idUsuario && prestamo->getIdPrestamo() == idP) {
			if (prestamo->getEstado() != "prestado") {
				std::cout << "Este material ya fue devuelto." << std::endl;
				return;
			}
			// Lógica de días máximos según tipo
			int maxDias = prestamo->getMaterial()->getDiasPrestamo();
		
			// Cálculo de días transcurridos
			//int diasPrestamo = convertirFechaADias(fechaActual) - convertirFechaADias(prestamo->getFechaPrestamo());
			int diasPrestamo = fechaActual.getDia() - prestamo->getMaterial()->getDiasPrestamo();

			// Registrar devolución
			prestamo->devolver(fechaActual);

			
			// Verificar si hubo retraso
			if (diasPrestamo > maxDias) {
				//std::string registro = "Devuelto tarde: " + fechaActual.toString() + " - " + idMaterial;
				//std::string registro = "Devuelto tarde: " + fechaActual.toString() + " - Id de material" + idMaterial + " - Retraso de " + std::to_string(diasPrestamo - maxDias) + " dias";
				std::string registro  ="======================================\n";
				registro += "ID Prestamo" + std::to_string(prestamo->getIdPrestamo()) + "\n";
				registro += "Usuario: " + prestamo->getUsuario()->getNombre() + "\n";
				registro += "Material: " + prestamo->getMaterial()->getTitulo() + "\n";
				registro += "Fecha de prestamo: " + prestamo->getFechaPrestamo().toString() + "\n";
				registro += "Devuelto tarde el:" + fechaActual.toString() + "\n";
				registro += "Retraso de " + std::to_string(diasPrestamo - maxDias) + " dias\n";
				registro += "======================================\n";


				prestamo->getUsuario()->agregarHistorial(registro);
				prestamo->getMaterial()->agregarHistorial(registro);
			}else
			{
				//std::string registro = "Devuelto a tiempo: " + fechaActual.toString() + " - Id de material " + idMaterial ;
				std::string registro = "======================================\n";
				registro += "ID Prestamo" + std::to_string(prestamo->getIdPrestamo()) + "\n";
				registro += "Usuario: " + prestamo->getUsuario()->getNombre() + "\n";
				registro += "Material: " + prestamo->getMaterial()->getTitulo() + "\n";
				registro += "Fecha de prestamo: " + prestamo->getFechaPrestamo().toString() + "\n";
				registro += "Devuelto" + fechaActual.toString() + "\n";
				registro += "======================================\n";
				prestamo->getUsuario()->agregarHistorial(registro);
				prestamo->getMaterial()->agregarHistorial(registro);

			}
			std::cout << "Material devuelto correctamente." << std::endl;
			prestamo->getMaterial()->setDisponibilidad("disponible");
			return;
		}
	}
	std::cout << "Prestamo no encontrado." << std::endl;
}

Prestamo* GestorPrestamo::buscarPrestamo(int idPrestamo)
{
	return listaPrestamos.get(idPrestamo-1);
}

void GestorPrestamo::mostrarPrestamos(){
	if (listaPrestamos.isEmpty()) {
		std::cout << "No hay prestamos registrados." << std::endl;
	}
	else {
		std::cout << listaPrestamos.toString() << std::endl;
	}
}

void GestorPrestamo::mostrarPrestamosPorUsuario(std::string idUsuario){
	if (idUsuario.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	Lista<Prestamo> prestamosUsuario;

	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getUsuario()->getCedula() == idUsuario) {
			prestamosUsuario.addBegin(prestamo);
		}
	}
	if (prestamosUsuario.isEmpty()) {
		throw InvalidInputException("Usuario no tiene prestamos");
	}
	prestamosUsuario.toString();
}



void GestorPrestamo::mostrarPrestamosPorMaterial(std::string idMaterial){
	if (idMaterial.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	Lista<Prestamo> prestamosMaterial;
	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getMaterial()->getIdentificador() == idMaterial) {
			prestamosMaterial.addBegin(prestamo);
		}
	}
	if (prestamosMaterial.isEmpty()) {
		throw InvalidInputException("Material no tiene prestamos");
	}
	prestamosMaterial.toString();
	
}

void GestorPrestamo::mostrarHistorialUsuario(std::string idUsuario)
{
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

		throw InvalidInputException("Usuario tiene historial");
	}
	usuario->mostrarHistorial();
}

void GestorPrestamo::mostrarHistorialMaterial(std::string idMaterial)
{
	if (idMaterial.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	Material* material = nullptr;
	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* prestamo = listaPrestamos.get(i);
		if (prestamo->getMaterial()->getIdentificador() == idMaterial) {
			material = prestamo->getMaterial();
			break;
		}
	}
	if (material == nullptr) {
		throw InvalidInputException("Material no encontrado");
	}
	material->mostrarHistorial();
}





Lista<Prestamo> GestorPrestamo::getListaPrestamos() {
	return listaPrestamos;
}


