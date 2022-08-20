#include<iostream>
#include<conio.h>
#include<vector>

using namespace std;
using namespace System;

struct Node {
	float data1;
	char data2;
	Node* next;

	Node(float data1, char data2) {
		this->data1 = data1;
		this->data2 = data2;
		this->next = nullptr;
	}
};

class SingleCircular {
private:
	Node* head;
	int size;
public:
	SingleCircular() {
		this->head = nullptr;
		this->size = 0;
	}

	/*O(n)*/
	void push_front(float data1, char data2) {
		size++;

		Node* newFront = new Node(data1,data2);

		if (head == nullptr) {
			newFront->next = newFront;
			head = newFront;
			return;
		}

		Node* aux = head;

		while (aux->next != head) {
			aux = aux->next;
		}

		aux->next = newFront;
		newFront->next = head;
		head = newFront;
	}

	/*O(n)*/
	void push_back(float data1, char data2) {
		size++;

		if (head == nullptr) {
			push_front(data1,data2);
			return;
		}

		Node* newLast = new Node(data1, data2);
		Node* aux = head;

		while (aux->next != head) {
			aux = aux->next;
		}

		aux->next = newLast;
		newLast->next = head;
	}

	void printThis() {
		Node* aux = head;

		do {
			cout << "[" << aux->data1 << " , " << aux->data2 << "]\n";
			aux = aux->next;
		} while (aux != head);
	}

	auto getHead() { return head; }
};




void ModifyFloats(SingleCircular* array, int range, int toRange, float modFloat) {
	cout << "Floats originales\n";
	array->printThis();

	Node* current = array->getHead();
	int cont = 0;

	/*O(n)*/
	do {
		if (cont >= range) {
			/*Lambda suma*/

			if (cont <= toRange) {
				current->data1 = [](Node* aux, const float sumData) { return aux->data1 + sumData; }(current, modFloat);
			}

		}

		cont++;
		current = current->next;
	} while (cont <= toRange);

	cout << "\n\nFloats modificados con la suma de " << modFloat << " de rangos ["<<range<<" - " << toRange << "]\n";
	array->printThis();
}




void ModifyChars(SingleCircular* array, int range, int toRange, char modChar) {
	cout << "Chars originales\n";
	array->printThis();

	Node* current = array->getHead();
	int cont = 0;

	/*O(n)*/
	do {
		if (cont >= range) {

			if (cont <= toRange) {
				/*Lambda*/
				current->data2 = [](Node* aux, const float data1) { return aux->data1 = data1; }(current, modChar);
			}

		}
		/*Lambda*/
		current = current->next;
		cont++;
	} while (cont <= toRange);

	cout << "\n\nChars modificados con " << modChar << " de rangos [" << range << " - " << toRange << "]\n";
	array->printThis();
}


//int main() {
//	SingleCircular* array = new SingleCircular();
//	
//	/*Insertar elementos random en el array*/
//	/*O(n)*/
//	for (int i = 0; i < 20; i++) {
//		array->push_back(rand() % 100, char(rand() % 26 + 97));
//	}
//
//	int option;
//	do {
//		system("CLS");
//		cout << "Menu - Fu Liliana\n";
//		cout << "Lista enlazada circular\n";
//		cout << "1. Mostrar lista\n";
//		cout << "2. Modificar floats\n";
//		cout << "3. Modificar chars\n";
//		cout << "4. Salir\n";
//		cout << "Tu opcion: "; cin >> option;
//		system("CLS");
//		
//		int range;
//		int toRange;
//		float a;
//		char b;
//
//		switch (option)
//		{
//		case 1:
//			array->printThis();
//			break;
//		case 2:
//			int range;
//			float a;
//			cout << "Inserte el rango de modificacion inicial (2 por ejemplo): "; cin >> range;
//			cout << "Hasta el rango (5 por ejemplo, tiene que ser mayor al rango de modificacion inicial): "; cin >> toRange;
//			cout << "Inserte la cantidad que desea sumar (20 por ejemplo): "; cin >> a;
//			ModifyFloats(array, range, toRange, a);
//			break;
//		case 3:
//			cout << "Inserte el rango de modificacion inicial (1 por ejemplo): "; cin >> range;
//			cout << "Hasta el rango (5 por ejemplo, tiene que ser mayor al rango de modificacion inicial): "; cin >> toRange;
//			cout << "Inserte el nuevo char ('Z' por ejemplo): "; cin >> b;
//			ModifyChars(array, range, toRange, b);
//			break;
//		case 4:
//			exit(0);
//			break;
//		}
//		system("PAUSE");
//	} while (option < 5);
//
//
//	_getch();
//}