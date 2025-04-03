#include "Controladora.h"

Controladora::Controladora()
{
	biblioteca = new Biblioteca();
	gestorArchivos = new GestorArchivos();
	interfaz = new IntefazUsuario();
}

Controladora::~Controladora()
{
	delete biblioteca;
	delete gestorArchivos;
}

void Controladora::iniciar()
{
	// Inicializar la interfaz de usuario
	
	interfaz->bannerBienvenida();
	
	//gestorArchivos->cargarDatos(biblioteca);

}

void Controladora::mostrarMenuPrincipal()
{

}
