#pragma once
#include <iostream>
#include <sstream>
class Material
{
protected:
	std::string identificador;
	std::string cantidad;
	std::string titulo;
	std::string autor;//implementar para mas de un autor podemos usar un vector o aprovechar la clase lista
	std::string palabrasClave;//implementar para mas de una palabra clave podemos usar un vector o aprovechar la clase lista
	std::string tipoMaterial;
	std::string estado;//(buen estado, regular, malo)
public:
	Material(std::string identificador, std::string cantidad, std::string titulo, std::string autor, std::string palabrasClave, std::string tipoMaterial, std::string estado);
	~Material();
	virtual std::string toString() const = 0;
};
	

