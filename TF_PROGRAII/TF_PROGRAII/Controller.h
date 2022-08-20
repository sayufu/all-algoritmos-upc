#pragma once
#include<fstream>
#include<iostream>
#include"Fondo.h"
#include"Buzo.h"
#include"Oxigeno.h"
#include"Trash.h"
#include"Pirana.h"
#include"Tiburon.h"
#include"Cloud.h"
#include"Cofre.h"
#include"Datos.h"
#include"Datos2.h"

class Controller {
private:
	//Datos de partida
	int nivel;
	ofstream write_data;
	ifstream get_data;
	vector<Datos*>datos;
	vector<Datos2*>datos2;
	//Fondo
	Fondo* fondo;
	//Buzo
	Buzo* buzo;
	clock_t t_inmunidad;
	int aux, seg;
	//Nubes
	clock_t t_cloud;
	vector<Cloud*> clouds;
	//Cofres
	int tipo;
	int contCofres;
	vector<Cofre*> cofres;
	clock_t t_cofre;
	int size_cofre;
	//Basuritas
	clock_t t_basuritas;
	vector<Trash*> basuritas;
	//Oxigenos
	clock_t t_oxigenos;
	vector<Oxigeno*> oxigenos;
	//Enemigos piranas
	clock_t t_pirana;
	vector<Pirana*> piranas;
	//Enemigos tiburones
	clock_t t_tiburon;
	vector<Tiburon*>tiburones;
public:
	Controller() {
	}
 	~Controller() {}

	void Juego(Graphics^g) {
		Agregar_Objetos(g);
		Mover_Objetos(g);
		Colisiones(g);
		Borrar_Objetos(g);
		Estadisticas(g);
		if (++aux == 9) {
			--seg; aux = 0;
		}
	}

	//Empieza nueva partida, se crean los objetos nuevos
	void Nueva_Partida(int nivel) {
		t_cloud = t_oxigenos = t_basuritas = t_pirana = t_cofre =t_tiburon= clock();
		fondo = new Fondo(nivel);
		buzo = new Buzo(nivel);
		aux = 0;
		seg = 80;
		size_cofre = 1;
		contCofres = 0;
		this->nivel = nivel;
	}

	//Eliminar partida reciente
	void Salir_Partida(string nombre) {
		//Guardamos datos de partidas finalizadas
		if (getTiempo() == false || getVidas() == false) {

			//Nivel 1
			if (nivel == 1) {
				//push back datos al vector
				datos.push_back(new Datos(nombre, buzo->getPuntos()));
				//Ordenamos datos
				Datos* aux;
				if (datos.size() > 1) {
					for (int i = 0; i < datos.size(); i++) {
						for (int j = i+1; j < datos.size(); j++) {
							if (datos.at(i)->getPuntos() < datos.at(j)->getPuntos()) {
								aux = datos.at(i);
								datos.at(i) = datos.at(j);
								datos.at(j) = aux;
							}
						}
					}
				}
				//Limpiamos data antigua
				write_data.open("Datos_Nivel_1.txt", ios::out | ios::trunc);
				write_data.close();
				//Lo guardamos en el txt
				write_data.open("Datos_Nivel_1.txt", ios::out);
				string space = "  ";
				//Ofstream
				if (write_data.is_open()) {
					for (int i = 0; i < datos.size(); i++) {
						write_data << datos.at(i)->getNombre() << space << datos.at(i)->getPuntos() << "\n";
					}
					write_data.close();
				}
			}

			//Nivel 2
			if (nivel == 2) {
				//push back datos al vector
				datos2.push_back(new Datos2(nombre, buzo->getPuntos()));
				//Ordenamos datos
				Datos2* aux;
				if (datos2.size() > 1) {
					for (int i = 0; i < datos2.size(); i++) {
						for (int j = i+1; j < datos2.size(); j++) {
							if (datos.at(i)->getPuntos() < datos2.at(j)->getPuntos()) {
								aux = datos2.at(i);
								datos2.at(i) = datos2.at(j);
								datos2.at(j) = aux;
							}
						}
					}
				}
				//Limpiamos data antigua
				write_data.open("Datos_Nivel_2.txt", ios::out | ios::trunc);
				write_data.close();
				//Lo guardamos en el txt
				write_data.open("Datos_Nivel_2.txt", ios::out);
				string space = "  ";
				if (write_data.is_open()) {
					for (int i = 0; i < datos2.size(); i++) {
						write_data << datos2.at(i)->getNombre() << space << datos2.at(i)->getPuntos() << "\n";
					}
					write_data.close();
				}
			}

		}

		//Eliminamos todos los datos de la antigua partida
		clouds.clear();
		oxigenos.clear();
		basuritas.clear();
		piranas.clear();
		tiburones.clear();
		cofres.clear();
		delete fondo;
		delete buzo;
	}

	string getRanking(int rank) {
		string ranking = "\n";
		string line;
		if (rank == 1) {
			//Recogemos datos de txt
			get_data.open("Datos_Nivel_1.txt", ios::in);
			if (get_data.is_open()) {
				if (datos.size() > 0) {
					while (!get_data.eof()) {
						getline(get_data, line);
						ranking += line + "\n";
					}
				}
				else ranking += "No hay datos";
				get_data.close();
			}
		}
		if (rank == 2) {
			//Recogemos datos de txt
			get_data.open("Datos_Nivel_2.txt", ios::in);
			if (get_data.is_open()) {
				if (datos2.size() > 0) {
					while (!get_data.eof()) {
						getline(get_data, line);
						ranking += line + "\n";
					}
				}
				else ranking += "No hay datos";
				get_data.close();
			}
		}
		return ranking;
	}

	//Elemenos del juego
	void Agregar_Objetos(Graphics^ g) {
		//Cofres
		Random r;
		if (((clock() - t_cofre) / 1000) == r.Next(15,60) && cofres.size() < size_cofre) {
			cofres.push_back(new Cofre());
			//Cofres no aparecen mas
			this->size_cofre = 0;
		}
		//Clouds
		if (((clock() - t_cloud) / 1000) == 7) {
			clouds.push_back(new Cloud());
			t_cloud = clock();
		}
		//Basuritas
		if (((clock() - t_basuritas) / 1000) == 3) {
			basuritas.push_back(new Trash(nivel));
			t_basuritas = clock();
		}
		//Oxigenos
		if (((clock() - t_oxigenos) / 1000) == 20) {
			oxigenos.push_back(new Oxigeno());
			t_oxigenos = clock();
		}
		//Piranas
		int seg_piranas;
		if (nivel == 1) { seg_piranas = 6; }
		if (nivel == 2) { seg_piranas = 4; }
		if (((clock() - t_pirana) / 1000) == seg_piranas) {
			piranas.push_back(new Pirana(nivel));
			t_pirana = clock();
		}
		//Tiburones
		if (nivel == 2) {
			if (((clock() - t_tiburon) / 1000) == 10) {
				tiburones.push_back(new Tiburon());
				t_tiburon = clock();
			}
		}
	}
	void Mover_Objetos(Graphics^ g) {
		//Fondo
		fondo->Mover(g);
		//Buzo
		buzo->Mover_Constante(g);
		//Cofres
		for (int i = 0; i < cofres.size(); i++) {
			cofres.at(i)->Mover(g);
		}
		//Clouds
		for (int i = 0; i < clouds.size(); i++) {
			if (clouds.at(i)->getX() < 0 - clouds.at(i)->getW()) clouds.at(i)->setVisible(false);
			clouds.at(i)->Mover(g);
		}
		//Basuritas
		for (int i = 0; i < basuritas.size(); i++) {
			if (basuritas.at(i)->getX() < 0 - basuritas.at(i)->getW()) basuritas.at(i)->setVisible(false);
			basuritas.at(i)->Mover(g);
		}
		//Oxigenos
		for (int i = 0; i < oxigenos.size(); i++) {
			if (oxigenos.at(i)->getX() < 0-oxigenos.at(i)->getW()) oxigenos.at(i)->setVisible(false);
			oxigenos.at(i)->Mover(g);
		}
		//Piranas
		for (int i = 0; i < piranas.size(); i++) {
			if (piranas.at(i)->getX() < 0) piranas.at(i)->setVisible(false);
			piranas.at(i)->Mover(g);
		}
		//Tiburones
		for (int i = 0; i < tiburones.size(); i++) {
			if (tiburones.at(i)->getX() < 0) tiburones.at(i)->setVisible(false);
			tiburones.at(i)->Mover(g);
		}
	}
	void Colisiones(Graphics^ g) {
		//Basuritas
		for (int i = 0; i < basuritas.size(); i++) {
			if (basuritas.at(i)->Colision(buzo->getRectangle()) == true) {
				basuritas.at(i)->setVisible(false);
				buzo->sumarPuntos();
			}
		}
		//Oxigenos
		for (int i = 0; i < oxigenos.size(); i++) {
			if (oxigenos.at(i)->Colision(buzo->getRectangle()) == true) {
				oxigenos.at(i)->setVisible(false);
				buzo->sumarVidas();
			}
		}
		//Piranas
		for (int i = 0; i < piranas.size(); i++) {
			if (piranas.at(i)->Colision(buzo->getRectangle()) == true) {
				//Restar vidas, comprobamos inmunidad
				if (buzo->getinmunidad() == false) {
					buzo->restarVidas();
					buzo->setX(30);
					buzo->setY(120);
				}
				//Inmunidad
				t_inmunidad = clock();
				buzo->setinmunidad(true);
				if (buzo->getinmunidad() == true) {
					buzo->setindiceH(1);
				}
			}	
			if (((clock() - t_inmunidad) / CLOCKS_PER_SEC) == 2) {
				buzo->setinmunidad(false);
				buzo->setindiceH(0);
			}
		}
		//Tiburones
		for (int i = 0; i < tiburones.size(); i++) {
			if (tiburones.at(i)->Colision(buzo->getRectangle()) == true) {
				//Restar vidas, comprobamos inmunidad
				if (buzo->getinmunidad() == false) {
					buzo->restarVidas();
					buzo->setX(30);
					buzo->setY(120);
				}
				//Inmunidad
				t_inmunidad = clock();
				buzo->setinmunidad(true);
				if (buzo->getinmunidad() == true) {
					buzo->setindiceH(1);
				}
			}
			if (((clock() - t_inmunidad) / CLOCKS_PER_SEC) == 2) {
				buzo->setinmunidad(false);
				buzo->setindiceH(0);
			}
		}
		//Cofres
		for (int i = 0; i < cofres.size(); i++) {
			if (cofres.at(i)->Colision(buzo->getRectangle()) == true) {
				cofres.at(i)->setVisible(false);
				contCofres += 1;
			}
		}
	}
	void Borrar_Objetos(Graphics^ g) {
		//Nubes
		for (int i = 0; i < clouds.size(); i++) {
			if (!clouds.at(i)->getVisible())
				clouds.erase(clouds.begin() + i);
		}
		//Basuritas
		for (int i = 0; i < basuritas.size(); i++) {
			if (!basuritas.at(i)->getVisible())
				basuritas.erase(basuritas.begin() + i);
		}
		//Oxigenos
		for (int i = 0; i < oxigenos.size(); i++) {
			if (!oxigenos.at(i)->getVisible())
				oxigenos.erase(oxigenos.begin() + i);
		}
		//Piranas
		for (int i = 0; i < piranas.size(); i++) {
			if (!piranas.at(i)->getVisible())
				piranas.erase(piranas.begin() + i);
		}
		//Tiburones
		for (int i = 0; i < tiburones.size(); i++) {
			if (!tiburones.at(i)->getVisible())
				tiburones.erase(tiburones.begin() + i);
		}
		//Cofres
		for (int i = 0; i < cofres.size(); i++) {
			if (!cofres.at(i)->getVisible()) {
				cofres.erase(cofres.begin() + i);
			}
		}
	}
	void Estadisticas(Graphics^g){
		SolidBrush^ sb = gcnew SolidBrush(Color::Maroon);
		g->FillRectangle(sb, 140, 16, 600, 32);
		Drawing::Font^ miFuente = gcnew Drawing::Font("MV Boli", 12);
		g->DrawString("Vidas: "+buzo->getVidas().ToString()+ "       Puntos: "+buzo->getPuntos().ToString()+"       Tiempo restante: "+seg.ToString()+" segundos", miFuente, Brushes::Lime, 150, 20);
		delete sb, miFuente;
	}

	Buzo* getBuzo() { return buzo; }
	Fondo* getFondo() { return fondo; }
	bool getTiempo() { 
		if (seg < 0)
			return false;
		else return true;
	}
	bool getVidas(){
		if (buzo->getVidas() < 1)
			return false;
		else return true;
	}
	int getCofres() { return contCofres; }	
};