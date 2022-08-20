#include<iostream>
#include<functional>
#include<conio.h>
#include<fstream>
#include<sstream>
#include<algorithm>

using namespace std;



template<class T>
class BST {
private:
    class Node {
    public:
        T key;
        Node* left;
        Node* right;
        Node(T _key) {
            key = _key;
            left = right = nullptr;
        }
    };

    Node* root;

    function<void(T)> show;
    function<bool(T, T)> compare;
    function<bool(T, T)> equals;

    void _search(Node* node, T key, function<void(T)> doWhat) {
        if (node == nullptr) {
            return;
        }
        else if (equals(key, node->key)) {
            doWhat(node->key);
            return;
        }
        else if (compare(key, node->key)) {
            _search(node->left, key, doWhat);
        }

        _search(node->right, key, doWhat);
    }

    Node* _insert(Node* node, T key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (compare(key, node->key)) {
            node->left = _insert(node->left, key);
        }
        else {
            node->right = _insert(node->right, key);
        }

        return node;
    }

    void _print(Node* node) {
        if (node == nullptr) {
            return;
        }
        show(node->key);
        _print(node->left);
        _print(node->right);
    }

public:
    BST(function<void(T)> _show, function<bool(T, T)> _compare, function<bool(T, T)> _equals) {
        this->show = _show;
        this->compare = _compare;
        this->equals = _equals;
        this->root = nullptr;
    }
    ~BST() { destroyBST(root); }

    void search(T key, function<void(T)> doWhat) {
        _search(root, key, doWhat);
    }
    void insert(T key) {
        this->root = _insert(root, key);
    }
    void print() {
        _print(root);
    }

    /*SOLUCION*/
    double getAbsoluto(double a, double b) {
        a = a - b;
        if (a < 0) {
            a = -a;
        }
        return a;
    }

    void solucion(Node* node, double objetivo, int min_for_now, int &minimum_key) {
        if (node == nullptr) {
            return;
        }
        /*si son iguales*/
        if (equals(objetivo, node->key)) {
            minimum_key = node->key;
            return;
        }
        else {
            double absolut = getAbsoluto(node->key, objetivo);
            if (min_for_now < absolut) {
                min_for_now = node->key;
                minimum_key = node->key;
            }

            if (compare(objetivo, node->key)) {
                solucion(node->left, objetivo, min_for_now, minimum_key);
            }
            else {
                solucion(node->right, objetivo, min_for_now, minimum_key);
            }
        }
       
    }

    int encontrarValorMasCercano(double objetivo) {
        int minimum_key = 0;
        solucion(root, objetivo, 1, minimum_key);
        return minimum_key;
    }
};


int main() {
    BST<int>* arbol = new BST<int>(
        // show
        [](int a) -> void {
            cout << a << " ";
        },
        // compare
            [](int a, int b) -> bool {
            return a < b;
        },
        // equals
            [](int a, int b) -> bool {
            return a == b;
        }
        );


    /*TXT READ se lee lineal, cada numero va en una nueva linea*/
    ifstream file;
    string line = "";

    file.open("input.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            string data;
            stringstream inputString(line);
            getline(inputString, data, ',');
            arbol->insert(stoi(data));
        }
    }
    else {
        cout << "No se encontro input.txt";
    }
    file.close();
    /**/


    arbol->print();

    /*SOLUCION PEOR CASO SERIA O(n) al realizar todas las recursiones por el BST*/
    cout << "\nCASOS DE PRUEBA: \n";
    cout << arbol->encontrarValorMasCercano(6.124780) << "\n";
    cout << arbol->encontrarValorMasCercano(8.5) << "\n";
	_getch();
	return 0;
}