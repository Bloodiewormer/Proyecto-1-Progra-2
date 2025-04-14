#pragma once
#include "Material.h"
class MaterialDigital : public Material{
protected:
	double tamano; // (en MB)
public:
	MaterialDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, double tamano, int dias);
	~MaterialDigital();
	virtual std::string toString() const = 0;
	virtual std::string getTipo() = 0;
};

