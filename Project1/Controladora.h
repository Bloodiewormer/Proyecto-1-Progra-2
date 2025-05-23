#pragma once
#include "IntefazUsuario.h"
#include "Biblioteca.h"
#include "GestorArchivos.h"
#include "CustomException.h"
#include "GestorPrestamo.h"
#include "Utility.h"

class Controladora{
private:
	Biblioteca* biblioteca;
	GestorArchivos* gestorArchivos;
	IntefazUsuario* interfaz;
public:
	Controladora();
	virtual ~Controladora();
	void iniciar();
	void MenuPrincipal();
	void MenusubMenuUsuario();
	void MenuMaterial();
	void MenuAgregarMaterial();
	void MenuPrestamos();
	void MenuReportes();
	void MenuModificarUsuario();
	void MenuTiempo();
	void GuardarDatos();
	void CargarDatos();
};

