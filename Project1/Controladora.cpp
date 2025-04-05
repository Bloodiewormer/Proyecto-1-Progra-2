#include "Controladora.h"

Controladora::Controladora(){
	biblioteca = new Biblioteca();
	gestorArchivos = new GestorArchivos();
	interfaz = new IntefazUsuario();
}

Controladora::~Controladora(){
	delete biblioteca;
	delete gestorArchivos;
	delete interfaz;

}

void Controladora::iniciar(){


		interfaz->bannerBienvenida();
		system("pause");
		interfaz->DatosPrueba();
		MenuPrincipal();

}

void Controladora::datosPrueba()
{
	system("pause");
}

void Controladora::MenuPrincipal(){
	int opcion;
	do {
		try{
		system("cls");
		opcion = interfaz->mostrarMenuPrincipal();
		switch (opcion) {
		case 0:
			if (interfaz->ConfirmarSalida() == true) {
				opcion = -1;
				interfaz->msj("Saliendo del programa...");
			}
			else {
				interfaz->msj("Regresando al menu principal...");
				system("pause");
			}
			break;
		case 1:
			// Agregar material
			MenuAgregarMaterial();
			break;
		case 2:
			// Agregar usuario
			biblioteca->agregarUsuario(interfaz->crearUsuario());
			interfaz->msj("Usuario agregado correctamente");
			break;
		case 5:
			// Mostrar materiales

			break;
		case 6:
			// Mostrar usuarios
			biblioteca->mostrarUsuarios();
			system("pause");

			break;
		case 7:
			if (interfaz->ConfirmarSalida()) {
				interfaz->msj("Saliendo del programa...");
				system("pause");
			}
			else {
				interfaz->msj("Regresando al menu principal...");
				system("pause");
			}
			break;
		default:
			interfaz->opcionInvalida();
			break;
		}
		system("cls");
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			system("pause");
		}
		catch (...) {
			std::cerr << "Error desconocido" << std::endl;
		}
	} while (opcion != -1);


}

void Controladora::MenuAgregarMaterial()
{
	int opcion;
	//primero se pregunta si es fisico o digital
	opcion = interfaz->tipoMaterial();
	switch (opcion) {
	case 1:
		// Agregar material fisico
		switch (interfaz->tipoMaterialFisico()) {
		case 1:
			biblioteca->agregarMaterial(interfaz->crearLibro());
			break;
		case 2:
			biblioteca->agregarMaterial(interfaz->crearRevista());
			break;
		case 3:
			biblioteca->agregarMaterial(interfaz->crearVideoFisico());
			break;
		case 4:
			biblioteca->agregarMaterial(interfaz->crearArticuloFisico());
			break;
		default:
			interfaz->opcionInvalida();
			break;
		}
		break;
	case 2:
		// Agregar material digital
		switch (interfaz->tipoMaterialDigital()) {
		case 1:
			biblioteca->agregarMaterial(interfaz->crearVideoDigital());
			break;
		case 2:
			biblioteca->agregarMaterial(interfaz->crearArticuloDigital());
			break;
		default:
			interfaz->opcionInvalida();
			break;
		}
		break;
	default:
		interfaz->opcionInvalida();
	break;
	}
	interfaz->msj("Material agregado correctamente");
	system("pause");
}
