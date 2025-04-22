#pragma once
#include <iostream>
#include <sstream>
#include "Usuario.h"
#include "Material.h"
<<<<<<< HEAD
#include "Time.h"
=======
#include "Lista.h"
>>>>>>> e04f1133ef02369d47d20956f21d7f53ecfefe28


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

<<<<<<< HEAD
	std::string toString() const;
	std::string toStringCSV();

	//sobrecarga de operador
	friend std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo);
=======
	std::string toString();
	std::string toCSV() const;
>>>>>>> e04f1133ef02369d47d20956f21d7f53ecfefe28
};

