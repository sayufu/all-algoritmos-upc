#pragma once
#include "Figura.h"
#include <vector>

class Controlador {
private:
	vector<Figura*> impostores;
	int size;
	int init;

	int contCyan; //idx = 0;
	int contRojo;
	int contMagenta;
	int contBrown;
	int contBlack;
	int contPink; // idx = 5
public:
	Controlador() {
		init = 0;
		size = rand() % 7 + 6;

		contCyan = 0;
		contRojo = 0;
		contMagenta = 0;
		contBrown = 0;
		contBlack = 0;
		contPink = 0;
	}

	~Controlador() {

	}
	void agregar() {
		if (init != size) {
			impostores.push_back(new Figura());
			init++;
		}
	}
	void jugar(BufferedGraphics^ buffer, Bitmap^ bmp, int S, int anchoF, int altoF) {
		for (int i = 0; i < impostores.size(); i++) {
			impostores.at(i)->mover(buffer, bmp, anchoF, altoF);
		}
		colision();
	}
	void colision() {
		int aux;
		for (int i = 0; i < impostores.size(); i++) {
			for (int j = 0; j < impostores.size(); j++) {
				if (impostores.at(i)->getRectangle().IntersectsWith(impostores.at(j)->getRectangle())) {
					aux = rand() % 2;
					if (aux == 1 && (impostores.at(i)->getIndiceX() != impostores.at(j)->getIndiceX())
						&& impostores.at(i)->getCapturado() != true) {
						//i
						impostores.at(i)->setIndiceX(impostores.at(j)->getIndiceX());
						impostores.at(j)->setZoom(impostores.at(j)->getZoom() + 0.5);
						impostores.at(i)->setCapturado(true);
						impostores.at(j)->setRanking(impostores.at(j)->getRanking() + 1);

						switch (impostores.at(j)->getIndiceX()) {
						case 0: contCyan++; break;
						case 1: contRojo++; break;
						case 2: contMagenta++; break;
						case 3: contBrown++; break;
						case 4: contBlack++; break;
						case 5: contPink++; break;
						}
					}
					else {
						//j
						if ((impostores.at(j)->getIndiceX() != impostores.at(i)->getIndiceX())
							&& impostores.at(j)->getCapturado() != true) {
							impostores.at(j)->setIndiceX(impostores.at(i)->getIndiceX());
							impostores.at(i)->setZoom(impostores.at(i)->getZoom() + 0.5);
							impostores.at(j)->setCapturado(true);
							impostores.at(i)->setRanking(impostores.at(i)->getRanking() + 1);
							switch (impostores.at(i)->getIndiceX()) {
							case 0: contCyan++; break;
							case 1: contRojo++; break;
							case 2: contMagenta++; break;
							case 3: contBrown++; break;
							case 4: contBlack++; break;
							case 5: contPink++; break;
							}
						}
					}
				}
			}
		}
	}
	vector<Figura*> getVector() { return this->impostores; }

	int getCyan() { return this->contCyan; }
	int getRojo() { return this->contRojo; }
	int getMagenta() { return this->contMagenta; }
	int getBrown() { return this->contBrown; }
	int getBlack() { return this->contBlack; }
	int getPink() { return this->contPink; }
};
