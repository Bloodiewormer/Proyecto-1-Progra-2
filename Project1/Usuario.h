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
};

