#pragma once
#include "MaterialFisico.h"
class ArticuloFisico : public MaterialFisico {
private:
	std::string tipoArticulo; // (Juego, heramienta, cualquier otro que no sea una clase creada)
public:
    ArticuloFisico(const std::string& id,
        const std::string& tit,
        const Lista<std::string>& palabras,
        const Lista<std::string>& auts,
        const std::string& tipoMaterial,
        const std::string& est,
        const std::string& tipoArt);
    ~ArticuloFisico();
	std::string toString() const override;
};

