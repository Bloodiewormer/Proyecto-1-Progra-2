#pragma once
#include "MaterialFisico.h"
class Libro : public MaterialFisico {
private:
    std::string isbn;
    std::string editorial;
public:
    Libro(const std::string& id,
        const std::string& tit,
        const Lista<std::string>& palabras,
        const Lista<std::string>& auts,
        const std::string& tipoMaterial,
        const std::string& est,
        const std::string& isbn_,
        const std::string& edit);
    ~Libro();
    std::string toString() const override;
};