#pragma once 
#include "MaterialDigital.h"
class ArticuloDigital : public MaterialDigital {
private:
	std::string TipoArticulo;
public:
    ArticuloDigital(const std::string& id,
        const std::string& tit,
        const Lista<std::string>& palabras,
        const Lista<std::string>& auts,
        const std::string& tipoArchivo,
        double sizeMB,
        const std::string& tipoArt);
	~ArticuloDigital();
	std::string toString() const override;
    std::string toStringCSV() const override;
    
};

