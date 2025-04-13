#pragma once
#include <iostream>
#include <sstream>
#include "MaterialDigital.h"
class VideoDigital : public MaterialDigital
{
private:
	std::string duracion;
	std::string resolucion;
public:
    VideoDigital(const std::string& id,
        const std::string& tit,
        const Lista<std::string>& palabras,
        const Lista<std::string>& auts,
        const std::string& tipoArchivo,
        double sizeMB,
        const std::string& dur,
        const std::string& res);
	~VideoDigital();
	std::string toString() const override;
};