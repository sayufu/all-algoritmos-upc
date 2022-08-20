#include<iostream>
#include<conio.h>

using namespace std;
using namespace System;

template<class T>
struct Node {
	T data;
	Node<T>* next;

	Node(T data) {
		this->data = data;
		this->next = nullptr;
	}
};

template<class T>
class CircularLinkedList {
private:
	Node<T>* head;
	int size;
public:
	CircularLinkedList() {
		head = nullptr;
		size = 0;
	}
	~CircularLinkedList(){}

	void push_front(T data) {
		size++;

		Node<T>* newFront = new Node<T>(data);

		if (head == nullptr) {
			newFront->next = newFront;
			head = newFront;
			return;
		}

		Node<T>* aux = head;

		while (aux->next != head) {
			aux = aux->next;
		}

		aux->next = newFront;
		newFront->next = head;
		head = newFront;
	}

	void push_back(T data) {
		size++;

		if (head == nullptr) {
			push_front(data);
			return;
		}

		Node<T>* newLast = new Node<T>(data);
		Node<T>* aux = head;

		while (aux->next != head) {
			aux = aux->next;
		}

		aux->next = newLast;
		newLast->next = head;
	}


	void popTop(){
		Node<T>* aux = head;

		while (aux->next != head) {
			aux = aux->next;
		}

		Node<T>* toDelete = head;
		aux->next = head->next;
		this->head = head->next;

		delete toDelete;
	}


	void popAt(int pos) {

		/*if theres only 1 node*/
		if (pos == 1) {
			popTop();
			return;
		}

		Node<T>* aux = head;
		int cont = 0;

		/*find the aux in the position*/
		while (cont != pos - 1) {
			aux = aux->next;
			cont++;
		}

		Node<T>* toDelete = aux->next;
		aux->next = aux->next->next;
		
		/*if object doesnt exist*/
		if (!toDelete) {
			cout<< "No found";
			return;
		}

		delete toDelete;
	}


	T getdataAt(int pos) {
		if (pos == 0) {
			return head->data;
		}

		Node<T>* aux = head;
		int cont = 0;

		/*find the aux in the position*/
		while (cont != pos - 1) {
			aux = aux->next;
			cont++;
		}

		Node<T>* toSend = aux->next;

		return toSend->data;
	}

	void findData(T data) {
		Node<T>* aux = head;

		for (int i = 0; i < size; i++) {
			if (aux->data == data) {
				cout << "Found " << data << " in position array[" << i << "]\n";
			}
			aux = aux->next;
		}
		
	}

	auto getHead() { return head; }
	int getSize() { return size; }
};


template<class T>
void printCircular(CircularLinkedList<T>* array) {

	Node<T>* aux = array->getHead();

	do {
		cout << aux->data << " ";
		aux = aux->next;
	} while (aux != array->getHead());
}


int main() {
	CircularLinkedList<string>*array = new CircularLinkedList<string>();
	array->push_back("1");
	array->push_back("2");
	array->push_back("3");
	array->push_back("2");

	array->push_front("4");
	array->push_front("5");

	cout << "\n";
	printCircular(array);

	/*deletion: arrays begins with pos[0] IMPORTANT*/
	cout << "\n";
	array->popAt(2);
	printCircular(array);


	/*queries*/
	cout << "\n";
	cout << array->getdataAt(7);
	cout << "\n";
	array->findData("2");
	cout << "\n";


	/*lambda*/
	//string findThis = "2";

	//auto search = [&](string findThis) {
	//	static Node<string>* aux;

	//	for (int i = 0; i < array->getSize(); i++) {
	//		if (aux->data == findThis) {
	//			cout << "Found " << findThis << " in position array[" << i << "]\n";
	//		}
	//		// aux = aux->next;
	//	}
	//};

	//search(findThis);



	_getch();
	return 0;
}