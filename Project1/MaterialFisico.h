#pragma once
#include <iostream>
#include <sstream>
#include "Material.h"
class MaterialFisico : public Material
{
protected:
	std::string estado;//(buen estado, regular, malo)
public:
	MaterialFisico(const std::string& id, 
		const std::string& tit,
		const Lista<std::string>& palabras,
		const Lista<std::string>& auts,
		const std::string& tipoMaterial,
		const std::string& est);
	virtual ~MaterialFisico();

	std::string getEstado();

	virtual std::string toString() const = 0;
	virtual std::string toStringCSV() const = 0;
};

