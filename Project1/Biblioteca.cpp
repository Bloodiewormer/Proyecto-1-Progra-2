#include "Biblioteca.h"

Biblioteca::Biblioteca(){
	listaMateriales = Lista<Material>();
	listaUsuarios = Lista<Usuario>();
	gestorPrestamos = GestorPrestamo();
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
		throw InvalidInputException("Material cannot be null");	
	}
	if (comprobarExistenciaMaterial(material->getIdentificador())) {
		throw InvalidInputException("Material already exists in the list");
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
		for (int i = 0; i < listaMateriales.getLength(); i++) {
			Material* material = listaMateriales.get(i);
			std::cout << material->toString() << std::endl;
		}
	}
}

void Biblioteca::eliminarMaterial(std::string ID)
{
	if (ID.empty()) {
		throw InvalidInputException("ID cannot be empty");
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

//Material* Biblioteca::buscarMaterial(std::string ID)
//{
//	if (ID.empty()) {
//		throw InvalidInputException("ID cannot be empty");
//	}
//	for (int i = 0; i < listaMateriales.getLength(); i++) {
//		if (listaMateriales.get(i)->getIdentificador() == ID) {
//			return listaMateriales.get(i);
//		}
//	}
//	throw InvalidInputException("Material no encontrado");
//}


bool Biblioteca::comprobarExistenciaUsuario(std::string ID) {
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
		std::cout<<listaUsuarios.toString();
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

Lista<Usuario> Biblioteca::getListaUsuarios()  
{  
   return listaUsuarios;  
}


