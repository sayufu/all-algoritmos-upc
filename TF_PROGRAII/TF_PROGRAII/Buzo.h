#pragma once
#include "Objeto.h"

class Buzo: public Objeto{
private:
	int vidas, puntos;
	bool inmunidad;
public:
	//inicializar x y dx dy width height imagen
	Buzo(int nivel): Objeto() {
		x = 30;
		y = 120;
		width = 150;
		height = 52;
		dy = dx = 8;
		imagen = "Resources//Main.png";
		switch (nivel) {
		case 1: vidas = 5; break;
		case 2: vidas = 3; break;
		}
		puntos = 0;
		inmunidad = false;
	}
	~Buzo() {}

	//Vidas
	void setVidas(int vidas) { this->vidas = vidas; }
	int getVidas() { return vidas; }
	void restarVidas() { vidas--; }
	void sumarVidas() { vidas++; }
	//Puntos
	void setPuntos(int vidas) { this->puntos = puntos; }
	int getPuntos() { return puntos; }
	void sumarPuntos() { puntos+=100; }

	void Mover(Graphics^ g, char tecla) {
		switch (tecla)
		{
		case 'W':
			if (y > 100) {
				indiceH = getindiceH();
				y -= dy;
			}
			break;

		case 'S':
			if (y < g->VisibleClipBounds.Height-120) {
				y += dy;
				indiceH = getindiceH();
			}
			break;
		}
	}
	void Mover_Constante(Graphics^ g) {
		if (indiceW > 6)
			indiceW = 0;
		indiceW++;
		Mostrar(g);
	}
	void setinmunidad(bool inmunidad) { this->inmunidad = inmunidad; }
	bool getinmunidad() { return inmunidad; }
};