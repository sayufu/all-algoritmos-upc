#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

//declarar
void insertarCola(Nodo*&, Nodo*&, int);
bool cola_vacia(Nodo*);
void eliminarCola(Nodo*&, Nodo*&, int&);

//int main() {
//    Nodo* frente = NULL;
//    Nodo* fin = NULL;
//
//    int dato;
//
//    cout << "Digite un numero: ";
//    cin >> dato;
//    insertarCola(frente, fin, dato);
//
//    cout << "Digite un numero: ";
//    cin >> dato;
//    insertarCola(frente, fin, dato);
//
//    cout << "Digite un numero: ";
//    cin >> dato;
//    insertarCola(frente, fin, dato);
//
//    //eliminando elementos de la cola
//    cout << "\tEliminando elementos de la cola" << endl;
//    while (frente != NULL) {
//        eliminarCola(frente, fin, dato);
//
//        if (frente != NULL) {
//            cout << dato << ",";
//        }
//        else {
//            cout << dato << ".";
//        }
//
//    }
//
//    return 0;
//}

//Función para insertar elementos en una cola
void insertarCola(Nodo*& frente, Nodo*& fin, int n) {
    Nodo* nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if (cola_vacia(frente)) {
        frente = nuevo_nodo;

    }

    // 1 2 3                       n=3
    else {
        fin->siguiente = nuevo_nodo;
        //fin = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "\tElemento " << n << " insertado correctamente." << endl;
};

bool cola_vacia(Nodo* frente) {
    return (frente == NULL) ? true : false;
};

void eliminarCola(Nodo*& frente, Nodo*& fin, int& n) {
    n = frente->dato;
    Nodo* aux = frente;
    //evaluar 2 casos
    if (frente == fin) {
        //solo hay un elemento en la cola
        frente = NULL;
        fin = NULL;

    }
    else {
        frente = frente->siguiente;
    }

    delete aux;

}