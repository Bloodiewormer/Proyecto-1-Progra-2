#include "Utility.h"

void Utilidades::limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H"; // ANSI escape codes para limpiar pantalla
#endif
}

void Utilidades::msj(const std::string& mensaje) {
    limpiarPantalla();
    size_t mensajeSize = mensaje.size();
    size_t lineWidth = 50;

    std::cout << "+----------------------------------------------------+" << std::endl;
    for (size_t i = 0; i < mensajeSize; i += lineWidth) {
        std::cout << "| ";
        std::cout << mensaje.substr(i, lineWidth);
        size_t remaining = lineWidth - mensaje.substr(i, lineWidth).size();
        for (size_t j = 0; j < remaining; j++) {
            std::cout << " ";
        }
        std::cout << " |" << std::endl;
    }
    std::cout << "+----------------------------------------------------+" << std::endl;
    std::cout << "|          Presione ENTER para continuar            |" << std::endl;
    std::cout << "+----------------------------------------------------+" << std::endl;
    system("pause");
}

int Utilidades::inputInt() {
    int input;
    std::cin >> input;

    if (std::cin.fail()) {
        std::cin.clear(); // Limpia el flag de error
        while (std::cin.get() != '\n'); // Limpia el buffer de entrada
        throw InvalidInputException("Error: Entrada invalida. Por favor, ingrese un numero entero.");
    }

    return input;
}

std::string Utilidades::inputString() {
    std::string dato;
    while (std::cin.peek() == '\n' || std::cin.peek() == '\r') {
        std::cin.get();
    }
    std::getline(std::cin, dato);
    return dato;
}

Lista<std::string> Utilidades::collectInputList(const std::string& prompt) 
{
    Lista<std::string> list;
    std::string input;
    

    std::cout << prompt << " (escriba 'fin' para terminar):" << std::endl;
    while (true) {
        std::cout << "- ";
        input = inputString();

        if (input == "fin") {
            break; // Salir del bucle si el usuario escribe "fin"
        }
        list.addBegin(new std::string(input)); // Agregar la entrada a la lista
    }
	return list; // Retornar la lista de entradas
}

bool Utilidades::inputBool()
{
	std::string input;
	std::cin >> input;
	if (input == "true" || input == "1"|| input == "True"||"TRUE") {
		return true;
	}
	else if (input == "false" || input == "0" || input == "False" || "FALSE") {
		return false;
	}
	else {
		throw InvalidInputException("Error: Entrada invalida. Se asume 'false'.");
	}
}
