#pragma once
#include "IntefazUsuario.h"
#include "Biblioteca.h"
#include "GestorArchivos.h"
#include "CustomException.h"

class Controladora{
private:
	Biblioteca* biblioteca;
	GestorArchivos* gestorArchivos;
	IntefazUsuario* interfaz;
public:
	Controladora();
	virtual ~Controladora();
	void iniciar();
	void datosPrueba();
	void GuardarDatos();
	//void CargarDatos();
	void MenuPrincipal();
	void MenusubMenuUsuario();
	void MenuAgregarMaterial();
	void MenuReportes();
	void MenuModificarUsuario();
};

