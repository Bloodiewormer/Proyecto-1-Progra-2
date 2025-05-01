#pragma once
#include <iostream>
#include "Lista.h"
#include "Prestamo.h"
#include "CustomException.h"
#include "Utility.h"

class GestorPrestamo{
private:
	Lista<Prestamo> listaPrestamos;

public:
    void registrarPrestamo(Time, Usuario*, Material*);
    void registrarPrestamoCreado(Prestamo* p);
    
    void devolverMaterial(int, Time, std::string);
	Prestamo* buscarPrestamo(int idPrestamo);

    void mostrarPrestamos();
   // void mostrarPrestamosPorUsuario(std::string idUsuario);
   //void mostrarPrestamosPorMaterial(std::string idMaterial);
	Lista<Prestamo> mostrarPrestamosPorUsuario(std::string idUsuario);
	Lista<Prestamo> mostrarPrestamosPorMaterial(std::string idMaterial);

	Lista<Prestamo> MostrarPrestamosClase(std::string tipo);
	void mostrarHistorialUsuario(std::string idUsuario);
	void mostrarHistorialMaterial(std::string idMaterial);

    Lista<Prestamo> getListaPrestamos();

};

