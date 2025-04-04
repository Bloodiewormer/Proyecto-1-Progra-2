#pragma once
#include <iostream>
#include <sstream>
#include "Material.h"
class MaterialFisico : public Material
{
protected:
	std::string cantidad;
	std::string tipoMaterial;
	std::string estado;//(buen estado, regular, malo)
public:
	MaterialFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string cantidad, std::string tipoMaterial, std::string estado);
	~MaterialFisico();
};

