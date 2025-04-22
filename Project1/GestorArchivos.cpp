#include "GestorArchivos.h"
#include "Biblioteca.h"



void GestorArchivos::guardarUsuarios(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
	Lista<Usuario> listaUsuarios = biblioteca->getListaUsuarios();
	if (listaUsuarios.getLength() == 0) {
		throw new InvalidInputException("No hay usuarios para guardar.");
	}
	std::ofstream archivo(nombreArchivo, std::ios::out);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para guardar usuarios.");
	}
	archivo << "cedula , nombre , apellido , estado" << std::endl;	
	if (listaUsuarios.getLength() == 0) {
		throw  InvalidInputException("No hay usuarios para guardar.");
	}
	else {
		archivo << listaUsuarios.CSV();
		archivo.close();
	}
	archivo.close();
}

void GestorArchivos::guardarTiempo(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
	Time tiempo = biblioteca->getCurrentTime();
	std::ofstream archivo(nombreArchivo, std::ios::out);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para guardar tiempos.");
	}
	archivo << "dia" << std::endl; //0 to 365
	archivo << tiempo.getDia()<< std::endl;
	archivo.close();
}

void GestorArchivos::guardarPrestamos(const Lista<Prestamo>& listaPrestamos, const std::string& nombreArchivo){
	if (listaPrestamos.getLength() == 0) {
		throw InvalidInputException("No hay préstamos para guardar.");
	}

	std::ofstream archivo(nombreArchivo, std::ios::out);
	if (!archivo.is_open()) {
		throw FileOperationException("Error al abrir el archivo para guardar préstamos.");
	}

	archivo << "cedula,idMaterial,fechaPrestamo,fechaDevolucion,estado" << std::endl;

	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* p = listaPrestamos.get(i);
		archivo << p->toCSV() << std::endl;
	}

	archivo.close();
}

void GestorArchivos::cargarUsuarios(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
	std::ifstream archivo(nombreArchivo, std::ios::in);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para cargar usuarios.");
	}
	std::string linea;
	// Leer la primera línea (encabezados)
	std::getline(archivo, linea);
	// Leer el resto de las líneas
	while (std::getline(archivo, linea)) {
		std::istringstream iss(linea);
		std::string cedula, nombre, apellido, estado;
		if (std::getline(iss, cedula, ',') && std::getline(iss, nombre, ',') && std::getline(iss, apellido, ',') && std::getline(iss, estado)) {
			bool estadoBool = (estado == "Activo");
			Usuario* usuario = new Usuario(cedula, nombre, apellido, estadoBool);
			biblioteca->agregarUsuario(usuario);
		}
	}
	archivo.close();
}

void GestorArchivos::cargarTiempo(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
	std::ifstream archivo(nombreArchivo, std::ios::in);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para cargar tiempos.");
	}
	std::string linea;
	// Leer la primera línea (encabezados)
	std::getline(archivo, linea);
	// Leer el resto de las líneas
	while (std::getline(archivo, linea)) {
		std::istringstream iss(linea);
		int dia;
		if (iss >> dia) {
			biblioteca->setTime(dia+1, 1);
		}
	}
	archivo.close();
}
