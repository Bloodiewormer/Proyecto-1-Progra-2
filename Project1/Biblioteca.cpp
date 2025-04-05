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
