#include "VideoFisico.h"




VideoFisico::VideoFisico(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoMaterial, const std::string& est, const std::string& form, int dur, const std::string& res)
	: MaterialFisico(id, tit, palabras, auts, tipoMaterial, est),formato(form), duracion(dur), resolucion(res) {
	diasPrestamo = DIAS_PRESTAMO_VIDEO;
}

std::string VideoFisico::getFormato()
{
	return formato;
}

int VideoFisico::getDuracion()
{
	return duracion;
}

std::string VideoFisico::getResolucion()
{
	return resolucion;
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
	oss << "Autores: " << std::endl;
	oss << autores.toString();
	oss << "Palabras Clave: " << std::endl;
	oss << palabrasClave.toString();
	oss << "Tipo de Material: " << tipo << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "Formato: " << formato << std::endl;
	oss << "Duracion: " << duracion << std::endl;
	oss << "Resolucion: " << resolucion << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}

std::string VideoFisico::toStringCSV() const
{
	std::ostringstream oss;

	oss << "1" << ",";//fisico
	oss << "3" << ","; //Video Fisico
	oss << identificador << ",";
	oss << titulo << ",";
	oss << autores.getLength() << ",";
	for (int i = 0; i < autores.getLength(); i++) {
		oss << *autores.get(i);
		if (i != autores.getLength() - 1) {
			oss << ",";
		}
	}
	oss << "," << palabrasClave.getLength() << ",";
	for (int i = 0; i < palabrasClave.getLength(); i++) {
		oss << *palabrasClave.get(i);
		if (i != palabrasClave.getLength() - 1) {
			oss << ",";
		}
	}
	oss << "," << tipo << ",";
	oss << estado << ",";
	oss << formato << ",";
	oss << duracion << ",";
	oss << resolucion << ",";
	oss << disponibilidad << ",";
	return oss.str();
}

