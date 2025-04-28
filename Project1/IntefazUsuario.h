#pragma once
#include <iostream>
#include <string>
#include "Usuario.h"
#include "Libro.h"
#include "ArticuloDigital.h"
#include "ArticuloFisico.h"
#include "VideoFisico.h"
#include "VideoDigital.h"
#include "Revista.h"
#include "CustomException.h"
#include "Utility.h"

class IntefazUsuario {
public:
    // ===========================
    // M�todos del men� principal
    // ===========================
    static void bannerBienvenida();
    static int mostrarMenuPrincipal();
    static int subMenuReportes();

    // ===========================
    // Submen�s de usuarios
    // ===========================
    static int mostrarSubMenuUsuario();
    static int mostrarSubMenuModificarUsuario();
    static Usuario* crearUsuario();

    // ===========================
    // Submen�s de materiales
    // ===========================
    static int mostrarSubMenuMateriales();
    static int tipoMaterial();
    static int tipoMaterialDigital();
    static int tipoMaterialFisico();
    static Libro* crearLibro();
    static ArticuloDigital* crearArticuloDigital();
    static ArticuloFisico* crearArticuloFisico();
    static VideoFisico* crearVideoFisico();
    static VideoDigital* crearVideoDigital();
    static Revista* crearRevista();

    // ===========================
    // Submen�s de pr�stamos
    // ===========================
    static int subMenuPrestamos();

    // ===========================
    // Submen�s de tiempo
    // ===========================
    static int subMenuTiempo();
    static int pedirDias();
    static int* pedirFecha();

    // ===========================
    // M�todos de utilidad
    // ===========================
   
    static bool ConfirmarSalida();
    static bool agregarOtro();
    static std::string pedirDatos(std::string dato, bool modificar);
    static bool pedirDatosBool(std::string dato);
    static void opcionInvalida();
   
};