#include "Utility.h"

void imprimeCadena(string cadena) {
	cout << cadena;
}

void imprimeEntero(int n) {
	cout << n;
}

void imprimeFloat(float n) {
	cout << n;
}

string leerCadena() {
	string x;

	getline(cin, x);
	return x;
}

int leerEntero() {
	int n;
	bool continuar = true;
	while (true) {
		if (cin >> n) {
			cin.clear(); // Limpia el estado del flujo..
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "Valor incorrecto.. digita UN NUMERO" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

double leerDouble() {
	double n;
	bool continuar = true;
	while (true) {
		if (cin >> n) {
			cin.clear(); // Limpia el estado del flujo..
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "Valor incorrecto.. digita UN NUMERO" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

void limpiaPantalla() {
	system("cls");
}

void esperandoEnter() {
	system("pause");
}

bool respuestaValida(int res) {
	bool resValida = false;
	if (res == 1 || res == 2) {
		resValida = true;
	}
	else {
		imprimeCadena("\nOpcion no valida. Intente nuevamente.");
	}
	return resValida;
}
int convertirInt(string s) {
	stringstream r(s);
	int v;
	r >> v;
	return v;
}

double convertirDouble(string s) {
	stringstream r(s);
	double v;
	r >> v;
	return v;
}

float convertirFloat(string s) {
	stringstream r(s);
	float v;
	r >> v;
	return v;
}
