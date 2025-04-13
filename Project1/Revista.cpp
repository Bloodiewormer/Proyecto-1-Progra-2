#include "Revista.h"

Revista::Revista(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoMaterial, const std::string& est, const std::string& vol, const std::string& num)
	: MaterialFisico(id, tit, palabras, auts, tipoMaterial, est),
	volumen(vol), numero(num) {
	diasPrestamo = DIAS_PRESTAMO_REVISTA;
}

Revista::~Revista(){
	// Destructor
}

std::string Revista::toString() const{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Revista: " << std::endl;
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
	oss << "Volumen: " << volumen << std::endl;
	oss << "Numero: " << numero << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}