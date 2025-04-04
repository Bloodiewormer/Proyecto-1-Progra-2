#pragma once
#include "IntefazUsuario.h"
#include "Biblioteca.h"
#include "GestorArchivos.h"

class Controladora{
private:
	Biblioteca* biblioteca;
	GestorArchivos* gestorArchivos;
	IntefazUsuario* interfaz;
	// maybe need a exeption handler here
public:
	Controladora();
	~Controladora();
	void iniciar();
	void mostrarMenuPrincipal();
};

