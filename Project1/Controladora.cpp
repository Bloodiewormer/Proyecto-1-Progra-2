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

void Controladora::GuardarDatos()
{
	
	Lista<Usuario> usuarios = biblioteca->getListaUsuarios();
	gestorArchivos->guardarUsuarios(usuarios, "usuarios.csv");
	//gestorArchivos->cargarDatos(biblioteca);
	//interfaz->msj("Datos cargados correctamente");
	//system("pause");
}

void Controladora::MenuPrincipal(){
	int opcion = 20;
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
			}
			break;
		case 1:
			// Agregar material
			MenuAgregarMaterial();
			break;
		case 2:
			// Agregar usuario
			MenusubMenuUsuario();
			break;
		case 5:
			// Mostrar materiales
			GuardarDatos();
			break;
		case 6:
			// Mostrar usuarios
			MenuReportes();
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
		catch (const InvalidInputException& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			system("pause");
		}
		catch (...) {
			std::cerr << "Error desconocido" << std::endl;
		}
	} while (opcion != -1);


}

void Controladora::MenusubMenuUsuario()
{
	int opcion;
	std::string dato;
	system("cls");
	opcion = interfaz->mostrarSubMenuUsuario();
	switch (opcion) {
	case 0:
		opcion = -2;
		break;
	case 1:
		biblioteca->agregarUsuario(interfaz->crearUsuario());
		interfaz->msj("Usuario agregado correctamente");
		break;
	case 2:
		// Modificar usuario
		MenuModificarUsuario();
		break;
	case 3:
		// Eliminar usuario
		dato = interfaz->pedirDatos("cedula", false);
		if (biblioteca->comprobarExistenciaUsuario(dato) == false) {
			interfaz->msj("El usuario no existe");
			system("pause");
			break;
		}
		else
		{
		biblioteca->eliminarUsuario(dato);
		interfaz->msj("Usuario eliminado correctamente");
		}
		system("pause");
	break;
	case 4:
		// Buscar usuario
		std::cout<<biblioteca->buscarUsuario(interfaz->pedirDatos("cedula", false))->toString();
		system("pause");
		break;
	default:
		interfaz->opcionInvalida();
		break;
	}
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

void Controladora::MenuReportes()
{
	system("cls");
	int opcion = interfaz->subMenuReportes();
	switch (opcion) {
	case 1:
		biblioteca->mostrarMateriales();
		break;
	case 2:
		biblioteca->mostrarUsuarios();
		break;
	case 3:
		//biblioteca->gestorPrestamos.mostrarPrestamos();
		break;
	case 4:
		//biblioteca->gestorPrestamos.mostrarHistorialPrestamos();
		break;
	default:
		interfaz->opcionInvalida();
		break;
	}
}

void Controladora::MenuModificarUsuario()
{
	switch (interfaz->mostrarSubMenuModificarUsuario()) {
	case 1:
		biblioteca->modificarUsuario(interfaz->pedirDatos("cedula", false), interfaz->pedirDatos("nombre", true), 1);
		break;
	case 2:
		biblioteca->modificarUsuario(interfaz->pedirDatos("cedula", false), interfaz->pedirDatos("apellido", true), 2);
		break;
	case 3:
		biblioteca->modificarUsuario(interfaz->pedirDatos("cedula", false), interfaz->pedirDatosBool("estado") ? "true" : "false", 3);
		break;
	case 4:
		biblioteca->modificarUsuario(interfaz->pedirDatos("cedula", false), interfaz->pedirDatos("cedula", true), 4);
		break;
	default:
		interfaz->opcionInvalida();
		break;
	}
	system("pause");
}
