#include "IntefazUsuario.h"

void IntefazUsuario::bannerBienvenida()
{
	std::cout << "+-----------------------------------------------------+" << std::endl;
	std::cout << "|                                                     |" << std::endl;
	std::cout << "| (c) 2025                                            |" << std::endl;
	std::cout << "| EIF204 - Programación 2                             |" << std::endl;
	std::cout << "| 1er ciclo 2025                                      |" << std::endl;
	std::cout << "| NRC 9999 – Grupo 00                                 |" << std::endl;
	std::cout << "| Proyecto 1                                          |" << std::endl;
	std::cout << "|                                                     |" << std::endl;
	std::cout << "| 2-0854-0087; David Alberto Gonzalez Cordoba         |" << std::endl;
	std::cout << "| 4-0243-0410; Marisol Quiros Viquez                  |" << std::endl;
	std::cout << "|                                                     |" << std::endl;
	std::cout << "| versión 1.0.0 2025-04-01                            |" << std::endl;
	std::cout << "|                                                     |" << std::endl;
	std::cout << "+-----------------------------------------------------+" << std::endl;

}

void IntefazUsuario::DatosPrueba()
{

}

int IntefazUsuario::mostrarMenuPrincipal()
{
	system("cls");
	int opcion;
	std::cout << "Menu Principal" << std::endl;
	std::cout << "1. Agregar Material" << std::endl;
	std::cout << "2. Agregar Usuario" << std::endl;
	std::cout << "5. Mostrar Materiales" << std::endl;
	std::cout << "6. Mostrar Usuarios" << std::endl;
	std::cout << "7. Salir" << std::endl;
	std::cout << "Seleccione una opcion: ";
	std::cin >> opcion;
	return opcion;
}

Usuario* IntefazUsuario::crearUsuario()
{
	system("cls");
	//	std::string cedula;
	//std::string nombre;
	//std::string apellido;
	//bool estado;

	std::string cedula;
	std::string nombre;
	std::string apellido;
	bool estado;
	std::cout << "Ingrese la cedula del usuario: ";
	std::cin >> cedula;
	std::cout << "Ingrese el nombre del usuario: ";
	std::cin >> nombre;
	std::cout << "Ingrese el apellido del usuario: ";
	std::cin >> apellido;

	Usuario* usuario = new Usuario(cedula, nombre, apellido, true);
	return usuario;
}

int IntefazUsuario::tipoMaterial()
{
	system("cls");
	int opcion;
	std::cout << "Seleccione el tipo de material:" << std::endl;
	std::cout << "1. Fisico" << std::endl;
	std::cout << "2. Digital" << std::endl;
	std::cout << "Seleccione una opcion: ";
	std::cin >> opcion;
	return opcion;
}

int IntefazUsuario::tipoMaterialDigital()
{
	system("cls");
	int opcion;
	std::cout << "Seleccione el tipo de material digital:" << std::endl;
	std::cout << "1. Video Digital" << std::endl;
	std::cout << "2. Otro" << std::endl;
	std::cout << "Seleccione una opcion: ";
	std::cin >> opcion;
	return opcion;
}

int IntefazUsuario::tipoMaterialFisico()
{
	system("cls");
	int opcion;
	std::cout << "Seleccione el tipo de material fisico:" << std::endl;
	std::cout << "1. Libro" << std::endl;
	std::cout << "2. Revista" << std::endl;
	std::cout << "3. Video Fisico" << std::endl;
	std::cout << "4. Otro" << std::endl;
	std::cout << "Seleccione una opcion: ";
	std::cin >> opcion;
	return opcion;
}

Libro* IntefazUsuario::crearLibro()
{
	system("cls");
	return nullptr;
}
ArticuloDigital* IntefazUsuario::crearArticuloDigital()
{
	system("cls");
	return nullptr;
}

ArticuloFisico* IntefazUsuario::crearArticuloFisico()
{
	system("cls");
	return nullptr;
}

VideoFisico* IntefazUsuario::crearVideoFisico()
{
	system("cls");
	return nullptr;
}

VideoDigital* IntefazUsuario::crearVideoDigital()
{
	system("cls");
	return nullptr;
}

Revista* IntefazUsuario::crearRevista()
{
	system("cls");
	return nullptr;
}

bool IntefazUsuario::ConfirmarSalida()
{
	system("cls");
	std::string opcion;
	std::cout << "====================================================\n";
	std::cout << "||  Recuerde Guardar los Archivos antes de Salir  ||\n";
	std::cout << "||        Desea Salir del Programa? (s/n)         ||\n";
	std::cout << "====================================================\n";
	std::cin >> opcion;
	return (opcion == "s" || opcion == "S") ? true : false;
	system("cls");
}

void IntefazUsuario::msj(std::string mensaje)
{
	system("cls");
	size_t mensajeSize = mensaje.size();
	//need to ajust the size of the message to fit the box
	std::cout << "=====================================\n";
	if (mensajeSize < 30) {
		std::cout << "||    " << mensaje;
		for (int i = 0; i < 30 - mensajeSize; i++) {
			std::cout << " ";
		}
		std::cout << "||\n";
	}
	else {
		std::cout << "||    " << mensaje << "    ||\n";
	}
	std::cout << "||    Presione ENTER para continuar ||\n";
	std::cout << "=====================================\n";
	system("pause");
	system("cls");

}

void IntefazUsuario::opcionInvalida()
{
	system("cls");
	std::cout << "====================================================\n";
	std::cout << "||  Opcion Invalida, Presione ENTER para continuar  ||\n";
	std::cout << "====================================================\n";
	system("pause");
	system("cls");
}

