#pragma once 
#include "MaterialDigital.h"

class ArticuloDigital : public MaterialDigital {
private:
	std::string TipoArticulo;
public:
	ArticuloDigital(std::string identificador, std::string titulo, Lista<std::string> palabrasClave, Lista<std::string> autores, std::string tipoArchivo, std::string tamano, std::string tipoArticulo);
	~ArticuloDigital();
	std::string toString() const;


	

};

