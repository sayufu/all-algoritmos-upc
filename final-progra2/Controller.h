#pragma once
#include"Circulo.h"
#include"Color.h"
#include"Agujero.h"
#include<fstream>
#include<iostream>

class Controller {
private:
	vector<Agujero*>* agujeros;
	vector<deColor*>* colores;
public:
	Controller() {
		agujeros = new vector<Agujero*>();
		colores = new vector<deColor*>();
		leerTxT();
		//Arriba
		agujeros->push_back(new Agujero(0,0));
		agujeros->push_back(new Agujero(850, 0));
		//Centro
		agujeros->push_back(new Agujero(0, 400));
		agujeros->push_back(new Agujero(850, 400));
		//Abajo
		agujeros->push_back(new Agujero(0, 825));
		agujeros->push_back(new Agujero(850, 825));
	}
	~Controller() {}

	void agregarColor() {
		deColor* nuevoCirculo = new deColor();
		colores->push_back(nuevoCirculo);
	}

	void leerTxT() {
		int n = 0;
		string line = "";
		ifstream file;

		file.open("datos.txt", ios::in);
		if (file.is_open()) {
			getline(file, line);
		}
		file.close();
		n = stoi(line);
		for (int i = 0; i < n; i++) {
			agregarColor();
		}
	}

	void dibujarTodo(Graphics^ g) {
		for (int i = 0; i < agujeros->size(); i++) {
			agujeros->at(i)->Mostrar(g);
		}
		for (int i = 0; i < colores->size(); i++) {
			colores->at(i)->Mover(g);
			if (colores->at(i)->getY() + colores->at(i)->getH() > 850 || colores->at(i)->getY() + colores->at(i)->getH() < 1) {
				colores->erase(colores->begin() + i);
			}
		}
	}

	void Colisiones() {
		//Rebote
		for (int i = 0; i < colores->size(); i++) {
			for (int j = 0; j < i; j++) {
				if (colores->at(i)->Colision(colores->at(j)->getRectangle()) == true) {
					colores->at(i)->setDx(colores->at(i)->getDx() * -1);
					colores->at(j)->setDx(colores->at(j)->getDx() * -1);
				}
			}
		}

		//Colision con agujeros
		for (int i = 0; i < agujeros->size(); i++) {
			for (int j = 0; j < colores->size(); j++) {
				if (agujeros->at(i)->Colision(colores->at(j)->getRectangle()) == true) {
					colores->erase(colores->begin() + j);
				}
			}
		}
	}
};
