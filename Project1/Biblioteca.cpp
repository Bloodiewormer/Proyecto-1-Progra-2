#include "Biblioteca.h"

Biblioteca::Biblioteca() : listaMateriales(), listaUsuarios(), gestorPrestamos() {

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

void Biblioteca::agregarUsuario(Usuario* usuario)
{
	try {
		if (usuario == nullptr) {
			throw InvalidInputException("Usuario cannot be null");
		}
		if (listaUsuarios.contains(&usuario)) {
			throw InvalidInputException("Usuario already exists in the list");
		}
		listaUsuarios.addBegin(&usuario); // Pass the address of the usuario pointer
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown error" << std::endl;
	}
}
