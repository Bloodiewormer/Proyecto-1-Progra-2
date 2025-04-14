#pragma once
#include <iostream>
#include <sstream>
#include "MaterialDigital.h"
class VideoDigital : public MaterialDigital
{
private:
	std::string duracion;
	std::string resolucion;
public:
	VideoDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, double tamano, int dias, std::string duracion, std::string resolucion);
	~VideoDigital();
	std::string toString() const override;
	std::string getTipo() override;
};

