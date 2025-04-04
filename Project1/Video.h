#pragma once
#include "Material.h"
class Video : public Material{
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

