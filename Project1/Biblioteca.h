#pragma once
#include <iostream>
#include <sstream>
#include "Lista.h"
#include "Usuario.h"
#include "Material.h"
#include "GestorPrestamo.h"
#include "CustomException.h"
#include "Time.h"
<<<<<<< HEAD
#include "Utility.h"
=======
#include "Libro.h"
#include "ArticuloDigital.h"
#include "ArticuloFisico.h"
#include "VideoFisico.h"
#include "VideoDigital.h"
#include "Revista.h"
>>>>>>> 879200a1e6ae1a4c512d2d0f3c2ab6fb014cd04e
class Biblioteca{
private:
	Lista<Material> listaMateriales;
	Lista<Usuario> listaUsuarios;
	GestorPrestamo gestorPrestamos;
	Time currentTime;
public:
	Biblioteca();
	~Biblioteca();
	//Metodos para gestionar materiales
	bool comprobarExistenciaMaterial(std::string ID);
	void agregarMaterial(Material* material);
	void mostrarMateriales();
	Lista<Material> mostrarMaterialesClase(std::string tipo);
	void eliminarMaterial(std::string ID);
	Material* buscarMaterial(std::string ID);
	void agregarCopiaMaterial(std::string ID, std::string newID);
	//Metodos para gestionar usuarios
	bool comprobarExistenciaUsuario(std::string ID);
	void agregarUsuario(Usuario* usuario);
	void mostrarUsuarios();
	void modificarUsuario(std::string ID,std::string change ,int opcion);
	void eliminarUsuario(std::string ID);
	Usuario* buscarUsuario(std::string ID);
	//Metodos para gestionar prestamos
	void registrarPrestamo(std::string, std::string);
	void registrarPrestamoCreado(Prestamo* p);
	void devolverMaterial(int idPrestamo, std::string);
	void mostrarPrestamos();
	std::string mostrarPrestamosPorUsuario(std::string id);
	std::string mostrarPrestamosPorMaterial(std::string id);
	std::string mostrarPrestamosPorClase(std::string tipo);
	

	//Metodos tiempos
	Time getCurrentTime();
	void pasarDias(int dias);
	void volverDias(int dias);
	void resetTime();
	void setTime(int dia, int mes);


	//metodos para guardar y cargar datos
	Lista<Usuario> getListaUsuarios();	
	Lista<Material> getListaMateriales();
	Lista<Prestamo> getListaPrestamos();
};