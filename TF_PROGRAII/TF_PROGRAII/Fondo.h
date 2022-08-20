#pragma once

#include "Objeto.h"

class Fondo :public Objeto {
private:
	bool limite;
public:
	Fondo(int nivel) {
		x=y = 0;
		width = 7680;
		height = 720;
		dx = 8;
		//Escoge mapa de nivel
		switch (nivel) {
		case 1: imagen = "Resources//Fondos//Map_2.png"; break;
		case 2: imagen = "Resources//Fondos//Map.png"; break;
		}
	}
	~Fondo(){}
	void Mover(Graphics^g) {
		x -= dx;
	}
};