#include "ArticuloDigital.h"







ArticuloDigital::ArticuloDigital(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoArchivo, double sizeMB, const std::string& tipoArt)
	: MaterialDigital(id, tit, palabras, auts, tipoArchivo, sizeMB), TipoArticulo(tipoArt) {
	diasPrestamo = DIAS_PRESTAMO_ARTICULO;
}


ArticuloDigital::~ArticuloDigital()
{
	// Destructor
}

std::string ArticuloDigital::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Tipo Articulo: " << TipoArticulo << std::endl;
	oss << "Articulo Digital: " << std::endl;
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
	oss << "Tipo Archivo: " << tipo << std::endl;
	oss << "Tamano: " << tamano << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}