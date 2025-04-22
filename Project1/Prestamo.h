#pragma once
#include <iostream>
#include <sstream>
#include "Usuario.h"
#include "Material.h"
#include "Time.h"


class Prestamo{
private:

	std::string estado;//Devuelto, EnPrestamo
	Usuario* usuario;
	Material* material;
	//std::string fechaPrestamo;
	//std::string fechaDevolucion;
	Time fechaPrestamo;
	Time fechaDevolucion;

public:
	//Prestamo(std::string, Usuario*, Material*);
	//std::string getFechaPrestamo();
	//std::string getFechaDevolucion();
	Prestamo(Time fechaA, Usuario* usuarioA, Material* materialA);	
	std::string getEstado();
	Usuario* getUsuario();
	Material* getMaterial();
	Time getFechaPrestamo();

	void devolver(Time fecAct);

	std::string toString() const;
	std::string toStringCSV();

	//sobrecarga de operador
	friend std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo);
};

