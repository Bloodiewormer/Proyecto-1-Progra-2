#include "VideoFisico.h"




VideoFisico::VideoFisico(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoMaterial, const std::string& est, const std::string& form, int dur, const std::string& res)
	: MaterialFisico(id, tit, palabras, auts, tipoMaterial, est),formato(form), duracion(dur), resolucion(res) {
	diasPrestamo = DIAS_PRESTAMO_VIDEO;
}

VideoFisico::~VideoFisico()
{
	// Destructor
}

std::string VideoFisico::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Video Fisico: " << std::endl;
	oss << "Identificador: " << identificador << std::endl;
	oss << "Titulo: " << titulo << std::endl;
	for (int i = 0; i < autores.getLength(); i++)
	{
		oss << "Autor: " << autores.get(i) << std::endl;
	}
	oss << "Palabras Clave: " << std::endl;
	for (int i = 0; i < palabrasClave.getLength(); i++)
	{
		oss << "Palabra Clave: " << palabrasClave.get(i) << std::endl;
	}
	oss << "Tipo de Material: " << tipo << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "Formato: " << formato << std::endl;
	oss << "Duracion: " << duracion << std::endl;
	oss << "Resolucion: " << resolucion << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}
