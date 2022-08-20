#pragma once
#include"Objeto.h"

class Tiburon :public Objeto {
private:
public:
	Tiburon() :Objeto() {
		x = 1280;
		width = 215; // arreglar tama�o
		height = 79;
		dx = 17;
		Random r;
		y = r.Next(120, 670 - height);
		imagen = "Resources//Enemigos//Shark.png"; //cambiar
	}
	~Tiburon() {}

	void Mover(Graphics^ g) {
		if (indiceW > 1) indiceW = 0;
		x -= dx;
		indiceW++;
		Mostrar(g);
	}
};