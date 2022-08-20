#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace System;

class Datos {
private:
	ofstream salida;
	ifstream entrada;
	string text;
	int S; // S => Tiempo para que aparezca un impostor
	int T; // T => Tiempo total en segundos del juego
public:
	Datos() {
		leer();
	}
	void leer() {
		entrada.open("configuracion.txt", ios::in);
		if (entrada.fail()) {
			entrada.close();
			salida.open("configuracion.txt", ios::out);
			salida << "2" << endl;
			salida << "100" << endl;
			salida.close();
			entrada.open("configuracion.txt", ios::in);
		}
		getline(entrada, text);
		S = stoi(text);
		getline(entrada, text);
		T = stoi(text);
		entrada.close();
	}

	int getS() { return this->S; }
	int getT() { return this->T; }

	void setS(int S) { this->S = S; }
	void setT(int T) { this->T = T; }
};
