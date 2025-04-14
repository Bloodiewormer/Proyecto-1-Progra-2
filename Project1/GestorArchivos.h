#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "CustomException.h"
#include "Usuario.h"
#include "Lista.h"
#include "Biblioteca.h"
class GestorArchivos {
public:
	static void guardarUsuarios(Biblioteca* biblioteca, const std::string& nombreArchivo);
	static void guardarTiempo(Biblioteca* biblioteca, const std::string& nombreArchivo);
	static void cargarUsuarios(Biblioteca* biblioteca, const std::string& nombreArchivo);
	static void cargarTiempo(Biblioteca* biblioteca, const std::string& nombreArchivo);
};