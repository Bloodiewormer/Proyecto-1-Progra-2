#include "IntefazUsuario.h"

void IntefazUsuario::bannerBienvenida()
{
	std::cout << "+-----------------------------------------------------+" << std::endl;
	std::cout << "|                                                     |" << std::endl;
	std::cout << "| (c) 2025                                            |" << std::endl;
	std::cout << "| EIF204 - Programación 2                             |" << std::endl;
	std::cout << "| 1er ciclo 2025                                      |" << std::endl;
	std::cout << "| NRC 41370 – Grupo 00                                |" << std::endl;
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
	int opcion;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "|                                                    |" << std::endl;
	std::cout << "|	1. Menu Materiales                           |" << std::endl;
	std::cout << "|	2. Menu Usuarios                             |" << std::endl;
	std::cout << "|	3. Menu Tiempo                               |" << std::endl;
	std::cout << "|	4. Menu Prestamos                            |" << std::endl;
	std::cout << "|	5. Guardar                                   |" << std::endl;
	std::cout << "|	6. Reportes                                  |" << std::endl;
	std::cout << "|	0. Salir                                     |" << std::endl;
	std::cout << "|                                                    |" << std::endl;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";

	opcion = inputInt();
	return opcion;
}

int IntefazUsuario::subMenuReportes()
{
	system("cls");
	int opcion;
	std::cout << "+------------------------------------------------------+" << std::endl;
	std::cout << "|                                                      |" << std::endl;
	std::cout << "|		1. Reporte de Materiales                         |" << std::endl;
	std::cout << "|		2. Reporte de Usuarios                           |" << std::endl;
	std::cout << "|		3. Reporte de Prestamos                          |" << std::endl;
	std::cout << "|		4. Reporte de Historial de Prestamos por Usuario |" << std::endl;
	std::cout << "|		5. Reporte de Historial de Prestamos por Material|" << std::endl;
	std::cout << "|		0. Salir                                         |" << std::endl;
	std::cout << "|                                                      |" << std::endl;
	std::cout << "+------------------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";

	opcion = inputInt();
	return opcion;
}

int IntefazUsuario::mostrarSubMenuUsuario()
{
	system("cls");
	int opcion;
	std::cout << "Menu de Usuario" << std::endl;
	std::cout << "1. Agregar Usuario" << std::endl;
	std::cout << "2. Modificar Usuario" << std::endl;
	std::cout << "3. Eliminar Usuario" << std::endl;
	std::cout << "4. Buscar Usuario" << std::endl;
	std::cout << "0. Salir" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = inputInt();
	return opcion;
}

int IntefazUsuario::mostrarSubMenuModificarUsuario()
{
	system("cls");
	int opcion;
	std::cout << "Menu de Modificacion de Usuario" << std::endl;
	std::cout << "1. Modificar Nombre" << std::endl;
	std::cout << "2. Modificar Apellido" << std::endl;
	std::cout << "3. Modificar Estado" << std::endl;
	std::cout << "4. Modificar Cedula" << std::endl;
	std::cout << "0. Salir" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = inputInt();
	return opcion;
}

Usuario* IntefazUsuario::crearUsuario()
{
	system("cls");

	std::string cedula;
	std::string nombre;
	std::string apellido;
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
	opcion = inputInt();
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
	opcion = inputInt();
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
	opcion = inputInt();
	return opcion;
}

Libro* IntefazUsuario::crearLibro()
{
	//Libro(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoMaterial, std::string estado, int dias, std::string isbn, std::string editorial);
	//ask for the data

	system("cls");
	std::string identificador;
	std::string titulo;
	Lista<std::string> palabrasClave;
	Lista<std::string> autores;
	std::string tipoMaterial;
	std::string estado;
	std::string isbn;
	std::string editorial;
	std::cout << "Ingrese el identificador del libro: ";
	std::cin >> identificador;
	std::cout << "Ingrese el titulo del libro: ";
	std::cin >> titulo;
	//lista de palabras clave
	std::cout << "Ingrese las palabras clave del libro: ";
	std::string palabra;
	while (true) {
		std::cout << "Ingrese una palabra clave: ";
		std::cin >> palabra;
		palabrasClave.addBegin(new std::string(palabra));
		std::cout << "Desea agregar otra palabra clave? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}

	std::cout << "Ingrese los autores del libro: ";
	std::string autor;
	while (true) {
		std::cout << "Ingrese un autor: ";
		std::cin >> autor;
		autores.addBegin(new std::string(autor));
		std::cout << "Desea agregar otro autor? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese el tipo de material del libro: ";
	std::cin >> tipoMaterial;
	std::cout << "Ingrese el estado del libro: ";
	std::cin >> estado;
	std::cout << "Ingrese el isbn del libro: ";
	std::cin >> isbn;
	std::cout << "Ingrese la editorial del libro: ";
	std::cin >> editorial;
	Libro* libro = new Libro(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, isbn, editorial);
	return libro;
}
ArticuloDigital* IntefazUsuario::crearArticuloDigital()
{
//ArticuloDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, double tamano, int dias, std::string TipoArticulo);
	
	system("cls");
	std::string identificador;
	std::string titulo;
	Lista<std::string> palabrasClave;
	Lista<std::string> autores;
	std::string tipoArchivo;
	double tamano;
	std::string TipoArticulo;
	std::cout << "Ingrese el identificador del articulo: ";
	std::cin >> identificador;
	std::cout << "Ingrese el titulo del articulo: ";
	std::cin >> titulo;
	//lista de palabras clave
	std::cout << "Ingrese las palabras clave del articulo: ";
	std::string palabra;
	while (true) {
		std::cout << "Ingrese una palabra clave: ";
		std::cin >> palabra;
		palabrasClave.addBegin(new std::string(palabra));
		std::cout << "Desea agregar otra palabra clave? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese los autores del articulo: ";
	std::string autor;
	while (true) {
		std::cout << "Ingrese un autor: ";
		std::cin >> autor;
		autores.addBegin(new std::string(autor));
		std::cout << "Desea agregar otro autor? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese el tipo de archivo del articulo: ";
	std::cin >> tipoArchivo;
	std::cout << "Ingrese el tamano del articulo: ";
	std::cin >> tamano;
	std::cout << "Ingrese el tipo de articulo: ";
	std::cin >> TipoArticulo;
	return new ArticuloDigital(identificador, titulo, palabrasClave, autores, tipoArchivo, tamano, TipoArticulo);
}

ArticuloFisico* IntefazUsuario::crearArticuloFisico()
{
	//ArticuloFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoMaterial, std::string estado, int dias, std::string tipoArticulo);

	system("cls");
	std::string identificador;
	std::string titulo;
	Lista<std::string> palabrasClave;
	Lista<std::string> autores;
	std::string tipoMaterial;
	std::string estado;
	std::string tipoArticulo;
	std::cout << "Ingrese el identificador del articulo: ";
	std::cin >> identificador;
	std::cout << "Ingrese el titulo del articulo: ";
	std::cin >> titulo;
	//lista de palabras clave
	std::cout << "Ingrese las palabras clave del articulo: ";
	std::string palabra;
	while (true) {
		std::cout << "Ingrese una palabra clave: ";
		std::cin >> palabra;
		palabrasClave.addBegin(new std::string(palabra));
		std::cout << "Desea agregar otra palabra clave? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese los autores del articulo: ";
	std::string autor;
	while (true) {
		std::cout << "Ingrese un autor: ";
		std::cin >> autor;
		autores.addBegin(new std::string(autor));
		std::cout << "Desea agregar otro autor? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese el tipo de material del articulo: ";
	std::cin >> tipoMaterial;
	std::cout << "Ingrese el estado del articulo: ";
	std::cin >> estado;
	std::cout << "Ingrese el tipo de articulo: ";
	std::cin >> tipoArticulo;
	return new ArticuloFisico(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, tipoArticulo);

}

VideoFisico* IntefazUsuario::crearVideoFisico()
{
	//VideoFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoMaterial, std::string estado, int dias, std::string formato, int duracion, std::string resolucion);
	system("cls");
	std::string identificador;
	std::string titulo;
	Lista<std::string> palabrasClave;
	Lista<std::string> autores;
	std::string tipoMaterial;
	std::string estado;
	std::string formato;
	int duracion;
	std::string resolucion;
	std::cout << "Ingrese el identificador del video: ";
	std::cin >> identificador;
	std::cout << "Ingrese el titulo del video: ";
	std::cin >> titulo;
	//lista de palabras clave
	std::cout << "Ingrese las palabras clave del video: ";
	std::string palabra;
	while (true) {
		std::cout << "Ingrese una palabra clave: ";
		std::cin >> palabra;
		palabrasClave.addBegin(new std::string(palabra));
		std::cout << "Desea agregar otra palabra clave? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese los autores del video: ";
	std::string autor;
	while (true) {
		std::cout << "Ingrese un autor: ";
		std::cin >> autor;
		autores.addBegin(new std::string(autor));
		std::cout << "Desea agregar otro autor? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese el tipo de material del video: ";
	std::cin >> tipoMaterial;
	std::cout << "Ingrese el estado del video: ";
	std::cin >> estado;
	std::cout << "Ingrese el formato del video: ";
	std::cin >> formato;
	std::cout << "Ingrese la duracion del video: ";
	duracion = inputInt();
	std::cout << "Ingrese la resolucion del video: ";
	std::cin >> resolucion;
	return new VideoFisico(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, formato, duracion, resolucion);


}

VideoDigital* IntefazUsuario::crearVideoDigital()
{
	//VideoDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, double tamano, int dias, std::string duracion, std::string resolucion);

	system("cls");
	std::string identificador;
	std::string titulo;
	Lista<std::string> palabrasClave;
	Lista<std::string> autores;
	std::string tipoArchivo;
	double tamano;
	std::string duracion;
	std::string resolucion;
	std::cout << "Ingrese el identificador del video: ";
	std::cin >> identificador;
	std::cout << "Ingrese el titulo del video: ";
	std::cin >> titulo;
	//lista de palabras clave
	std::cout << "Ingrese las palabras clave del video: ";
	std::string palabra;
	while (true) {
		std::cout << "Ingrese una palabra clave: ";
		std::cin >> palabra;
		palabrasClave.addBegin(new std::string(palabra));
		std::cout << "Desea agregar otra palabra clave? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese los autores del video: ";
	std::string autor;
	while (true) {
		std::cout << "Ingrese un autor: ";
		std::cin >> autor;
		autores.addBegin(new std::string(autor));
		std::cout << "Desea agregar otro autor? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese el tipo de archivo del video: ";
	std::cin >> tipoArchivo;
	std::cout << "Ingrese el tamano del video: ";
	tamano = inputInt();
	std::cout << "Ingrese la duracion del video: ";
	std::cin >> duracion;
	std::cout << "Ingrese la resolucion del video: ";
	std::cin >> resolucion;
	return new VideoDigital(identificador, titulo, palabrasClave, autores, tipoArchivo, tamano, duracion, resolucion);

}

Revista* IntefazUsuario::crearRevista()
{
	//Revista(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoMaterial, std::string estado, int dias, std::string volumen, std::string numero);

	system("cls");
	std::string identificador;
	std::string titulo;
	Lista<std::string> palabrasClave;
	Lista<std::string> autores;
	std::string tipoMaterial;
	std::string estado;
	std::string volumen;
	std::string numero;
	std::cout << "Ingrese el identificador de la revista: ";
	std::cin >> identificador;
	std::cout << "Ingrese el titulo de la revista: ";
	std::cin >> titulo;
	//lista de palabras clave
	std::cout << "Ingrese las palabras clave de la revista: ";
	std::string palabra;
	while (true) {
		std::cout << "Ingrese una palabra clave: ";
		std::cin >> palabra;
		palabrasClave.addBegin(new std::string(palabra));
		std::cout << "Desea agregar otra palabra clave? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese los autores de la revista: ";
	std::string autor;
	while (true) {
		std::cout << "Ingrese un autor: ";
		std::cin >> autor;
		autores.addBegin(new std::string(autor));
		std::cout << "Desea agregar otro autor? (s/n): ";
		std::string opcion;
		std::cin >> opcion;
		if (opcion == "n" || opcion == "N") {
			break;
		}
	}
	std::cout << "Ingrese el tipo de material de la revista: ";
	std::cin >> tipoMaterial;
	std::cout << "Ingrese el estado de la revista: ";
	std::cin >> estado;
	std::cout << "Ingrese el volumen de la revista: ";
	std::cin >> volumen;
	std::cout << "Ingrese el numero de la revista: ";
	std::cin >> numero;
	return new Revista(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, volumen, numero);

}

int IntefazUsuario::subMenuPrestamos()
{
	system("cls");
	int opcion;
	std::cout << "Menu de Prestamos" << std::endl;
	std::cout << "1. Registrar prestamo" << std::endl;
	std::cout << "2. Devolver material" << std::endl;
	std::cout << "0. Salir" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = inputInt();
	return opcion;
}

int IntefazUsuario::subMenuTiempo()
{
	system("cls");
	int opcion;
	std::cout << "Menu de Tiempo" << std::endl;
	std::cout << "1. Pasar Dias" << std::endl;
	std::cout << "2. Volver Dias" << std::endl;
	std::cout << "3. Ir al Dia" << std::endl;
	std::cout << "4. Resetear Tiempo" << std::endl;
	std::cout << "0. Salir" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = inputInt();
	return opcion;
}

int IntefazUsuario::pedirDias()
{
	system("cls");
	int dias;
	std::cout << "Ingrese la cantidad de dias: ";
	dias = inputInt();
	return dias;
}

int* IntefazUsuario::pedirFecha()
{
	system("cls");
	int* fecha = new int[2];
	std::cout << "Ingrese la fecha (dd mm): ";
	std::cin >> fecha[0] >> fecha[1];
	return fecha;
	

}


int IntefazUsuario::inputInt()
{	int input;
	std::cin >> input;
	if (std::cin.fail()) {
		std::cin.clear(); // clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the invalid input,
		throw InvalidInputException("Invalid input, please enter a number");
	}
	return input;
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

bool IntefazUsuario::agregarOtro()
{
	system("cls");
	std::string opcion;
	std::cout << "====================================================\n";
	std::cout << "||  Desea agregar otro material? (s/n)            ||\n";
	std::cout << "====================================================\n";
	std::cin >> opcion;
	return (opcion == "s" || opcion == "S") ? true : false;
	system("cls");
}

std::string IntefazUsuario::pedirDatos(std::string dato, bool modificar)
{
	system("cls");
	std::string datoIngresado;
	if (modificar) {
		std::cout << "Ingrese " << dato << " a modificar: ";
	}
	else {
		std::cout << "Ingrese " << dato << ": ";
	}
	std::cin >> datoIngresado;
	return datoIngresado;

}


bool IntefazUsuario::pedirDatosBool(std::string dato)
{
	system("cls");
	std::string datoIngresado;
	std::cout << "Ingrese el " << dato << " a modificar: ";
	std::cout << "(true/false): ";
	std::cin >> datoIngresado;
	if (datoIngresado == "true" || datoIngresado == "True" || datoIngresado == "TRUE") {
		return true;
	}
	else if (datoIngresado == "false" || datoIngresado == "False" || datoIngresado == "FALSE") {
		return false;
	}
	else {
		return false;
	}
}

void IntefazUsuario::msj(std::string mensaje)
{
	system("cls");
	size_t mensajeSize = mensaje.size(); //size_t es un tipo de dato que representa el tamaño de un objeto en bytes
	//need to ajust the size of the message to fit the box

	

    if (mensajeSize < 30) {  
       std::cout << "=====================================\n";  
       std::cout << "||    " << mensaje;  
       for (int i = 0; i < 30 - mensajeSize; i++) {  
           std::cout << " ";  
       }  
       std::cout << "||\n";  
    } else {  
       size_t lineWidth = 30;  
       std::cout << "=====================================\n";  
       for (size_t i = 0; i < mensajeSize; i += lineWidth) {  
           std::cout << "|| ";  
           std::cout << mensaje.substr(i, lineWidth);  
           size_t remaining = lineWidth - mensaje.substr(i, lineWidth).size();  
           for (size_t j = 0; j < remaining; j++) {  
               std::cout << " ";  
           }  
           std::cout << " ||\n";  
       }  
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

