#pragma once
#include "MaterialDigital.h"
class Video : public MaterialDigital{
private:
	std::string duracion;
	std::string formato;
	std::string tipo;
	std::string tema;
public:
	Video(std::string identificador, std::string cantidad, std::string titulo, std::string autor, std::string palabrasClave, std::string tipoMaterial, std::string estado, std::string duracion, std::string formato, std::string tipo, std::string tema);
	~Video();
	std::string toString() const override;
};

