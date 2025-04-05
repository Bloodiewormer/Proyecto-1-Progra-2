#pragma once
#include "MaterialFisico.h"
class ArticuloFisico : public MaterialFisico {
private:
	std::string tipoArticulo; // (Juego, heramienta, cualquier otro que no sea una clase creada)
public:
	ArticuloFisico(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string cantidad, std::string tipoMaterial, std::string estado, std::string tipoArticulo);
	~ArticuloFisico();
	std::string toString() const override;
};

