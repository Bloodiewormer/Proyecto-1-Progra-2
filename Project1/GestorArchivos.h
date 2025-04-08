#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "CustomExeception.h"
#include "Usuario.h"
#include "Lista.h"
class GestorArchivos {
public:
	static void guardarUsuarios(Lista<Usuario> listaUsuarios, const std::string& nombreArchivo);
	
};