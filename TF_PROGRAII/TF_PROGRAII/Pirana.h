#include"Objeto.h"

class Pirana :public Objeto {
private:
public:
	Pirana(int nivel) :Objeto() {
		x = 1280;
		width = height = 53;
		switch (nivel) {
		case 1: dx = 12; break;
		case 2: dx = 20; break;
		}
		Random r;
		y = r.Next(120, 670 - height);
		imagen = "Resources//Enemigos//Pirana.png";
	}
	~Pirana() {}

	void Mover(Graphics^ g) {
		if (indiceW > 1) indiceW = 0;
		x -= dx;
		indiceW++;
		Mostrar(g);
	}
};