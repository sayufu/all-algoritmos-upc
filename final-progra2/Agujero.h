#pragma once
#include"Circulo.h"

class Agujero : public Circulo {
public:
	Agujero(int _x, int _y) :Circulo() {
		this->colorx = 0;
		this->colory = 0;
		this->colorz = 0;
		this->x = _x;
		this->y = _y;
	}
};
