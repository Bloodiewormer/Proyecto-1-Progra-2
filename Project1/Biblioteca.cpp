#include "Biblioteca.h"

Biblioteca::Biblioteca(){
	listaMateriales = Lista<Material>();
	listaUsuarios = Lista<Usuario>();
	gestorPrestamos = GestorPrestamo();
	currentTime = 0; //= 1/1 ; 1 enero
}

Biblioteca::~Biblioteca() {

}

bool Biblioteca::comprobarExistenciaMaterial(std::string ID){
	if (ID.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	for (int i = 0; i < listaMateriales.getLength(); i++) {
		if (listaMateriales.get(i)->getIdentificador() == ID) {
			return true;
		}
	}
	return false;
}

void Biblioteca::agregarMaterial(Material* material)
{
	if (material == nullptr) {
		throw ObjectCreationException("Material cannot be null");
	}
	if (comprobarExistenciaMaterial(material->getIdentificador())) {
		throw ObjectCreationException("Material already exists in the list");
	}
	listaMateriales.addBegin(material); 
}

void Biblioteca::mostrarMateriales()
{
	if (listaMateriales.isEmpty()) {
		std::cout << "No hay materiales registrados." << std::endl;
	}
	else {
		std::cout << "Lista de Materiales:" << std::endl;
		/*for (int i = 0; i < listaMateriales.getLength(); i++) {
			Material* material = listaMateriales.get(i);
			std::cout << material->toString() << std::endl;
		}*/
		std::cout << listaMateriales.toString();
	}
}

void Biblioteca::eliminarMaterial(std::string ID)
{
	if (ID.empty()) {
		throw ObjectCreationException("ID cannot be empty");
	}

	for (int i = 0; i < listaMateriales.getLength(); i++) {
		if (listaMateriales.get(i)->getIdentificador() == ID) {
			listaMateriales.remove(i);
			std::cout << "Material eliminado correctamente." << std::endl;
			return;
		}
	}
	std::cout << "Material no encontrado." << std::endl;
}

Material* Biblioteca::buscarMaterial(std::string ID)
{
	if (ID.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	for (int i = 0; i < listaMateriales.getLength(); i++) {
		if (listaMateriales.get(i)->getIdentificador() == ID) {
			return listaMateriales.get(i);
		}
	}
	throw InvalidInputException("Material no encontrado");
}


bool Biblioteca::comprobarExistenciaUsuario(std::string ID) {
		if (ID.empty()) {
			throw ObjectCreationException("ID cannot be empty");
		}
		for (int i = 0; i < listaUsuarios.getLength(); i++) {
			if (listaUsuarios.get(i)->getCedula() == ID) {
				return true;
			}
		}
		return false;
}

void Biblioteca::agregarUsuario(Usuario* usuario)
{
		if (usuario == nullptr) {
			throw ObjectCreationException("Usuario cannot be null");
		}
		if (comprobarExistenciaUsuario(usuario->getCedula())) {
			throw ObjectCreationException("Usuario already exists in the list");
		}
		listaUsuarios.addBegin(usuario); // Pass the address of the usuario pointer
}

void Biblioteca::mostrarUsuarios()
{
	if (listaUsuarios.isEmpty()) {
		std::cout << "No hay usuarios registrados." << std::endl;
	}
	else {
		std::cout << "Lista de Usuarios:" << std::endl;
		std::cout<<listaUsuarios.toString();
	}
}

void Biblioteca::modificarUsuario(std::string ID, std::string change, int opcion)
{
	if (ID.empty()) {
		throw ObjectCreationException("ID cannot be empty");
	}
	Usuario* usuario = buscarUsuario(ID);
	if (usuario == nullptr) {
		throw ObjectCreationException("Usuario cannot be null");
	}
	if (comprobarExistenciaUsuario(usuario->getCedula())) {
		switch (opcion) {
		case 1: // Modificar nombre
			usuario->setNombre(change);
			break;
		case 2: // Modificar apellido
			usuario->setApellido(change);
			break;
		case 3: // Modificar estado
			if (change == "true") {
				usuario->setEstado(true);
			}
			else if (change == "false") {
				usuario->setEstado(false);
			}
			else {
				std::cout << "Estado invalido" << std::endl;
			}
			break;
		case 4: // Modificar cedula
			if (comprobarExistenciaUsuario(change)) {
				std::cout << "La cedula ya existe en la lista" << std::endl;
			}
			else {
				usuario->setCedula(change);
			}
			break;
			{
		default:
			break;

			}
		}

	}
	else {
		std::cout << "El usuario no existe en la lista" << std::endl;
	}
}


void Biblioteca::eliminarUsuario(std::string ID)
{
	if (ID.empty()) {
		throw ObjectCreationException("ID cannot be empty");
	}
	for (int i = 0; i < listaUsuarios.getLength(); i++) {
		if (listaUsuarios.get(i)->getCedula() == ID) {
			listaUsuarios.remove(i);
			std::cout << "Usuario eliminado correctamente." << std::endl;
			return;
		}
	}
	std::cout << "Usuario no encontrado." << std::endl;
}

Usuario* Biblioteca::buscarUsuario(std::string ID)
{
	if (ID.empty()) {
		throw ObjectCreationException("ID cannot be empty");
	}
	for (int i = 0; i < listaUsuarios.getLength(); i++) {
		if (listaUsuarios.get(i)->getCedula() == ID) {
			return listaUsuarios.get(i);
		}
	}
	throw ObjectCreationException("Usuario no encontrado");
}

void Biblioteca::registrarPrestamo(std::string idUsuario, std::string idMaterial, std::string fechaActual)
{
	Usuario* u = buscarUsuario(idUsuario);
	Material* m = buscarMaterial(idMaterial); //falta implementacion de buscarMaterial
	if (u != nullptr && m != nullptr) {
		gestorPrestamos.registrarPrestamo(fechaActual, u, m);
		std::cout << "Prestamo registrado correctamente.\n";
	}
	else {
		std::cout << "Usuario o material no encontrado.\n";
	}
}

void Biblioteca::devolverMaterial(std::string idUsuario, std::string idMaterial, std::string fechaActual)
{
	gestorPrestamos.devolverMaterial(idUsuario, idMaterial, fechaActual);
}

void Biblioteca::mostrarPrestamos()
{
	gestorPrestamos.mostrarPrestamos();
}

void Biblioteca::mostrarPrestamosPorUsuario(std::string idUsuario)
{
	gestorPrestamos.mostrarPrestamosPorUsuario(idUsuario);
}

void Biblioteca::mostrarPrestamosPorMaterial(std::string idMaterial)
{
	gestorPrestamos.mostrarPrestamosPorMaterial(idMaterial);
}

Time Biblioteca::getCurrentTime()
{
	return currentTime;
}

void Biblioteca::pasarDias(int dias)
{
	if (dias < 0) {
		throw ObjectCreationException("Dias cannot be negative");
	}
	currentTime.pasarDia(dias);
}

void Biblioteca::volverDias(int dias)
{
	if (dias < 0) {
		throw InvalidDateException("Dias cannot be negative");
	}
	currentTime.regresarDia(dias);
}

void Biblioteca::resetTime()
{
	currentTime.irAlDia(0);
}

void Biblioteca::setTime(int dia, int mes)
{
	if (dia < 1 || dia > 31) {
		throw InvalidDateException("Dia no valido");
	}
	if (mes < 1 || mes > 12) {
		throw InvalidDateException("Mes no valido");
	}
	if (mes == 2 && dia > 28) {
		throw InvalidDateException("Febrero solo tiene 28 dias");
	}
	if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
		throw InvalidDateException("Este mes solo tiene 30 dias");
	}
	int diasTotales = 0;
	for (int i = 0; i < mes - 1; i++) {
		if (i == 1) {
			diasTotales += 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			diasTotales += 30;
		}
		else {
			diasTotales += 31;
		}
	}
	diasTotales += dia-1;
	currentTime.irAlDia(diasTotales);
}

Lista<Usuario> Biblioteca::getListaUsuarios()  
{  
   return listaUsuarios;  
}


