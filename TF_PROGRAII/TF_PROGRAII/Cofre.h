#pragma once

#include"Objeto.h"

class Cofre :public Objeto {
private:
	bool cofreEliminar;
public:
	Cofre() :Objeto() {
		x = 1280;
		y = 610;
		width = 86;
		height = 65;
		dx = dy = 8;
		imagen = "Resources//Objetos//Cofre.png";
	}
	~Cofre() {}

	void Mover(Graphics^ g) {
		x -= dx;
		Mostrar(g);
	}

};