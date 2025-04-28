#pragma once
#include "MaterialFisico.h"
class Revista : public MaterialFisico{
private:
	std::string volumen;
	std::string numero;
public:
    Revista(const std::string& id,
        const std::string& tit,
        const Lista<std::string>& palabras,
        const Lista<std::string>& auts,
        const std::string& tipoMaterial,
        const std::string& est,
        const std::string& vol,
        const std::string& num);
    ~Revista();
    std::string getVolumen();
    std::string getNumero();
	std::string toString() const override;
    std::string toStringCSV() const override;
};

