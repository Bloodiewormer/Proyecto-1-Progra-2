#include "Material.h"




Material::Material(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string tip)
	: identificador(id), titulo(tit), palabrasClave(palabras),
	autores(auts), tipo(tip), diasPrestamo(0) {
}

Material::~Material()
{
}

std::string Material::getIdentificador() const
{
	return identificador;
}

std::ostream& operator<<(std::ostream& os, const Material& Material)
{
	os << Material.toString();
	return os;
}
