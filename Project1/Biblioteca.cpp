#include "Biblioteca.h"

Biblioteca::Biblioteca(){
	listaMateriales = Lista<Material>();
	listaUsuarios = Lista<Usuario>();
	gestorPrestamos = GestorPrestamo();
	currentTime = 0; //= 1/1 ; 1 enero
}

Biblioteca::~Biblioteca() {

}

bool Biblioteca::comprobarExistenciaMaterial(std::string ID){
	if (ID.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	for (int i = 0; i < listaMateriales.getLength(); i++) {
		if (listaMateriales.get(i)->getIdentificador() == ID) {
			return true;
		}
	}
	return false;
}

void Biblioteca::agregarMaterial(Material* material)
{
	if (material == nullptr) {
		throw ObjectCreationException("Material cannot be null");
	}
	if (comprobarExistenciaMaterial(material->getIdentificador())) {
		throw ObjectCreationException("Material already exists in the list");
	}
	listaMateriales.addBegin(material); 
}

void Biblioteca::mostrarMateriales()
{
	system("cls");
	if (listaMateriales.isEmpty()) {
		std::cout << "No hay materiales registrados." << std::endl;
	}
	else {
		std::cout << "Lista de Materiales:" << std::endl;
		/*for (int i = 0; i < listaMateriales.getLength(); i++) {
			Material* material = listaMateriales.get(i);
			std::cout << material->toString() << std::endl;
		}*/
		std::cout << listaMateriales.toString();
	}
}

Lista<Material> Biblioteca::mostrarMaterialesClase(std::string tipo)
{
	//tipo can be libro, revista, articulo fisico, articulo digital, video fisico, video digital
	if (tipo.empty()) {
		throw ObjectCreationException("Tipo cannot be empty");
	}
	Lista<Material> materialesTipo;

	//dynamic_cast

	for (int i = 0; i < listaMateriales.getLength(); i++) {
		Material* material = listaMateriales.get(i);
		if (tipo == "libro" && dynamic_cast<Libro*>(material)) {
			materialesTipo.addBegin(material);
		}
		else if (tipo == "revista" && dynamic_cast<Revista*>(material)) {
			materialesTipo.addBegin(material);
		}
		else if (tipo == "articulo fisico" && dynamic_cast<ArticuloFisico*>(material)) {
			materialesTipo.addBegin(material);
		}
		else if (tipo == "articulo digital" && dynamic_cast<ArticuloDigital*>(material)) {
			materialesTipo.addBegin(material);
		}
		else if (tipo == "video fisico" && dynamic_cast<VideoFisico*>(material)) {
			materialesTipo.addBegin(material);
		}
		else if (tipo == "video digital" && dynamic_cast<VideoDigital*>(material)) {
			materialesTipo.addBegin(material);
		}
	}
	system("cls");
	return materialesTipo;
}

void Biblioteca::eliminarMaterial(std::string ID)
{
	if (ID.empty()) {
		throw ObjectCreationException("ID cannot be empty");
	}

	for (int i = 0; i < listaMateriales.getLength(); i++) {
		if (listaMateriales.get(i)->getIdentificador() == ID) {
			listaMateriales.remove(i);
			std::cout << "Material eliminado correctamente." << std::endl;
			return;
		}
	}
	std::cout << "Material no encontrado." << std::endl;
}

Material* Biblioteca::buscarMaterial(std::string ID)
{
	if (ID.empty()) {
		throw InvalidInputException("ID cannot be empty");
	}
	for (int i = 0; i < listaMateriales.getLength(); i++) {
		if (listaMateriales.get(i)->getIdentificador() == ID) {
			return listaMateriales.get(i);
		}
	}
	throw InvalidInputException("Material no encontrado");
}

void Biblioteca::agregarCopiaMaterial(std::string ID, std::string newID)
{
	if (ID.empty()) {
		throw ObjectCreationException("ID cannot be empty");
	}
	if (newID.empty()) {
		throw ObjectCreationException("New ID cannot be empty");
	}
	if (comprobarExistenciaMaterial(newID)) {
		throw ObjectCreationException("New ID already exists in the list");
	}

	Material* existingMaterial = buscarMaterial(ID);
	if (!existingMaterial) {
		throw ObjectCreationException("Material not found");
	}

	Material* copia = nullptr;

	// Determine the type of the existing material and create a copy
	if (auto* libro = dynamic_cast<Libro*>(existingMaterial)) {
		copia = new Libro(newID, libro->getTitulo(), libro->getPalabrasClave(), libro->getAutores(),
			libro->getTipo(), libro->getEstado(), libro->getISBN(), libro->getEditorial());
	}
	else if (auto* revista = dynamic_cast<Revista*>(existingMaterial)) {
		copia = new Revista(newID, revista->getTitulo(), revista->getPalabrasClave(), revista->getAutores(),
			revista->getTipo(), revista->getEstado(), revista->getVolumen(), revista->getNumero());
	}
	else if (auto* articuloFisico = dynamic_cast<ArticuloFisico*>(existingMaterial)) {
		copia = new ArticuloFisico(newID, articuloFisico->getTitulo(), articuloFisico->getPalabrasClave(),
			articuloFisico->getAutores(), articuloFisico->getTipo(), articuloFisico->getEstado(),
			articuloFisico->getTipoArticulo());
	}
	else if (auto* articuloDigital = dynamic_cast<ArticuloDigital*>(existingMaterial)) {
		copia = new ArticuloDigital(newID, articuloDigital->getTitulo(), articuloDigital->getPalabrasClave(),
			articuloDigital->getAutores(), articuloDigital->getTipo(),
			articuloDigital->getTamano(), articuloDigital->getTipoArticulo());
	}
	else if (auto* videoFisico = dynamic_cast<VideoFisico*>(existingMaterial)) {
		copia = new VideoFisico(newID, videoFisico->getTitulo(), videoFisico->getPalabrasClave(),
			videoFisico->getAutores(), videoFisico->getTipo(), videoFisico->getEstado(),
			videoFisico->getFormato(), videoFisico->getDuracion(), videoFisico->getResolucion());
	}
	else if (auto* videoDigital = dynamic_cast<VideoDigital*>(existingMaterial)) {
		copia = new VideoDigital(newID, videoDigital->getTitulo(), videoDigital->getPalabrasClave(),
			videoDigital->getAutores(), videoDigital->getTipo(), videoDigital->getTamano(),
			videoDigital->getDuracion(), videoDigital->getResolucion());
	}
	else {
		throw ObjectCreationException("Unsupported material type");
	}

	agregarMaterial(copia);
	std::cout << "Copia agregada correctamente." << std::endl;
}



bool Biblioteca::comprobarExistenciaUsuario(std::string ID) {
		if (ID.empty()) {
			throw ObjectCreationException("ID cannot be empty");
		}
		for (int i = 0; i < listaUsuarios.getLength(); i++) {
			if (listaUsuarios.get(i)->getCedula() == ID) {
				return true;
			}
		}
		return false;
}

void Biblioteca::agregarUsuario(Usuario* usuario)
{
		if (usuario == nullptr) {
			throw ObjectCreationException("Usuario cannot be null");
		}
		if (comprobarExistenciaUsuario(usuario->getCedula())) {
			throw ObjectCreationException("Usuario already exists in the list");
		}
		listaUsuarios.addBegin(usuario); // Pass the address of the usuario pointer
}

void Biblioteca::mostrarUsuarios()
{
	if (listaUsuarios.isEmpty()) {
		std::cout << "No hay usuarios registrados." << std::endl;
	}
	else {
		std::cout << "Lista de Usuarios:" << std::endl;
		std::cout<<listaUsuarios.toString();
	}
}

void Biblioteca::modificarUsuario(std::string ID, std::string change, int opcion)
{
	if (ID.empty()) {
		throw ObjectCreationException("ID cannot be empty");
	}
	Usuario* usuario = buscarUsuario(ID);
	if (usuario == nullptr) {
		throw ObjectCreationException("Usuario cannot be null");
	}
	if (comprobarExistenciaUsuario(usuario->getCedula())) {
		switch (opcion) {
		case 1: // Modificar nombre
			usuario->setNombre(change);
			break;
		case 2: // Modificar apellido
			usuario->setApellido(change);
			break;
		case 3: // Modificar estado
			if (change == "true") {
				usuario->setEstado(true);
			}
			else if (change == "false") {
				usuario->setEstado(false);
			}
			else {
				std::cout << "Estado invalido" << std::endl;
			}
			break;
		case 4: // Modificar cedula
			if (comprobarExistenciaUsuario(change)) {
				std::cout << "La cedula ya existe en la lista" << std::endl;
			}
			else {
				usuario->setCedula(change);
			}
			break;
			{
		default:
			break;

			}
		}

	}
	else {
		std::cout << "El usuario no existe en la lista" << std::endl;
	}
}


void Biblioteca::eliminarUsuario(std::string ID)
{
	if (ID.empty()) {
		throw ObjectCreationException("ID cannot be empty");
	}
	for (int i = 0; i < listaUsuarios.getLength(); i++) {
		if (listaUsuarios.get(i)->getCedula() == ID) {
			listaUsuarios.remove(i);
			std::cout << "Usuario eliminado correctamente." << std::endl;
			return;
		}
	}
	std::cout << "Usuario no encontrado." << std::endl;
}

Usuario* Biblioteca::buscarUsuario(std::string ID)
{
	if (ID.empty()) {
		throw ObjectCreationException("ID cannot be empty");
	}
	for (int i = 0; i < listaUsuarios.getLength(); i++) {
		if (listaUsuarios.get(i)->getCedula() == ID) {
			return listaUsuarios.get(i);
		}
	}
	throw ObjectCreationException("Usuario no encontrado");
}

void Biblioteca::registrarPrestamo(std::string idUsuario, std::string idMaterial)
{
	Usuario* u = buscarUsuario(idUsuario);
	Material* m = buscarMaterial(idMaterial);
	if (u != nullptr && m != nullptr) {

		if (u->getEstado() == false) {
			std::cout << "El usuario no esta activo." << std::endl;
			return;
		}
		if (m->getDiasPrestamo() == 0) {
			std::cout << "El material no tiene dias de prestamo." << std::endl;
			return;
		}
		gestorPrestamos.registrarPrestamo(currentTime, u, m);
		std::cout << "Prestamo registrado correctamente.\n";
	}
	else {
		std::cout << "Usuario o material no encontrado.\n";
	}
}

void Biblioteca::registrarPrestamoCreado(Prestamo* p){
	if (p != nullptr) {
		gestorPrestamos.registrarPrestamoCreado(p);
	}
	else {
		throw ObjectCreationException("Prestamo no creado");
	}
}

void Biblioteca::devolverMaterial(int idPrestamo,std::string idUsuario)
{

	gestorPrestamos.devolverMaterial(idPrestamo,currentTime,idUsuario);
}

void Biblioteca::mostrarPrestamos()
{
	gestorPrestamos.mostrarPrestamos();
}

void Biblioteca::mostrarPrestamosPorUsuario(std::string idUsuario)
{
	gestorPrestamos.mostrarPrestamosPorUsuario(idUsuario);
}

void Biblioteca::mostrarPrestamosPorMaterial(std::string idMaterial)
{
	gestorPrestamos.mostrarPrestamosPorMaterial(idMaterial);
}

Time Biblioteca::getCurrentTime()
{
	return currentTime;
}

void Biblioteca::pasarDias(int dias)
{
	if (dias < 0) {
		throw ObjectCreationException("Dias cannot be negative");
	}
	currentTime.pasarDia(dias);
}

void Biblioteca::volverDias(int dias)
{
	if (dias < 0) {
		throw InvalidDateException("Dias cannot be negative");
	}
	currentTime.regresarDia(dias);
}

void Biblioteca::resetTime()
{
	currentTime.irAlDia(0);
}

void Biblioteca::setTime(int dia, int mes)
{
	if (dia < 1 || dia > 31) {
		throw InvalidDateException("Dia no valido");
	}
	if (mes < 1 || mes > 12) {
		throw InvalidDateException("Mes no valido");
	}
	if (mes == 2 && dia > 28) {
		throw InvalidDateException("Febrero solo tiene 28 dias");
	}
	if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
		throw InvalidDateException("Este mes solo tiene 30 dias");
	}
	int diasTotales = 0;
	for (int i = 0; i < mes - 1; i++) {
		if (i == 1) {
			diasTotales += 28;
		}
		else if (i == 3 || i == 5 || i == 8 || i == 10) {
			diasTotales += 30;
		}
		else {
			diasTotales += 31;
		}
	}
	diasTotales += dia-1;
	currentTime.irAlDia(diasTotales);
}

Lista<Usuario> Biblioteca::getListaUsuarios()  
{  
   return listaUsuarios;  
}

Lista<Material> Biblioteca::getListaMateriales()
{
	return listaMateriales;
}

Lista<Prestamo> Biblioteca::getListaPrestamos()
{
	return gestorPrestamos.getListaPrestamos();
}
