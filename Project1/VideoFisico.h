#pragma once
#include <iostream>
#include <sstream>
#include "MaterialFisico.h"
class VideoFisico : public MaterialFisico
{
private:
	std::string formato; // (DVD, Blu-ray, etc)
	int duracion;
	std::string resolucion;
public:
	VideoFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoMaterial, std::string estado, int dias, std::string formato, int duracion, std::string resolucion);
	~VideoFisico();
	std::string toString() const override;
	std::string getTipo() override;
};

