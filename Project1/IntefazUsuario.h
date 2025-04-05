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



class IntefazUsuario{
public:

	static void bannerBienvenida();
	static void DatosPrueba();
	static int mostrarMenuPrincipal();
	static int mostrarSubMenuUsuario();
	static int mostrarSubMenuModificarUsuario();
	static Usuario* crearUsuario();
	static int tipoMaterial();
	static int tipoMaterialDigital();
	static int tipoMaterialFisico();
	static Libro* crearLibro();
	static ArticuloDigital* crearArticuloDigital();
	static ArticuloFisico* crearArticuloFisico();
	static VideoFisico* crearVideoFisico();
	static VideoDigital* crearVideoDigital();
	static Revista* crearRevista();
	static bool ConfirmarSalida();
	static std::string pedirDatos(std::string dato, bool modificar);
	static bool pedirDatosBool(std::string dato);
	static void msj(std::string mensaje);
	static void opcionInvalida();

};

