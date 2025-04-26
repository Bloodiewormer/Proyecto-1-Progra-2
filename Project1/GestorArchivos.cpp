#include "GestorArchivos.h"



void GestorArchivos::guardarUsuarios(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
	Lista<Usuario> listaUsuarios = biblioteca->getListaUsuarios();
	if (listaUsuarios.getLength() == 0) {
		throw new InvalidInputException("No hay usuarios para guardar.");
	}
	std::ofstream archivo(nombreArchivo, std::ios::out);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para guardar usuarios.");
	}
	archivo << "cedula , nombre , apellido , estado" << std::endl;	
	if (listaUsuarios.getLength() == 0) {
		throw  InvalidInputException("No hay usuarios para guardar.");
	}
	else {
		archivo << listaUsuarios.CSV();
		archivo.close();
	}
	archivo.close();
}

void GestorArchivos::guardarTiempo(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
	Time tiempo = biblioteca->getCurrentTime();
	std::ofstream archivo(nombreArchivo, std::ios::out);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para guardar tiempos.");
	}
	archivo << "dia" << std::endl; //0 to 365
	archivo << tiempo.getDia()<< std::endl;
	archivo.close();
}

void GestorArchivos::guardarMateriales(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
	Lista<Material> listaMateriales = biblioteca->getListaMateriales();
	if (listaMateriales.getLength() == 0) {
		throw new InvalidInputException("No hay materiales para guardar.");
	}
	std::ofstream archivo(nombreArchivo, std::ios::out);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para guardar materiales.");
	}
	for (int i = 0; i < listaMateriales.getLength(); i++) {
		Material* m = listaMateriales.get(i);
		archivo << m->toStringCSV() << std::endl;
	}
	archivo.close();
}

void GestorArchivos::guardarPrestamos(const Lista<Prestamo>& listaPrestamos, const std::string& nombreArchivo){
	if (listaPrestamos.getLength() == 0) {
		throw InvalidInputException("No hay prestamos para guardar.");
	}

	std::ofstream archivo(nombreArchivo, std::ios::out);
	if (!archivo.is_open()) {
		throw FileOperationException("Error al abrir el archivo para guardar prestamos.");
	}

	archivo << "cedula, idMaterial, fechaPrestamo, fechaDevolucion, estado" << std::endl;

	for (int i = 0; i < listaPrestamos.getLength(); i++) {
		Prestamo* p = listaPrestamos.get(i);
		archivo << p->toStringCSV() << std::endl;
	}

	archivo.close();
}

void GestorArchivos::cargarUsuarios(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
	std::ifstream archivo(nombreArchivo, std::ios::in);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para cargar usuarios.");
	}
	std::string linea;
	// Leer la primera línea (encabezados)
	std::getline(archivo, linea);
	// Leer el resto de las líneas
	while (std::getline(archivo, linea)) {
		std::istringstream iss(linea);
		std::string cedula, nombre, apellido, estado;
		if (std::getline(iss, cedula, ',') && std::getline(iss, nombre, ',') && std::getline(iss, apellido, ',') && std::getline(iss, estado)) {
			bool estadoBool = (estado == "Activo");
			Usuario* usuario = new Usuario(cedula, nombre, apellido, estadoBool);
			biblioteca->agregarUsuario(usuario);
		}
	}
	archivo.close();
}

void GestorArchivos::cargarTiempo(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
	std::ifstream archivo(nombreArchivo, std::ios::in);
	if (!archivo.is_open()) {
		throw new FileOperationException("Error al abrir el archivo para cargar tiempos.");
	}
	std::string linea;
	// Leer la primera línea (encabezados)
	std::getline(archivo, linea);
	// Leer el resto de las líneas
	while (std::getline(archivo, linea)) {
		std::istringstream iss(linea);
		int dia;
		if (iss >> dia) {
			biblioteca->setTime(dia+1, 1);
		}
	}
	archivo.close();
}

void GestorArchivos::cargarMateriales(Biblioteca* biblioteca, const std::string& nombreArchivo)
{
    std::ifstream archivo(nombreArchivo, std::ios::in);
    if (!archivo.is_open()) {
        throw FileOperationException("Error al abrir el archivo para cargar materiales.");
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);

        // Atributos comunes
        int tipoMaterial, tipoEspecifico, numAutores, numPalabrasClave;
        std::string id, titulo, disponibilidad;
        Lista<std::string> autores, palabrasClave;

        // Leer los datos comunes usando std::getline con delimitadores
        std::string temp;
        if (!std::getline(iss, temp, ',') || !(std::istringstream(temp) >> tipoMaterial) ||
            !std::getline(iss, temp, ',') || !(std::istringstream(temp) >> tipoEspecifico) ||
            !std::getline(iss, id, ',') ||
            !std::getline(iss, titulo, ',') ||
            !std::getline(iss, temp, ',') || !(std::istringstream(temp) >> numAutores)) {
            throw InvalidInputException("Error al leer los datos comunes del material. Verifique el formato del archivo CSV.");
        }

        // Leer autores
        for (int i = 0; i < numAutores; ++i) {
            std::string autor;
            if (!std::getline(iss, autor, ',')) {
                throw InvalidInputException("Error al leer autores.");
            }
            autores.addBegin(new std::string(autor));
        }

        // Leer número de palabras clave
        if (!std::getline(iss, temp, ',') || !(std::istringstream(temp) >> numPalabrasClave)) {
            throw InvalidInputException("Error al leer número de palabras clave.");
        }

        // Leer palabras clave
        for (int i = 0; i < numPalabrasClave; ++i) {
            std::string palabraClave;
            if (!std::getline(iss, palabraClave, ',')) {
                throw InvalidInputException("Error al leer palabras clave.");
            }
            palabrasClave.addBegin(new std::string(palabraClave));
        }

        // Leer atributos específicos según el tipo de material
        Material* material = nullptr;
        switch (tipoMaterial) {
        case 1: // Físico
            switch (tipoEspecifico) {
            case 1: { // Libro
                std::string tipo, estado, isbn, editorial;
                if (!std::getline(iss, tipo, ',') ||
                    !std::getline(iss, estado, ',') ||
                    !std::getline(iss, isbn, ',') ||
                    !std::getline(iss, editorial, ',')) {
                    throw InvalidInputException("Error al leer libro.");
                }
                material = new Libro(id, titulo, palabrasClave, autores, tipo, estado, isbn, editorial);
                break;
            }
            case 2: { // Revista
                std::string tipo, estado, volumen, numero;
                if (!std::getline(iss, tipo, ',') ||
                    !std::getline(iss, estado, ',') ||
                    !std::getline(iss, volumen, ',') ||
                    !std::getline(iss, numero, ',')) {
                    throw InvalidInputException("Error al leer revista.");
                }
                material = new Revista(id, titulo, palabrasClave, autores, tipo, estado, volumen, numero);
                break;
            }
            case 3: { // Video Físico
                std::string tipo, estado, formato, resolucion;
                int duracionFisica;
                if (!std::getline(iss, tipo, ',') ||
                    !std::getline(iss, estado, ',') ||
                    !std::getline(iss, formato, ',') ||
                    !(std::getline(iss, temp, ',') && std::istringstream(temp) >> duracionFisica) ||
                    !std::getline(iss, resolucion, ',')) {
                    throw InvalidInputException("Error al leer video físico.");
                }
                material = new VideoFisico(id, titulo, palabrasClave, autores, tipo, estado, formato, duracionFisica, resolucion);
                break;
            }
            case 4: { // Artículo Físico
                std::string tipo, estado, tipoArticulo;
                if (!std::getline(iss, tipo, ',') ||
                    !std::getline(iss, estado, ',') ||
                    !std::getline(iss, tipoArticulo, ',')) {
                    throw InvalidInputException("Error al leer artículo físico.");
                }
                material = new ArticuloFisico(id, titulo, palabrasClave, autores, tipo, estado, tipoArticulo);
                break;
            }
            }
            break;
        case 2: // Digital
            switch (tipoEspecifico) {
            case 1: { // Video Digital
                std::string tipoArchivo, duracion, resolucion;
                double tamano;
                if (!std::getline(iss, tipoArchivo, ',') ||
                    !(std::getline(iss, temp, ',') && std::istringstream(temp) >> tamano) ||
                    !std::getline(iss, duracion, ',') ||
                    !std::getline(iss, resolucion, ',')) {
                    throw InvalidInputException("Error al leer video digital.");
                }
                material = new VideoDigital(id, titulo, palabrasClave, autores, tipoArchivo, tamano, duracion, resolucion);
                break;
            }
            case 2: { // Artículo Digital
                std::string tipoArchivo, tipoArticulo;
                double tamano;
                if (!std::getline(iss, tipoArchivo, ',') ||
                    !(std::getline(iss, temp, ',') && std::istringstream(temp) >> tamano) ||
                    !std::getline(iss, tipoArticulo, ',')) {
                    throw InvalidInputException("Error al leer artículo digital.");
                }
                material = new ArticuloDigital(id, titulo, palabrasClave, autores, tipoArchivo, tamano, tipoArticulo);
                break;
            }
            }
            break;
        }

        // Leer disponibilidad
        if (!std::getline(iss, disponibilidad, ',')) {
            throw InvalidInputException("Error al leer disponibilidad.");
        }

        // Crear el material y agregarlo a la biblioteca
        if (material != nullptr) {
            material->setDisponibilidad(disponibilidad);
            biblioteca->agregarMaterial(material);
        }
        else {
            throw InvalidInputException("Error al crear el material.");
        }
    }

    archivo.close();
}

void GestorArchivos::cargarPrestamos(Biblioteca* biblioteca, const std::string& nombreArchivo){
    std::ifstream archivo(nombreArchivo, std::ios::in);
    if (!archivo.is_open()) {
        throw FileOperationException("Error al abrir el archivo para cargar prestamos.");
    }

    std::string linea;
    std::getline(archivo, linea); // Leer encabezado

    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string idStr, cedula, idMaterial;
        std::string diaPrestamoStr;
        std::string estado;
        std::string diaDevolucionStr, mesDevolucionStr, anioDevolucionStr;

        if (std::getline(iss, idStr, ',') &&
            std::getline(iss, cedula, ',') &&
            std::getline(iss, idMaterial, ',') &&
            std::getline(iss, diaPrestamoStr, ',') &&
 
            std::getline(iss, estado, ',') &&
            std::getline(iss, diaDevolucionStr, ',') &&
            std::getline(iss, mesDevolucionStr, ',') &&
            std::getline(iss, anioDevolucionStr)) {

            int id = std::stoi(idStr);
            int diaPrestamo = std::stoi(diaPrestamoStr);
           

            Time fechaPrestamo(diaPrestamo);

            // Buscar el usuario y material en la biblioteca
            Usuario* usuario = biblioteca->buscarUsuario(cedula);
            Material* material = biblioteca->buscarMaterial(idMaterial);

            if (usuario == nullptr || material == nullptr) {
                std::cout << "Advertencia: Usuario o Material no encontrado para prestamo ID " << id << std::endl;
                continue;
            }

            Prestamo* prestamo = new Prestamo(id, fechaPrestamo, usuario, material);

            if (estado == "devuelto") {
                int diaDev = std::stoi(diaDevolucionStr);
                int mesDev = std::stoi(mesDevolucionStr);
                int anioDev = std::stoi(anioDevolucionStr);
                Time fechaDevolucion(diaDev);
                prestamo->devolver(fechaDevolucion);
            }
            biblioteca->registrarPrestamoCreado(prestamo);
        }
    }

    archivo.close();
}




