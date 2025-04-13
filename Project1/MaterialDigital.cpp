#include "MaterialDigital.h"




MaterialDigital::MaterialDigital(const std::string& id, const std::string& tit, const Lista<std::string>& palabras, const Lista<std::string>& auts, const std::string& tipoArchivo, double sizeMB)
	: Material(id, tit, palabras, auts, tipoArchivo), tamano(sizeMB) {}

MaterialDigital::~MaterialDigital()
{
	// Destructor
}
