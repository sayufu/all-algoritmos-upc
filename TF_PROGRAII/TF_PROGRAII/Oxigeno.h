#pragma once

#include"Objeto.h"

class Oxigeno:public Objeto {
private:
public:
	Oxigeno() :Objeto() {
		x = 1280;
		width = height = 40;
		dx = dy = 9;
		Random r;
		y = r.Next(120, 670 - height);
		imagen = "Resources//Objetos//O2.png";
	}
	~Oxigeno() {}

	void Mover(Graphics^ g) {
		if (indiceW > 2) indiceW = 0;
		if (y < 120 || y + height > 665)dy *= -1;
		x -= dx;
		y += dy;
		indiceW++;
		Mostrar(g);
	}
};