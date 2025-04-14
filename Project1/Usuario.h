#pragma once
#include"Lista.h"
#include <iostream>
#include <sstream>

class Usuario{
private:
	std::string cedula;
	std::string nombre;
	std::string apellido;
	bool estado;
	Lista<std::string> historial; // Lista de materiales prestados
public:
	Usuario(std::string cedula, std::string nombre, std::string apellido, bool estado);
	~Usuario();
	std::string getCedula() const;
	bool getEstado() const;
	void setEstado(bool estado);
	std::string toString() const;
	std::string toCSV() const;
	//setters
	void setCedula(std::string cedula);
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	
	void agregarHistorial(const std::string&);
	void mostrarHistorial();

	//sobrecarga de operador
	friend std::ostream& operator<<(std::ostream& os, const Usuario& usuario);
};

