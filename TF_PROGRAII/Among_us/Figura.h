#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class Figura {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX; // color a cambiar o tipo o equipo
	int indiceY;
	float zoom;
	bool capturado;

	int ranking;
	float anchoWZoom;
	float altoWZoom;
public:
	Figura() {
		x = rand() % 501;
		y = rand() % 201;
		dx = dy = rand() % 21 + 10;
		indiceX = rand() % 6;
		indiceY = 0;
		ancho = 64;
		alto = 65;
		zoom = 1;
		capturado = false;
		ranking = 0;
	}
	~Figura() {

	}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		anchoWZoom = ancho * zoom;
		altoWZoom = alto * zoom;
		Rectangle porcion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, anchoWZoom, altoWZoom);
		buffer->Graphics->DrawImage(bmp, aumento, porcion, GraphicsUnit::Pixel);
		if (capturado) {
			buffer->Graphics->DrawRectangle(Pens::Red, x, y, int(anchoWZoom), int(altoWZoom));
		}
		x += dx;
		y += dy;
	}
	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoF, int altoF) {
		if (indiceY >= 0 && indiceY <= 3)
			indiceY++;
		else
			indiceY = 0;
		if (x + dx < 0 || x + dx + anchoWZoom > anchoF)
			dx *= -1;
		if (y + dy < 0 || y + dy + altoWZoom > altoF)
			dy *= -1;
		dibujar(buffer, bmp);
	}
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getDx() { return this->dx; }
	int getDy() { return this->dy; }
	int getAncho() { return this->ancho; }
	int getAlto() { return this->alto; }
	int getIndiceX() { return this->indiceX; }
	int getIndiceY() { return this->indiceY; }
	float getZoom() { return this->zoom; }
	int getCapturado() { return this->capturado; }
	int getRanking() { return this->ranking; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int dx) { this->dx = dx; }
	void setAncho(int ancho) { this->ancho = ancho; }
	void setAlto(int alto) { this->alto = alto; }
	void setIndiceX(int indiceX) { this->indiceX = indiceX; }
	void setIndiceY(int indiceY) { this->indiceY = indiceY; }
	void setZoom(float zoom) { this->zoom = zoom; }
	void setCapturado(bool capturado) { this->capturado = capturado; }
	void setRanking(int ranking) { this->ranking = ranking; }

	Rectangle getRectangle() { return Rectangle(x, y, anchoWZoom, altoWZoom); }
};
