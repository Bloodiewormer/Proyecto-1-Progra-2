#include "Libro.h"

Libro::Libro(const std::string& id, const std::string& tit, const  Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoMaterial, const std::string& est, const std::string& isbn_, const std::string& edit)
	: MaterialFisico(id, tit, palabras, auts, tipoMaterial, est),
	isbn(isbn_), editorial(edit){ 
	diasPrestamo = DIAS_PRESTAMO_LIBRO;
}

Libro::~Libro() {
	// Destructor
}

std::string Libro::getISBN()
{
	return isbn;
}

std::string Libro::getEditorial()
{
	return editorial;
}

std::string Libro::toString() const {
	std::ostringstream oss;
	oss << "====================" << std::endl;
	oss << "Libro: " << std::endl;
	oss << "Identificador: " << identificador << std::endl;
	oss << "Titulo: " << titulo << std::endl;
	oss << "Autores: " << std::endl;
	oss << autores.toString();
	oss << "Palabras Clave: " << std::endl;
	oss << palabrasClave.toString();
	oss << "Tipo de Material: " << tipo << std::endl;
	oss << "Estado: " << estado << std::endl;
	oss << "ISBN: " << isbn << std::endl;
	oss << "Editorial: " << editorial << std::endl;
	oss << "====================" << std::endl;
	return oss.str();

}

std::string Libro::toStringCSV() const
{
	std::ostringstream oss;
	oss << "1" << ",";//Fisico
	oss << "1 " << ",";
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
	oss << isbn << ",";
	oss << editorial << ",";
	oss << disponibilidad << ",";
	return oss.str();

	
}
