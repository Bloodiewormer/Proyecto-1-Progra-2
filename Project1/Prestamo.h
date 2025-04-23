#pragma once
#include <iostream>
#include <sstream>
#include "Usuario.h"
#include "Material.h"
#include "Time.h"
#include "Lista.h"


class Prestamo{
private:
	int idPrestamo;
	std::string estado;//Devuelto, EnPrestamo
	Usuario* usuario;
	Material* material;
	Time fechaPrestamo;
	Time fechaDevolucion;

public:
	
	Prestamo(int id,Time fechaA, Usuario* usuarioA, Material* materialA);	
	std::string getEstado();
	Usuario* getUsuario();
	Material* getMaterial();
	int getIdPrestamo();
	Time getFechaPrestamo();

	void devolver(Time fecAct);

	std::string toString() const;
	std::string toStringCSV() const;

	//sobrecarga de operador
	friend std::ostream& operator<<(std::ostream& os, const Prestamo& prestamo);

};

