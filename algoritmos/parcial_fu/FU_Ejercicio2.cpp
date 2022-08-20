#include<iostream>
#include<conio.h>
#include <string> 

using namespace std;
using namespace System;

struct Ahorrista {
	string nombre, direccion;
	int aporte;
	Ahorrista* next;

	Ahorrista(string nombre, string direccion, int aporte) {
		this->nombre = nombre;
		this->direccion = direccion;
		this->aporte = aporte;
		this->next = nullptr;
	}
};


class Cola {
private:
	Ahorrista* top;
	Ahorrista* end;
	int recolectado;
public:
	Cola() {
		top = nullptr;
		end = nullptr;
		recolectado = 0;
	}

	auto getTop() { return top; }

	void push(string nombre, string direccion, int aporte) {
		Ahorrista* newAhorrista = new Ahorrista(nombre, direccion, aporte);

		if (top == nullptr) {
			top = newAhorrista;
		}
		else {
			end->next = newAhorrista;
		}
		end = newAhorrista;

		recolectado += aporte;
	}

	void addNew() {
		string nombre, direccion;
		int aporte;
		cout << "Ingrese nombre: "; cin >> nombre;
		cout << "Ingrese dirrecion: "; cin >> direccion;
		do {
			cout << "Ingrese aporte inicial mayor a 10: "; cin >> aporte;
		} while (aporte <= 10);

		push(nombre, direccion, aporte);
	}

	void popAt(int pos) {
		/*Si la cola es vacio*/
		if (top == nullptr) {
			return;
		}

		/*Si la posicion es 1*/
		if (pos == 1) {
			Ahorrista* aux = top;

			while (aux->next != top) {
				aux = aux->next;
			}

			Ahorrista* toDelete = top;
			aux->next = top->next;
			this->top = top->next;

			delete toDelete;

			return;
		}

		/*En otro caso*/
		Ahorrista* aux = top;
		int cont = 0;

		while (cont != pos - 1) {
			aux = aux->next;
			cont++;
		}

		Ahorrista* toDelete = aux->next;
		aux->next = aux->next->next;

		/*Si el objeto no existe*/
		if (!toDelete) {
			cout << "No se encontro";
			return;
		}

		cout << toDelete->nombre << " borrado y cantidad recolectada disminuida ("<< toDelete->aporte<<")\n";
		recolectado -= toDelete->aporte;
		delete toDelete;
	}


	void printInfo() {
		cout << "TOTAL RECOLECTADO ===== " << recolectado << "\n\n";

		Ahorrista* current = top;
		/*O(n)*/
		while (current != nullptr) {
			cout << "[" << current->nombre << " , " << current->direccion << " , " << current->aporte << "]\n";
			current = current->next;
		}
	}

	void getBeneficiario() {
		int random = rand() % 1001 + 1000;
		cout << "TOTAL RECOLECTADO ===== " << recolectado << "\n";
		cout<<"Numero random generado (entre 1000 y 2000) ===== " << random << "\n";

		Ahorrista* current = top;
		while (random != 0) {
			current = current->next;
			if (current == end) {
				current = top;
			}
			random--;
		}


		/*MOSTRAR TODOS CON EL BENEFICIADO*/
		Ahorrista* aux = top;
		/*O(n)*/
		while (aux != nullptr) {
			cout << "[" << aux->nombre << " , " << aux->direccion << " , " << aux->aporte << "]";
			
			if (aux == current) {
				cout << "    <<------ BENEFICIADO!!!";
			}
			cout << "\n";
			aux = aux->next;
		}
		
		cout<<"\n\nBENEFICIADO: "<< "[" << current->nombre << " , " << current->direccion << " , " << current->aporte << "]";
	}
};


int main() {
	srand(time(NULL));

	Cola* cola = new Cola();

	int nelementos = rand() % 1000 + 100;

	for (int i = 0; i < nelementos; i++) {
		cola->push("Ahorrista "+ to_string(i), "Direccion "+ to_string(i), rand() % 1000 + 10);
	}

	int option;
	do {
		system("CLS");
		cout << "Menu - Fu Liliana\n";
		cout << "Problema de ahorristas\n";
		cout << "1. Mostrar informacion de ahorristas y total recolectado\n";
		cout << "2. Agregar un nuevo ahorrista\n";
		cout << "3. Borrar un beneficiado en x posicion\n";
		cout << "4. Generar numero y determinar beneficiado\n";
		cout << "5. Salir\n";
		cout << "Tu opcion: "; cin >> option;
		system("CLS");

		int pos;

		switch (option)
		{
		case 1:
			cola->printInfo();
			break;
		case 2:
			int pos;
			cola->addNew();
			break;
		case 3:
			cout << "Ingrese la posicion del ahorrista a borrar: "; cin >> pos;
			cola->popAt(pos);
			break;
		case 4:
			cola->getBeneficiario();
			break;
		case 5:
			exit(0);
			break;
		}
		cout << "\n";
		system("PAUSE");
	} while (option < 5);


	_getch();
}