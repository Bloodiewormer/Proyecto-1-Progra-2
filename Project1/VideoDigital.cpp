#include "VideoDigital.h"



VideoDigital::VideoDigital(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoArchivo, double sizeMB, const std::string& dur, const std::string& res)
: MaterialDigital(id, tit, palabras, auts, tipoArchivo, sizeMB),duracion(dur), resolucion(res){

diasPrestamo = DIAS_PRESTAMO_VIDEO;
}

VideoDigital::~VideoDigital()
{
	// Destructor
}

std::string VideoDigital::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Video Digital: " << std::endl;
	oss << "Identificador: " << identificador << std::endl;
	oss << "Titulo: " << titulo << std::endl;
	oss << "Autores: " << std::endl;
	oss << autores.toString();
	oss << "Palabras Clave: " << std::endl;
	oss << palabrasClave.toString();
	oss << "Tipo de Archivo: " << tipo << std::endl;
	oss << "Tamano: " << tamano << std::endl;
	oss << "Duracion: " << duracion << std::endl;
	oss << "Resolucion: " << resolucion << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}


