#pragma once 
#include "MaterialDigital.h"

class ArticuloDigital : public MaterialDigital {
private:
	std::string TipoArticulo;
public:
	ArticuloDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, double tamano, int dias, std::string TipoArticulo);
	
	~ArticuloDigital();
	std::string toString() const override;


	

};

