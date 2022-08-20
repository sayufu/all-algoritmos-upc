#pragma once
#include"Circulo.h"

class deColor : public Circulo {
public:
	deColor() :Circulo() {
		this->colorx = rand() % 255;
		this->colory = rand() % 255;
		this->colorz = rand() % 255;
	}
};