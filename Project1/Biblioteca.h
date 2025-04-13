#pragma once
#include <iostream>
#include "Lista.h"
#include "Usuario.h"
#include "Material.h"
#include "GestorPrestamo.h"
class Biblioteca{
private:
	Lista<Material> listaMateriales;
	Lista<Usuario> listaUsuarios;
	GestorPrestamo gestorPrestamos;
public:
	Biblioteca();
	~Biblioteca();

	//Metodos para gestionar materiales
	bool comprobarExistenciaMaterial(std::string ID);
	void agregarMaterial(Material* material);
	void mostrarMateriales();
	void eliminarMaterial(std::string ID);
	//Material* buscarMaterial(std::string ID);

	//Metodos para gestionar usuarios
	bool comprobarExistenciaUsuario(std::string ID);
	void agregarUsuario(Usuario* usuario);
	void mostrarUsuarios();
	void modificarUsuario(std::string ID,std::string change ,int opcion);
	void eliminarUsuario(std::string ID);
	Usuario* buscarUsuario(std::string ID);


	//Metodos para gestionar prestamos

	

	//metodos para guardar y cargar datos
	Lista<Usuario> getListaUsuarios();
};

