#include<iostream>
#include<conio.h>

using namespace std;
using namespace System;

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
class Cola {
private:
    Node<T>* top;
    Node<T>* end;
public:
    Cola() {
        top = nullptr;
        end = nullptr;
    }
    ~Cola(){}

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);

        if (top == nullptr) {
            top = newNode;
        }
        else {
            end->next = newNode;
        }
        end = newNode;
    }

    bool isEmpty() {
        return (top == nullptr) ? true : false;
    }

    void pop() {
        Node<T>* aux = top;

        if (top == end) {
            top = end = nullptr;
        }
        else {
            top = top->next;
        }

        delete aux;
    }

    auto getTop() { return top; }
    auto getEnd() { return end; }
};

template<class T>
void printCola(Cola<T>* cola) {

    while (!cola->isEmpty()) {
        cout << cola->getTop()->data << "\n";
        cola->pop();
    }
}

int main() {
    Cola<string>* cola = new Cola<string>();
    cola->push("Objecto");
    cola->push("Objecto2");
    cola->push("Objecto3");

    printCola(cola);

    _getch();
    return 0;
}