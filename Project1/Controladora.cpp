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
	try {
		interfaz->bannerBienvenida();
		system("pause");
		MenuPrincipal();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Error desconocido" << std::endl;
	}

}

void Controladora::datosPrueba()
{
	interfaz->DatosPrueba();
	// Agregar materiales de prueba
	Libro* libro = interfaz->crearLibro();
	biblioteca->agregarMaterial(libro);
	ArticuloDigital* articuloDigital = interfaz->crearArticuloDigital();
	biblioteca->agregarMaterial(articuloDigital);
	ArticuloFisico* articuloFisico = interfaz->crearArticuloFisico();
	biblioteca->agregarMaterial(articuloFisico);
	VideoFisico* videoFisico = interfaz->crearVideoFisico();
	biblioteca->agregarMaterial(videoFisico);
	VideoDigital* videoDigital = interfaz->crearVideoDigital();
	biblioteca->agregarMaterial(videoDigital);
	Revista* revista = interfaz->crearRevista();
	biblioteca->agregarMaterial(revista);
	system("pause");
}

void Controladora::MenuPrincipal(){
	int opcion;
	do {
		system("cls");
		opcion = interfaz->mostrarMenuPrincipal();
		switch (opcion) {
		case 1:
			// Agregar material
			MenuAgregarMaterial();
			break;
		case 2:
			// Agregar usuario
			interfaz->crearUsuario();
			biblioteca->agregarUsuario(interfaz->crearUsuario());
			interfaz->msj("Usuario agregado correctamente");
			break;
		case 5:
			// Mostrar materiales
			break;
		case 6:
			// Mostrar usuarios
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
	} while (opcion != 7);


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
