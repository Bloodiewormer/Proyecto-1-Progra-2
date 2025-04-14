#pragma once
#include <iostream>
#include <sstream>
#include "Usuario.h"
#include "Material.h"


class Prestamo{
private:

	bool estado;//Devuelto, EnPrestamo
	Usuario* usuario;
	Material* material;

public:
	Prestamo(std::string, Usuario*, Material*);
	std::string getFechaPrestamo();
	std::string getFechaDevolucion();
	std::string getEstado();
	Usuario* getUsuario();
	Material* getMaterial();

	void devolver(std::string);

	std::string toString();
	std::string toStringCSV();
};

