#pragma once
#include <iostream>
#include <sstream>
#include "MaterialFisico.h"
class VideoFisico : public MaterialFisico
{
private:
	std::string formato; // (DVD, Blu-ray, etc)
	int duracion;
	std::string resolucion;
public:
    VideoFisico(const std::string& id,
        const std::string& tit,
        const Lista<std::string>& palabras,
        const Lista<std::string>& auts,
        const std::string& tipoMaterial,
        const std::string& est,
        const std::string& form,
        int dur,
        const std::string& res);
	~VideoFisico();
	std::string toString() const override;
    std::string toStringCSV() const override;

};

