#include "IntefazUsuario.h"

void IntefazUsuario::bannerBienvenida(){
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


int IntefazUsuario::mostrarMenuPrincipal(){
	int opcion;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "|                    MENU PRINCIPAL                  |" << std::endl;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "|  1. Menu Materiales                                |" << std::endl;
	std::cout << "|  2. Menu Usuarios                                  |" << std::endl;
	std::cout << "|  3. Menu Tiempo                                    |" << std::endl;
	std::cout << "|  4. Menu Prestamos                                 |" << std::endl;
	std::cout << "|  5. Guardar                                        |" << std::endl;
	std::cout << "|  6. Reportes                                       |" << std::endl;
	std::cout << "|  0. Salir                                          |" << std::endl;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = Utilidades::inputInt();
	return opcion;
}

int IntefazUsuario::subMenuReportes(){
	system("cls");
	int opcion;
	std::cout << "+------------------------------------------------------+" << std::endl;
	std::cout << "|                    MENU REPORTES                     |" << std::endl;
	std::cout << "+------------------------------------------------------+" << std::endl;
	std::cout << "|  1. Reporte de Materiales                            |" << std::endl;
	std::cout << "|  2. Reporte de Usuarios                              |" << std::endl;
	std::cout << "|  3. Reporte de Prestamos                             |" << std::endl;
	std::cout << "|  4. Historial de Prestamos por Usuario               |" << std::endl;
	std::cout << "|  5. Historial de Prestamos por Material              |" << std::endl;
	std::cout << "|  0. Salir                                            |" << std::endl;
	std::cout << "+------------------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = Utilidades::inputInt();
	return opcion;
}

int IntefazUsuario::mostrarSubMenuUsuario(){
	system("cls");
	int opcion;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "|                  MENU DE USUARIOS                  |" << std::endl;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "|  1. Agregar Usuario                                |" << std::endl;
	std::cout << "|  2. Modificar Usuario                              |" << std::endl;
	std::cout << "|  3. Eliminar Usuario                               |" << std::endl;
	std::cout << "|  4. Buscar Usuario                                 |" << std::endl;
	std::cout << "|  0. Salir                                          |" << std::endl;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = Utilidades::inputInt();
	return opcion;
}

int IntefazUsuario::mostrarSubMenuModificarUsuario(){
	system("cls");
	int opcion;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "|          MENU DE MODIFICACION DE USUARIO           |" << std::endl;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "|  1. Modificar Nombre                               |" << std::endl;
	std::cout << "|  2. Modificar Apellido                             |" << std::endl;
	std::cout << "|  3. Modificar Estado                               |" << std::endl;
	std::cout << "|  4. Modificar Cedula                               |" << std::endl;
	std::cout << "|  0. Salir                                          |" << std::endl;
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = Utilidades::inputInt();
	return opcion;
}

Usuario* IntefazUsuario::crearUsuario(){
	system("cls");
	std::string cedula, nombre, apellido;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|            CREAR NUEVO USUARIO              |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Ingrese la cedula del usuario: ";
	std::cin >> cedula;
	std::cout << "Ingrese el nombre del usuario: ";
	std::cin >> nombre;
	std::cout << "Ingrese el apellido del usuario: ";
	std::cin >> apellido;
	return new Usuario(cedula, nombre, apellido, true);
}

int IntefazUsuario::tipoMaterial(){
	system("cls");
	int opcion;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|           SELECCIONAR TIPO DE MATERIAL      |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|  1. Fisico                                  |" << std::endl;
	std::cout << "|  2. Digital                                 |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = Utilidades::inputInt();
	return opcion;
}

int IntefazUsuario::tipoMaterialDigital(){
	system("cls");
	int opcion;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|       SELECCIONAR TIPO DE MATERIAL DIGITAL  |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|  1. Video Digital                           |" << std::endl;
	std::cout << "|  2. Otro                                    |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = Utilidades::inputInt();
	return opcion;
}

int IntefazUsuario::tipoMaterialFisico(){
	system("cls");
	int opcion;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|       SELECCIONAR TIPO DE MATERIAL FISICO   |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|  1. Libro                                   |" << std::endl;
	std::cout << "|  2. Revista                                 |" << std::endl;
	std::cout << "|  3. Video Fisico                            |" << std::endl;
	std::cout << "|  4. Otro                                    |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = Utilidades::inputInt();
	return opcion;
}

Libro* IntefazUsuario::crearLibro(){
	system("cls");
	std::string identificador, titulo, isbn, editorial, tipoMaterial, estado;
	Lista<std::string> palabrasClave, autores;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|            CREAR NUEVO LIBRO                |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Identificador: "; std::cin >> identificador;
	std::cout << "Titulo: "; titulo = Utilidades::inputString();
	std::cout << "ISBN: "; std::cin >> isbn;
	std::cout << "Editorial: "; editorial = Utilidades::inputString();
	std::cout << "Tipo de Material: "; std::cin >> tipoMaterial;
	std::cout << "Estado: "; std::cin >> estado;
	palabrasClave = Utilidades::collectInputList("Palabras clave");
	autores = Utilidades::collectInputList("Autores");
	return new Libro(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, isbn, editorial);
}

ArticuloDigital* IntefazUsuario::crearArticuloDigital(){
	system("cls");
	std::string identificador, titulo, tipoArchivo, tipoArticulo;
	double tamano;
	Lista<std::string> palabrasClave, autores;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|        CREAR NUEVO ARTICULO DIGITAL         |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Identificador: "; std::cin >> identificador;
	std::cout << "Titulo: "; titulo = Utilidades::inputString();
	std::cout << "Tipo de Archivo: "; tipoArchivo = Utilidades::inputString();
	std::cout << "Tamano (MB): "; tamano = Utilidades::inputInt();
	std::cout << "Tipo de Articulo: "; tipoArticulo = Utilidades::inputString();
	palabrasClave = Utilidades::collectInputList("Palabras clave");
	autores = Utilidades::collectInputList("Autores");
	return new ArticuloDigital(identificador, titulo, palabrasClave, autores, tipoArchivo, tamano, tipoArticulo);
}

ArticuloFisico* IntefazUsuario::crearArticuloFisico(){
	system("cls");
	std::string identificador, titulo, tipoMaterial, estado, tipoArticulo;
	Lista<std::string> palabrasClave, autores;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|         CREAR NUEVO ARTICULO FISICO         |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Identificador: "; std::cin >> identificador;
	std::cout << "Titulo: "; titulo = Utilidades::inputString();
	std::cout << "Tipo de Material: "; tipoMaterial = Utilidades::inputString();
	std::cout << "Estado: "; estado = Utilidades::inputString();
	std::cout << "Tipo de Articulo: "; tipoArticulo = Utilidades::inputString();
	palabrasClave = Utilidades::collectInputList("Palabras clave");
	autores = Utilidades::collectInputList("Autores");
	return new ArticuloFisico(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, tipoArticulo);
}

VideoFisico* IntefazUsuario::crearVideoFisico(){
	system("cls");
	std::string identificador, titulo, tipoMaterial, estado, formato, resolucion;
	int duracion;
	Lista<std::string> palabrasClave, autores;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|           CREAR NUEVO VIDEO FISICO          |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Identificador: "; std::cin >> identificador;
	std::cout << "Titulo: "; titulo = Utilidades::inputString();
	std::cout << "Tipo de Material: "; tipoMaterial = Utilidades::inputString();
	std::cout << "Estado: "; estado = Utilidades::inputString();
	std::cout << "Formato: "; formato = Utilidades::inputString();
	std::cout << "Duracion (minutos): "; duracion = Utilidades::inputInt();
	std::cout << "Resolucion: "; resolucion = Utilidades::inputString();
	palabrasClave = Utilidades::collectInputList("Palabras clave (escriba 'fin' para terminar)");
	autores = Utilidades::collectInputList("Autores (escriba 'fin' para terminar)");
	return new VideoFisico(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, formato, duracion, resolucion);
}

VideoDigital* IntefazUsuario::crearVideoDigital()
{
	system("cls");
	std::string identificador, titulo, tipoArchivo, duracion, resolucion;
	double tamano;
	Lista<std::string> palabrasClave, autores;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|          CREAR NUEVO VIDEO DIGITAL          |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Identificador: "; std::cin >> identificador;
	std::cout << "Titulo: "; titulo = Utilidades::inputString();
	std::cout << "Tipo de Archivo: "; tipoArchivo = Utilidades::inputString();
	std::cout << "Tamano (MB): "; tamano = Utilidades::inputInt();
	std::cout << "Duracion: "; duracion = Utilidades::inputString();
	std::cout << "Resolucion: "; resolucion = Utilidades::inputString();
	palabrasClave = Utilidades::collectInputList("Palabras clave (escriba 'fin' para terminar)");
	autores = Utilidades::collectInputList("Autores (escriba 'fin' para terminar)");
	return new VideoDigital(identificador, titulo, palabrasClave, autores, tipoArchivo, tamano, duracion, resolucion);
}

Revista* IntefazUsuario::crearRevista(){
	system("cls");
	std::string identificador, titulo, tipoMaterial, estado, volumen, numero;
	Lista<std::string> palabrasClave, autores;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|             CREAR NUEVA REVISTA             |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Identificador: "; std::cin >> identificador;
	std::cout << "Titulo: "; titulo = Utilidades::inputString();
	std::cout << "Tipo de Material: "; tipoMaterial = Utilidades::inputString();
	std::cout << "Estado: "; estado = Utilidades::inputString();
	std::cout << "Volumen: "; volumen = Utilidades::inputString();
	std::cout << "Numero: "; numero = Utilidades::inputString();
	palabrasClave = Utilidades::collectInputList("Palabras clave (escriba 'fin' para terminar)");
	autores = Utilidades::collectInputList("Autores (escriba 'fin' para terminar)");
	return new Revista(identificador, titulo, palabrasClave, autores, tipoMaterial, estado, volumen, numero);
}

int IntefazUsuario::subMenuPrestamos(){
	system("cls");
	int opcion;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|              MENU DE PRESTAMOS              |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|  1. Registrar prestamo                      |" << std::endl;
	std::cout << "|  2. Devolver material                       |" << std::endl;
	std::cout << "|  0. Salir                                   |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = Utilidades::inputInt();
	return opcion;
}

int IntefazUsuario::subMenuTiempo(){
	system("cls");
	int opcion;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|               MENU DE TIEMPO                |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|  1. Pasar Dias                              |" << std::endl;
	std::cout << "|  2. Volver Dias                             |" << std::endl;
	std::cout << "|  3. Ir al Dia                               |" << std::endl;
	std::cout << "|  4. Resetear Tiempo                         |" << std::endl;
	std::cout << "|  0. Salir                                   |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Seleccione una opcion: ";
	opcion = Utilidades::inputInt();
	return opcion;
}

int IntefazUsuario::pedirDias(){
    system("cls");
    int dias;
    std::cout << "+---------------------------------------------+" << std::endl;
    std::cout << "|            INGRESAR CANTIDAD DE DIAS        |" << std::endl;
    std::cout << "+---------------------------------------------+" << std::endl;
    std::cout << "Ingrese la cantidad de dias: ";
    dias = Utilidades::inputInt();
    return dias;
}

int* IntefazUsuario::pedirFecha(){
	system("cls");
	int* fecha = new int[2];
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|              INGRESAR FECHA (DD MM)         |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Ingrese la fecha (dd mm): ";
	std::cin >> fecha[0] >> fecha[1];
	return fecha;
}


bool IntefazUsuario::ConfirmarSalida(){
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

bool IntefazUsuario::agregarOtro(){
	system("cls");
	std::string opcion;
	std::cout << "====================================================\n";
	std::cout << "||  Desea agregar otro material? (s/n)            ||\n";
	std::cout << "====================================================\n";
	std::cin >> opcion;
	return (opcion == "s" || opcion == "S") ? true : false;
	system("cls");
}

std::string IntefazUsuario::pedirDatos(std::string dato, bool modificar){
	system("cls");
	std::string datoIngresado;
	std::cout << "+---------------------------------------------+" << std::endl;
	if (modificar) {
	std::cout << "|         MODIFICAR " << dato << "                |" << std::endl;
	}
	else {
		std::cout << "|         INGRESAR " << dato << "                 |" << std::endl;
	}
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "Ingrese " << dato << ": ";
	std::cin >> datoIngresado;
	return datoIngresado; 
}


bool IntefazUsuario::pedirDatosBool(std::string dato){
	system("cls");
	std::string datoIngresado;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "|   INGRESAR " << dato << " (true/false)      |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	try {
		datoIngresado = Utilidades::inputBool();
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		system("pause");
		return false;
	}
}

void IntefazUsuario::opcionInvalida(){
	system("cls");
	std::cout << "+----------------------------------------------------+" << std::endl;
	std::cout << "|          Opcion Invalida, Intente de Nuevo         |" << std::endl;
	std::cout << "+----------------------------------------------------+" << std::endl;
	system("pause");
	system("cls");
}