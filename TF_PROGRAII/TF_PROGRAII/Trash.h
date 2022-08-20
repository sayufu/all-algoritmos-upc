#pragma once
#include "Objeto.h"

class Trash:public Objeto {
private:
	int tipo;
public:
	Trash(int nivel):Objeto() {
		x = 1280;
		width = height = 53;
		switch (nivel) {
		case 1: dx = 15; break;
		case 2: dx = 25; break;
		}
		Random r;
		y = r.Next(120, 670 - height);
		tipo = r.Next(1, 9);
		switch (tipo)
		{
		case 1:
			imagen = "Resources//Objetos//Trash//Bags.png";
			break;
		case 2:
			imagen = "Resources//Objetos//Trash//Bottles.png";
			break;
		case 3:
			imagen = "Resources//Objetos//Trash//Cups.png";
			break;
		case 4:
			imagen = "Resources//Objetos//Trash//Can.png";
			break;
		case 5:
			imagen = "Resources//Objetos//Trash//Cd.png";
			break;
		case 6:
			imagen = "Resources//Objetos//Trash//Glasses.png";
			break;
		case 7:
			imagen = "Resources//Objetos//Trash//News.png";
			break;
		case 8:
			imagen = "Resources//Objetos//Trash//Wood.png";
			break;
		default:
			break;
		}
	}
	~Trash() {}

	void Mover(Graphics^ g) {
		if (indiceW > 2) indiceW = 0;
		x -= dx;
		indiceW++;
		Mostrar(g);
	}
};