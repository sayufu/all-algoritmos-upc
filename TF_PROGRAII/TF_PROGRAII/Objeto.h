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

class Objeto {
protected:
	int x, y, dx, dy;
	char* imagen;
	int width, height;
	int indiceH;
	int indiceW;
	bool visible;
public:
	//inicializar x y dx dy width height imagen
	Objeto() {
		indiceH = indiceW = 0;
		imagen = new char[20];
		visible = true;
	}
	~Objeto() {}

	//Setters
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setVisible(bool v) { visible = v; }
	void setindiceH(int indiceH) { this->indiceH = indiceH; }
	void setindiceW(int indiceW) { this->indiceW = indiceW; }
	//Getters
	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	int getH() { return height; }
	int getW() { return width; }
	bool getVisible() { return visible; }
	int getindiceH() { return indiceH; }
	int getindiceW() { return indiceW;}

	void Mostrar(Graphics^ g) {
		Bitmap^ bmp = gcnew Bitmap(gcnew String(imagen));
		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW * width, indiceH * height, width, height);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, width, height);
		g->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
		delete bmp;
	}

	virtual void Mover(){}

	System::Drawing::Rectangle getRectangle() {return System::Drawing::Rectangle(x, y, width, height);}

	bool Colision(System::Drawing::Rectangle r2) {
		return this->getRectangle().IntersectsWith(r2);
	}
};