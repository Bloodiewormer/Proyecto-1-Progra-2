#pragma once
#include "Material.h"
class Revista : public Material{
private:
	std::string volumen;
	std::string numero;
public:
	Revista(std::string identificador, std::string cantidad, std::string titulo, std::string autor, std::string palabrasClave, std::string tipoMaterial, std::string estado, std::string volumen, std::string numero);
	~Revista();
	std::string toString() const override;
};

