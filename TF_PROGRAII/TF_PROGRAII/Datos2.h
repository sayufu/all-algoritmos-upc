#pragma once
#include "Objeto.h"
class Datos2 {
private:
	string Nombre;
	int Puntos;
public:
	Datos2(string Nombre, int Puntos) {
		this->Nombre = Nombre;
		this->Puntos = Puntos;
	}
	~Datos2() {}
	void setNombre(string Nombre) { this->Nombre = Nombre; }
	void setPuntos(int Puntos) { this->Puntos = Puntos; }
	string getNombre() { return Nombre; }
	int getPuntos() { return Puntos; }
};