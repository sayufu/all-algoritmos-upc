#pragma once
#include <stdio.h>
#include<vector>
#include<string>
#include<time.h>

using namespace std;
using namespace System;
using namespace System::Media;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Circulo {
protected:
	int x, y, dx, dy;
	int width, height;
	int colorx;
	int colory;
	int colorz;
public:
	Circulo() {
		this->dx = rand() %  3 + 10;
		this->dy = rand() % 3 + 10;
		this->width = 30;
		this->height = 30;
		this->x = rand() % (800 - width) + width;
		this->y = rand() % (800 - height) + height;
	}
	~Circulo() {}

	//Setters
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int _dx) { this->dx = _dx; }
	void setDy(int _dy) { this->dy = _dy; }
	//Getters
	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	int getH() { return height; }
	int getW() { return width; }

	void Mostrar(Graphics^ g) {
		SolidBrush^ lapiz = gcnew SolidBrush(Color::FromArgb(colorx, colory, colorz));
		g->FillEllipse(lapiz, x, y, width, height);
	}

	void Mover(Graphics^ g) {
		if (y < 1 || y + height > 850)dy *= -1;
		if (x < 1 || x > 850)dx *= -1;
		x -= dx;
		y += dy;
		Mostrar(g);
	}

	Rectangle getRectangle() { return Rectangle(x, y, width, height); }

	bool Colision(System::Drawing::Rectangle r2) {
		return this->getRectangle().IntersectsWith(r2);
	}
};