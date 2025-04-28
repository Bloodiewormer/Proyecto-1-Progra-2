#include "MaterialFisico.h"

MaterialFisico::MaterialFisico(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoMaterial, const std::string& est)
	: Material(id, tit, palabras, auts, tipoMaterial), estado(est) {
}
MaterialFisico::~MaterialFisico()
{
	// Destructor
}

std::string MaterialFisico::getEstado()
{
	return estado;
}
