#pragma once
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Libro.h"
#include "ArticuloDigital.h"
#include "ArticuloFisico.h"
#include "VideoFisico.h"
#include "videoDigital.h"
#include "revista.h"
#include "CustomException.h"
class IntefazUsuario{
public:
	//menu principal
	static void bannerBienvenida();
	static void DatosPrueba();
	static int mostrarMenuPrincipal();
	static int subMenuReportes();
	//submenus de usuarios
	static int mostrarSubMenuUsuario();
	static int mostrarSubMenuModificarUsuario();
	static Usuario* crearUsuario();
	//submenus de materiales
	static int tipoMaterial();
	static int tipoMaterialDigital();
	static int tipoMaterialFisico();
	static Libro* crearLibro();
	static ArticuloDigital* crearArticuloDigital();
	static ArticuloFisico* crearArticuloFisico();
	static VideoFisico* crearVideoFisico();
	static VideoDigital* crearVideoDigital();
	static Revista* crearRevista();

	//submenus de prestamos
	static int subMenuPrestamos();

	//submenus de tiempo

	static int subMenuTiempo();
	static int pedirDias();
    static int* pedirFecha();


	//metodos de utilidad
	static int inputInt();
	static bool ConfirmarSalida();
	static bool agregarOtro();
	static std::string pedirDatos(std::string dato, bool modificar);
	static bool pedirDatosBool(std::string dato);
	static void msj(std::string mensaje);
	static void opcionInvalida();
};

