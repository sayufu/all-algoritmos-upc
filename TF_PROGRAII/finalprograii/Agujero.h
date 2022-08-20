#pragma once
#include"Circulo.h"

class Agujero : public Circulo {
public:
	Agujero() :Circulo() {
		this->colorx = 0;
		this->colory = 0;
		this->colorz = 0;
	}
};