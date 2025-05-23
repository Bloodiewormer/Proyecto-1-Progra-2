#pragma once
#include "Material.h"
class MaterialDigital : public Material{
protected:
	double tamano; // (en MB)
public:
	MaterialDigital(const std::string& id, 
		const std::string& tit, const Lista<std::string>& palabras, 
		const Lista<std::string>& auts, 
		const std::string& tipoArchivo,
		double sizeMB);
	~MaterialDigital();
	double getTamano();
	virtual std::string toString() const = 0;
	virtual std::string toStringCSV() const = 0;

};

