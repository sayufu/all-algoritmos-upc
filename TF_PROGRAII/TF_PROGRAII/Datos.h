#pragma once
#include "Objeto.h"
class Datos{
private:
	string Nombre;
	int Puntos;
public:
	Datos(string Nombre, int Puntos) {
		this->Nombre = Nombre;
		this->Puntos = Puntos;
	}
	~Datos(){}
	void setNombre(string Nombre) { this->Nombre = Nombre; }
	void setPuntos(int Puntos) { this->Puntos = Puntos; }
	string getNombre() { return Nombre; }
	int getPuntos() { return Puntos; }
};