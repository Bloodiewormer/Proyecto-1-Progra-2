#include "GestorArchivos.h"



void GestorArchivos::guardarUsuarios(Lista<Usuario> listaUsuarios, const std::string& nombreArchivo)
{
	std::ofstream archivo(nombreArchivo, std::ios::out);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para guardar usuarios.");
	}
	archivo << "cedula ; nombre ; apellido ; estado" << std::endl;	
	if (listaUsuarios.getLength() == 0) {
		throw  InvalidInputException("No hay usuarios para guardar.");
	}
	else {
		archivo << listaUsuarios.CSV();
		archivo.close();
	}
	archivo.close();

}
