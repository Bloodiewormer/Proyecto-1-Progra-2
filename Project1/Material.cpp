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

int Material::getDiasPrestamo()
{
	return diasPrestamo;
}

void Material::agregarHistorial(const std::string& linea)
{
	historial.addBegin(new std::string(linea));
}

void Material::mostrarHistorial()
{
	for (int i = 0; i < historial.getLength(); i++) {
		std::cout << *historial.get(i) << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Material& Material)
{
	os << Material.toString();
	return os;
}
