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
	oss << "Autores: " << std::endl;
	oss << autores.toString();
	oss << "Palabras Clave: " << std::endl;
	oss << palabrasClave.toString();
	oss << "Tipo de Material: " << tipo << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}

std::string ArticuloFisico::toStringCSV() const
{
	std::ostringstream oss;
	oss << "1" << ",";//fisico
	oss << "4" << ","; //Articulo Fisico
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
	oss << tipoArticulo << ",";
	oss << disponibilidad << ",";
	return oss.str();

	
}


