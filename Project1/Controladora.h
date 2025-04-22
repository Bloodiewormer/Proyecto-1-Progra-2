#pragma once
#include "IntefazUsuario.h"
#include "Biblioteca.h"
#include "GestorArchivos.h"
#include "CustomException.h"
#include "GestorPrestamo.h"

class Controladora{
private:
	Biblioteca* biblioteca;
	GestorArchivos* gestorArchivos;
	GestorPrestamo* gestorPrestamo;
	IntefazUsuario* interfaz;
public:
	Controladora();
	virtual ~Controladora();
	void iniciar();
	void datosPrueba();
	void MenuPrincipal();
	void MenusubMenuUsuario();
	void MenuAgregarMaterial();
	void MenuPrestamos();
	void MenuReportes();
	void MenuModificarUsuario();
	void MenuTiempo();
	void GuardarDatos();
	void CargarDatos();
};

