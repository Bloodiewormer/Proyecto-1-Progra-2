#include "Biblioteca.h"

Biblioteca::Biblioteca()
{

	listaMateriales = Lista<Material*>();
	listaUsuarios = Lista<Usuario>();
	gestorPrestamos = GestorPrestamo();


}

Biblioteca::~Biblioteca() {

}


void Biblioteca::agregarMaterial(Material* material)
{
	try {
		if (material == nullptr) {
			throw InvalidInputException("Material cannot be null");
		}
		if (listaMateriales.contains(&material)) {
			throw InvalidInputException("Material already exists in the list");
		}
		listaMateriales.addBegin(&material); // Pass the address of the material pointer
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown error" << std::endl;
	}
}

bool Biblioteca::comprobarExistenciaUsuario(std::string ID) {
	try {
		if (ID.empty()) {
			throw InvalidInputException("ID cannot be empty");
		}
		for (int i = 0; i < listaUsuarios.getLength(); i++) {
			if (listaUsuarios.get(i)->getCedula() == ID) {
				return true;
			}
		}
		return false;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}
	catch (...) {
		std::cerr << "Unknown error" << std::endl;
		return false;
	}
}

void Biblioteca::agregarUsuario(Usuario* usuario)
{
		if (usuario == nullptr) {
			throw InvalidInputException("Usuario cannot be null");
		}
		if (comprobarExistenciaUsuario(usuario->getCedula())) {
			throw InvalidInputException("Usuario already exists in the list");
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
		for (int i = 0; i < listaUsuarios.getLength(); i++) {
			Usuario* usuario = listaUsuarios.get(i);
			std::cout << usuario->toString() << std::endl;
		}
	}
}

void Biblioteca::modificarUsuario(std::string ID, std::string change, int opcion)
{
	if (ID.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	Usuario* usuario = buscarUsuario(ID);
	if (usuario == nullptr) {
		throw InvalidInputException("Usuario cannot be null");
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
		throw InvalidInputException("ID cannot be empty");
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
		throw InvalidInputException("ID cannot be empty");
	}
	for (int i = 0; i < listaUsuarios.getLength(); i++) {
		if (listaUsuarios.get(i)->getCedula() == ID) {
			return listaUsuarios.get(i);
		}
	}
	throw InvalidInputException("Usuario no encontrado");
}
