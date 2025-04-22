#pragma once
#include <iostream>
#include <sstream>
#include "Lista.h"
#define DIAS_PRESTAMO_LIBRO 7
#define DIAS_PRESTAMO_ARTICULO 3
#define DIAS_PRESTAMO_VIDEO 5
#define DIAS_PRESTAMO_REVISTA 3
class Material{
protected:
	std::string identificador; //Este es el identificador unico de la biblioteca, todos los demas datos se pueden repetir
	std::string titulo;
	Lista<std::string> palabrasClave; //Lista de palabras clave
	Lista<std::string> autores; //Lista de autores 
	int diasPrestamo; //Dias de prestamo
	std::string tipo; // en Fisico se refiere en tipo de material (Cuero, plastico, etc), en digital se refiere a tipo de archivo (pdf, mp3, mp4, etc)
	Lista<std::string> historial; //Lista de historial de prestamos
public:
	Material(const std::string& id,
		const std::string& tit, 
		const Lista<std::string>& palabras, 
		const Lista<std::string>& auts, 
		const std::string tip);
	~Material();
	std::string getIdentificador() const;
	int getDiasPrestamo();
	
	void agregarHistorial(const std::string&);
	void mostrarHistorial();

	virtual std::string toString() const = 0;


	friend std::ostream& operator<<(std::ostream& os, const Material& Material);
};
	

