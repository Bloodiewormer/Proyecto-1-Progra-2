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
    void mostrarPrestamosPorUsuario(std::string);
    void mostrarPrestamosPorMaterial(std::string);
    Lista<Prestamo> getListaPrestamos();
};

