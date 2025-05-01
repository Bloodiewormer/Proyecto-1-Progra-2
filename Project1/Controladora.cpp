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
		CargarDatos();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		system("pause");
	}
	catch (...) {
		std::cerr << "Error desconocido" << std::endl;
		system("pause");
	}
	
	interfaz->bannerBienvenida();
	system("pause");
	MenuPrincipal();

}


void Controladora::MenuPrincipal(){
	int opcion = 20;
	do {
		try{
		system("cls");
		std::cout <<"Hoy es: " << biblioteca->getCurrentTime().toString() << std::endl;
		opcion = interfaz->mostrarMenuPrincipal();
		switch (opcion) {
		case 0:
			if (interfaz->ConfirmarSalida() == true) {
				opcion = -1;
				Utilidades::msj("Saliendo del programa...");
			}
			else {
				Utilidades::msj("Regresando al menu principal...");
			}
			break;
		case 1:
			// Agregar material
			MenuMaterial();
			break;
		case 2:
			// Agregar usuario
			MenusubMenuUsuario();
			break;
		case 3:
			// menu de tiempo
			MenuTiempo();
			break;
		case 4:
			// menu de prestamos
			MenuPrestamos();
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
				Utilidades::msj("Saliendo del programa...");
				system("pause");
			}
			else {
				Utilidades::msj("Regresando al menu principal...");
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
		Utilidades::msj("Usuario agregado correctamente");
		break;
	case 2:
		// Modificar usuario
		MenuModificarUsuario();
		break;
	case 3:
		// Eliminar usuario
		dato = interfaz->pedirDatos("cedula de Usuario", false);
		if (biblioteca->comprobarExistenciaUsuario(dato) == false) {
			Utilidades::msj("El usuario no existe");
			system("pause");
			break;
		}
		else
		{
		biblioteca->eliminarUsuario(dato);
		Utilidades::msj("Usuario eliminado correctamente");
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

void Controladora::MenuMaterial()
{
	int opcion;
	system("cls");
	opcion = interfaz->mostrarSubMenuMateriales();
	std::string idmat;
	switch (opcion) {
	case 0:
		opcion = -2;
		break;
	case 1:
		MenuAgregarMaterial();
		break;
	case 2:
		//pedir ID de material Existente
		idmat = interfaz->pedirDatos("ID", false);
		if (biblioteca->comprobarExistenciaMaterial(idmat) == false) {
			Utilidades::msj("El material no existe");
			system("pause");
			break;
		}
		else
		{
			biblioteca->agregarCopiaMaterial(idmat, interfaz->pedirDatos("ID de la copia", false));
			Utilidades::msj("Copia agregada correctamente");
		}
		break;
	case 3:
		biblioteca->eliminarMaterial(interfaz->pedirDatos("ID", false));
		break;
	case 4:
		// Buscar material
		std::cout << biblioteca->buscarMaterial(interfaz->pedirDatos("ID", false))->toString();
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
	Utilidades::msj("Material agregado correctamente");
	system("pause");
}

void Controladora::MenuPrestamos(){
	system("cls");
	int opcion = interfaz->subMenuPrestamos();
	Usuario* usuario;
	std::string idPrestamo;
	std::string idUsuario;
	std::string idMaterial;
	switch (opcion) {
	case 1:
		biblioteca->registrarPrestamo(biblioteca->buscarUsuario(interfaz->pedirDatos("cedula de Usuario ", false))->getCedula(), biblioteca->buscarMaterial(interfaz->pedirDatos("ID de Material", false))->getIdentificador());
		break;
	case 2:
		// Devolver material
		idUsuario = interfaz->pedirDatos("ID de Usuario", false);
		system("cls");
		usuario = biblioteca->buscarUsuario(idUsuario);
		if (usuario == nullptr) {
			Utilidades::msj("El usuario no existe");
			system("pause");
			break;
		}
		Utilidades::msj("Prestamos del usuario: " + usuario->getNombre()+ " ID:" + usuario->getCedula());
		std::cout<<biblioteca->mostrarPrestamosPorUsuario(idUsuario);
		system("pause");
		idPrestamo = interfaz->pedirDatos("ID del prestamo", false);
		biblioteca->devolverMaterial(stoi(idPrestamo),idUsuario);
		break;
	default:
		interfaz->opcionInvalida();
		break;
	}
}

void Controladora::MenuReportes()
{

	system("cls");
	int opcion = interfaz->subMenuReportes();
	int tipo;
	int tipoEspecifico;
	Lista<Material> listaM;

	switch (opcion) {
	case 1:
		biblioteca->mostrarUsuarios();
		break;
	case 2:
		biblioteca->mostrarMateriales();
		break;
	case 3:
		tipo = interfaz->tipoMaterial();
		switch (tipo) {
		case 1:
			tipoEspecifico = interfaz->tipoMaterialFisico();
			switch (tipoEspecifico) {
			case 1:
				listaM=biblioteca->mostrarMaterialesClase("libro");
				break;
			case 2:
				listaM = biblioteca->mostrarMaterialesClase("revista");
				break;
			case 3:
				listaM= biblioteca->mostrarMaterialesClase("video fisico");
				break;
			case 4:
				listaM = biblioteca->mostrarMaterialesClase("articulo fisico");
				break;
			default:
				interfaz->opcionInvalida();
				break;
			}
			break;
		case 2:
			tipoEspecifico = interfaz->tipoMaterialDigital();
			switch (tipoEspecifico) {
			case 1:
				listaM = biblioteca->mostrarMaterialesClase("video digital");
				break;
			case 2:
				listaM = biblioteca->mostrarMaterialesClase("articulo digital");
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
		if (listaM.isEmpty()) {
			throw ObjectCreationException("No hay materiales de este tipo");
			system("pause");
		}
		else {
			std::cout << listaM.toString();
		}
		break;
	case 4:
		//biblioteca->mostrarPrestamosPorUsuario(interfaz->pedirDatos("cedula del usuario", false));
		std::cout<<biblioteca->mostrarPrestamosPorUsuario(interfaz->pedirDatos("cedula del usuario", false));
		break;
	case 5:
		std::cout << biblioteca->mostrarPrestamosPorMaterial(interfaz->pedirDatos("ID de Material", false));
		break;
	case 6:
		biblioteca->mostrarPrestamos();
		break;
	case 7:
		tipo = interfaz->tipoMaterial();
		switch (tipo) {
		case 1:
			tipoEspecifico = interfaz->tipoMaterialFisico();
			switch (tipoEspecifico) {
			case 1:
				std::cout << biblioteca->mostrarPrestamosPorClase("libro");
				break;
			case 2:
				std::cout << biblioteca->mostrarPrestamosPorClase("revista");
				break;
			case 3:
				std::cout << biblioteca->mostrarPrestamosPorClase("video fisico");
				break;
			case 4:
				std::cout << biblioteca->mostrarPrestamosPorClase("articulo fisico");
				break;
			default:
				interfaz->opcionInvalida();
				break;
			}
			break;
		case 2:
			tipoEspecifico = interfaz->tipoMaterialDigital();
			switch (tipoEspecifico) {
			case 1:
				std::cout << biblioteca->mostrarPrestamosPorClase("video digital");
				break;
			case 2:
				std::cout << biblioteca->mostrarPrestamosPorClase("articulo digital");
				break;
			default:
				interfaz->opcionInvalida();
				break;
			}
			break;
		}
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

void Controladora::MenuTiempo()
{
	int opcion = interfaz->subMenuTiempo();
	int* fecha;
	switch (opcion) {
	case 1:
		biblioteca->pasarDias(interfaz->pedirDias());
		break;
	case 2:
		biblioteca->volverDias(interfaz->pedirDias());
		break;
	case 3:
		fecha = interfaz->pedirFecha();
		biblioteca->setTime(fecha[0], fecha[1]);
		break;
	case 4:
		biblioteca->resetTime();
		break;
	default:
		interfaz->opcionInvalida();
		break;
	}
}

void Controladora::GuardarDatos()
{
	gestorArchivos->guardarUsuarios(biblioteca, "usuarios.csv");
	gestorArchivos->guardarTiempo(biblioteca, "tiempo.csv");
	gestorArchivos->guardarMateriales(biblioteca, "materiales.csv");
	gestorArchivos->guardarPrestamos(biblioteca->getListaPrestamos(), "prestamos.csv");

}

void Controladora::CargarDatos()
{
	std::cout << "Cargando datos..." << std::endl;
	gestorArchivos->cargarUsuarios(biblioteca, "usuarios.csv");
	gestorArchivos->cargarTiempo(biblioteca, "tiempo.csv");
	gestorArchivos->cargarMateriales(biblioteca, "materiales.csv");
	gestorArchivos->cargarPrestamos(biblioteca, "prestamos.csv");
	//interfaz->msj("Datos cargados correctamente");
	//system("pause");
}