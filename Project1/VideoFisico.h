#pragma once
#include <iostream>
#include <sstream>
#include "MaterialFisico.h"
class VideoFisico : public MaterialFisico
{
private:
	std::string formato; // (DVD, Blu-ray, etc)
	std::string duracion;
	std::string resolucion;
public:
	VideoFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string cantidad, std::string tipoMaterial, std::string estado, std::string formato, std::string duracion, std::string resolucion);
	~VideoFisico();
	std::string toString() const override;

};

