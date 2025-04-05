#pragma once
#include <iostream>
#include "Lista.h"
#include "Usuario.h"
#include "Material.h"
#include "GestorPrestamo.h"
class Biblioteca{
private:
	Lista<Material*> listaMateriales;
	Lista<Usuario*> listaUsuarios;
	GestorPrestamo gestorPrestamos;
public:
	Biblioteca();
	~Biblioteca();
	void agregarMaterial(Material* material);
	void agregarUsuario(Usuario* usuario);



	//void guardarDatos(); // Guardar datos en un archivo
	//void cargarDatos(); // Cargar datos desde un archivo
};

