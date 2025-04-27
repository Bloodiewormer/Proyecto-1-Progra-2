#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "CustomException.h"
#include "Usuario.h"
#include "Lista.h"
#include "Libro.h"
#include "ArticuloDigital.h"
#include "ArticuloFisico.h"
#include "VideoFisico.h"
#include "videoDigital.h"
#include "revista.h"
#include "Biblioteca.h"
class GestorArchivos {
public:
	static void guardarUsuarios(Biblioteca* biblioteca, const std::string& nombreArchivo);
	static void guardarTiempo(Biblioteca* biblioteca, const std::string& nombreArchivo);
	static void guardarMateriales(Biblioteca* biblioteca, const std::string& nombreArchivo);
	static void guardarPrestamos(const Lista<Prestamo>& listaPrestamos, const std::string& nombreArchivo);
	static void cargarUsuarios(Biblioteca* biblioteca, const std::string& nombreArchivo);
	static void cargarTiempo(Biblioteca* biblioteca, const std::string& nombreArchivo);
	static void cargarMateriales(Biblioteca* biblioteca, const std::string& nombreArchivo);
	static void cargarPrestamos(Biblioteca* biblioteca, const std::string& nombreArchivo);
};