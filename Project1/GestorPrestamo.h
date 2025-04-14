#pragma once
#include <iostream>
#include "Lista.h"
#include "Prestamo.h"

class GestorPrestamo{
private:
	Lista<Prestamo> listaPrestamos;

public:
    void registrarPrestamo(std::string, Usuario*, Material*);
    void devolverMaterial(std::string, std::string, std::string);

    void mostrarPrestamos();
    void mostrarPrestamosPorUsuario(std::string idUsuario);
    void mostrarPrestamosPorMaterial(std::string idMaterial);

    //void guardarEnArchivo(std::string ruta);
    //void cargarDesdeArchivo(std::string ruta);

};

