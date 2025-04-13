#include "ArticuloFisico.h"

ArticuloFisico::ArticuloFisico(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoMaterial, const std::string& est, const std::string& tipoArt)
	: MaterialFisico(id, tit, palabras, auts, tipoMaterial, est),
	tipoArticulo(tipoArt) {
	diasPrestamo = DIAS_PRESTAMO_ARTICULO;
}

ArticuloFisico::~ArticuloFisico()
{
	// Destructor
}

std::string ArticuloFisico::toString() const
{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Articulo Fisico: " << std::endl;
	oss << "Tipo Articulo: " << tipoArticulo << std::endl;
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
	oss << "====================" << std::endl;
	return oss.str();
}
