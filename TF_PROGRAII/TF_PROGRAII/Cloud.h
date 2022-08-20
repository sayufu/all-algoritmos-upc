#pragma once
#include "Objeto.h"

class Cloud :public Objeto {
private:
	int tipo;
public:
	Cloud() :Objeto() {
		x = 1280;
		y = 30;
		dx = 10;
		Random r;
		tipo = r.Next(1, 4);
		switch (tipo)
		{
		case 1:
			imagen = "Resources//Objetos//Cloud_1.png";
			width=140; height = 49;
			break;
		case 2:
			imagen = "Resources//Objetos//Cloud_2.png";
			width = 74; height = 24;
			break;
		case 3:
			imagen = "Resources//Objetos//Cloud_3.png";
			width = 133; height = 25;
			break;
		default:
			break;
		}
	}
	~Cloud() {}

	void Mover(Graphics^ g) {
		x -= dx;
		Mostrar(g);
	}
};