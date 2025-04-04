#pragma once
#include <iostream>
#include <sstream>
#include "Usuario.h"
#include "Material.h"

class Prestamo{
private:
	std::string fechaPrestamo;
	std::string fechaDevolucion;
	std::string estado; // (prestado, devuelto)
	Usuario* usuario;
	Material* material;
public:

};

