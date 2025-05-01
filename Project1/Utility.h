#pragma once
#include <iostream>
#include <string>
#include "Lista.h"

//patra incluir las clases de materiales
#include "Libro.h"
#include "Revista.h"
#include "ArticuloFisico.h"
#include "ArticuloDigital.h"
#include "VideoFisico.h"
#include "VideoDigital.h"



#include "CustomException.h"


class Utilidades {
public:
    // Limpia la pantalla (compatible con múltiples plataformas)
    static void limpiarPantalla();

    // Muestra un mensaje formateado
    static void msj(const std::string& mensaje);

    // Lee un entero con manejo de errores
    static int inputInt();

    // Lee una línea completa de texto
    static std::string inputString();

	// Recoge una lista de entradas de texto
    static Lista<std::string> collectInputList(const std::string& prompt) ;

	// lee un booleano
	static bool inputBool();
};