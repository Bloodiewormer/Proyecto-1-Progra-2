#pragma once
#include <iostream>
#include <sstream>

class Usuario{
private:
	std::string cedula;
	std::string nombre;
	std::string apellido;
	bool estado;
public:
	Usuario(std::string cedula, std::string nombre, std::string apellido, bool estado);
	~Usuario();
	std::string getCedula() const;
	bool getEstado() const;
	void setEstado(bool estado);
	std::string toString() const;
	//setters
	void setCedula(std::string cedula);
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	

	//sobrecarga de operador
	//friend std::ostream& operator<<(std::ostream& os, const Usuario& usuario);	
};

