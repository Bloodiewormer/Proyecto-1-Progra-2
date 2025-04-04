#pragma once
#include "Material.h"


class Libro : public Material
{
private:
	std::string isbn;
	std::string editorial;
public:
	Libro(std::string identificador, std::string cantidad, std::string titulo, std::string autor, std::string palabrasClave, std::string tipoMaterial, std::string estado, std::string isbn, std::string editorial);
	~Libro();
	std::string toString() const override;

	
};

