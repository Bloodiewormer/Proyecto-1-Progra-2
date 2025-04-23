#pragma once
#include <iostream>
#include "Lista.h"
#include "Prestamo.h"
#include "CustomException.h"

class GestorPrestamo{
private:
	Lista<Prestamo> listaPrestamos;

public:
    void registrarPrestamo(Time, Usuario*, Material*);
    void devolverMaterial(int, Time, std::string);
	Prestamo* buscarPrestamo(int idPrestamo);

    void mostrarPrestamos();
    void mostrarPrestamosPorUsuario(std::string idUsuario);
    void mostrarPrestamosPorMaterial(std::string idMaterial);

	void mostrarHistorialUsuario(std::string idUsuario);
	void mostrarHistorialMaterial(std::string idMaterial);



    //void guardarEnArchivo(std::string ruta);
    //void cargarDesdeArchivo(std::string ruta);

    Lista<Prestamo> getListaPrestamos();

};

