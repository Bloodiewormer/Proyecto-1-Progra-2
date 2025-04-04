#pragma once
#include "MaterialFisico.h"

class Libro : public MaterialFisico{
private:
	std::string isbn;
	std::string editorial;
public:
	Libro(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string cantidad, std::string tipoMaterial, std::string estado, std::string isbn, std::string editorial);
	~Libro();
	std::string toString() const override;
	
};

