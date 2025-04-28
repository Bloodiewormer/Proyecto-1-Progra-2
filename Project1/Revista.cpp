#include "Revista.h"

Revista::Revista(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoMaterial, const std::string& est, const std::string& vol, const std::string& num)
	: MaterialFisico(id, tit, palabras, auts, tipoMaterial, est),
	volumen(vol), numero(num) {
	diasPrestamo = DIAS_PRESTAMO_REVISTA;
}

Revista::~Revista(){
	// Destructor
}

std::string Revista::getVolumen()
{
	return volumen;
}

std::string Revista::getNumero()
{
	return numero;
}

std::string Revista::toString() const{
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Revista: " << std::endl;
	oss << "Identificador: " << identificador << std::endl;
	oss << "Titulo: " << titulo << std::endl;
	oss << "Autores: " << std::endl;
	oss << autores.toString();
	oss << "Palabras Clave: " << std::endl;
	oss << palabrasClave.toString();
	oss << "Tipo de Material: " << tipo << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "Volumen: " << volumen << std::endl;
	oss << "Numero: " << numero << std::endl;
	oss << "====================" << std::endl;
	return oss.str();
}

std::string Revista::toStringCSV() const
{
	std::ostringstream oss;
	oss << "1" << ","; // Indica que es material físico
	oss << "2" << ","; // Tipo de material
	oss << identificador << ","; // Identificador
	oss << titulo << ","; // Título
	oss << autores.getLength() << ","; // Número de autores
	for (int i = 0; i < autores.getLength(); i++) {
		oss << *autores.get(i);
		if (i != autores.getLength() - 1) {
			oss << ",";
		}
	}
	oss << "," << palabrasClave.getLength() << ","; // Número de palabras clave
	for (int i = 0; i < palabrasClave.getLength(); i++) {
		oss << *palabrasClave.get(i);
		if (i != palabrasClave.getLength() - 1) {
			oss << ",";
		}
	}
	oss << "," << tipo << ","; // Tipo de material
	oss << estado << ","; // Estado
	oss << volumen << ","; // Volumen
	oss << numero << ","; // Número
	oss << disponibilidad; // Disponibilidad
	return oss.str();
}


