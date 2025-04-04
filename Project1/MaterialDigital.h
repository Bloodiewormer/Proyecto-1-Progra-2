#pragma once
#include "Material.h"
class MaterialDigital : public Material{
protected:
	std::string tipoArchivo; // (pdf, mp3, mp4, etc)
	std::string tamano; // (en MB)
public:
	MaterialDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, std::string tamano);
	~MaterialDigital();
};

