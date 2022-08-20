#include<conio.h>
#include<algorithm>
#include<iostream>
#include<functional>
#include <math.h>
#include<fstream>
#include<sstream>
using namespace std;


/*T type of elements, k what you want to hash*/
template<class T>
class Hash {
private:
    class Node {
    public:
        T key;
        Node* next;
        Node(T _key) {
            key = _key;
            next = nullptr;
        }
    };

    class List {
    public:
        Node* head;
        int size;

        List() {
            head = nullptr;
            size = 0;
        }

        bool isNull() {
            if (head == nullptr)
                return true;
            return false;
        }

        void push(T key) {
            if (head == nullptr) {
                head = new Node(key);
                return;
            }

            Node* newLast = new Node(key);
            Node* current = head;

            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newLast;
        }

        void print(function<void(T)> show) {
            Node* current = head;
            while (current != nullptr) {
                show(current->key);
                current = current->next;
            }
        }
    };

    /*Hash*/
    int n;
    int ncol;
    List* table;
    function<int(T)> hash_function;
    function<void(T)> show;

public:
    /*number of buckets, show function*/
    Hash(int _n, function<void(T)> _show, function<int(T)> _hash_function) {
        this->n = _n;
        this->table = new List[n];
        this->hash_function = _hash_function;
        this->show = _show;
        this->ncol = 0;
    }
    ~Hash() {}

    int gethash(T hashkey) {
        int hashCode = hash_function(hashkey);
        return hashCode;
    }

    void insert(T key) {
        int hashCode = gethash(key);
        if (!table[hashCode].isNull()) {
            ncol++;
        }
        table[hashCode].push(key);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            table[i].print(this->show);
            cout << "\n";
        }
        cout << "\n";
    }
    int getN() { return n; }
    int getnCollisions() { return ncol; }
};

int main() {
    Hash<int>* table = new Hash<int>(
        10,
        [](int a) -> void {
            cout << a << " -> ";
        },
        [&table](int a) -> int {
            return a % table->getN();
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
            table->insert(stoi(data)* stoi(data));
        }
    }
    else {
        cout << "No se encontro input.txt";
    }
    file.close();
    /**/

    table->print();

    cout << "Total de colisiones: " << table->getnCollisions() << "\n";

    /*El peor caso a momento de insertar en la tabla hash seria O(n)
    Cuando ocurren colisiones, la insercion siempre sera de O(1),
    pero para acceder a los datos, sera de O(n) en su peor caso
    ya que se trabajaron con listas enlazadas simpes
    */

    _getch();
    return 0;
}