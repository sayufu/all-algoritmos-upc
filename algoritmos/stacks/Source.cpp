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
class Stack{
private:
    Node<T>* top;
    int size;
public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    ~Stack() {}

    void pushTop(T data) {
        size++;

        if (top == nullptr) {
            top = new Node<T>(data);
            return;
        }

        Node<T>* newTop = new Node<T>(data);
        newTop->next = top;
        top = newTop;
    }

    T getTop() {
        if (top == nullptr)
            return "No data";

        return top->data;
    }

    void popTop() {
        if (top == nullptr)
            return;

        size--;

        if (top->next == nullptr) {
            delete top;
            top = nullptr;
            return;
        }

        Node<T>* toDelete = top;
        top = top->next;

        delete toDelete;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

template<class T>
void printStack(Stack<T>* stack) {
    Stack<T>*temp = new Stack<T>();
    temp = stack;

    cout << "[";
    while (!temp->isEmpty()) {

        cout << temp->getTop();

        if (temp->getSize() != 1) {
            cout << " , ";
        }

        temp->popTop();
    }

    cout << "]";

    delete temp;
}


int main() {
    Stack<string>*stack = new Stack<string>();
    stack->pushTop("Object");
    stack->pushTop("Object2");
    stack->pushTop("Object3");

    printStack(stack);
     

    _getch();
    return 0;
}