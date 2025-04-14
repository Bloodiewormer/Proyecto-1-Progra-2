#pragma once
#include "MaterialFisico.h"

class Revista : public MaterialFisico{
private:
	std::string volumen;
	std::string numero;
public:
	Revista(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoMaterial, std::string estado, int dias, std::string volumen, std::string numero);
	~Revista();
	std::string toString() const override;
	std::string getTipo() override;
};

