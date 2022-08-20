#include<functional>
#include<iostream>
#include<conio.h>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;


/*T type of elements, k what you want to hash*/
template<class T, class k>
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

        void push_front(T key) {
            Node* newNode = new Node(key);

            if (head == nullptr) {
                head = newNode;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        void push_back(T key) {

            if (head == nullptr) {
                push_front(key);
                return;
            }

            Node* newLast = new Node(key);
            Node* current = head;

            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newLast;
            size++;
        }

        void push_mid(T key) {
            if (head == nullptr) {
                push_front(key);
                return;
            }
            else {
                Node* newNode = new Node(key);

                Node* current = head;
                int count = ((size % 2) == 0) ? (size / 2) : (size + 1) / 2;

                while (count > 1) {
                    current = current->next;
                    count--;
                }

                newNode->next = current->next;
                current->next = newNode;
                size++;
            }
        }


        void push(T key) {
            if (head == nullptr) {
                push_front(key);
                return;
            }
            /*Collision*/
            push_mid(key);
        }

        void print(function<void(T)> show) {
            Node* current = head;
            while (current != nullptr) {
                show(current->key);
                current = current->next;
            }
        }

        bool search(T key) {
            Node* current = head;

            while (current != nullptr) {
                if (current->key == key) {
                    return true;
                }
                current = current->next;
            }

            return false;
        }

    };

    /*Hash*/
    int n;
    int ncol;
    List* table;
    function<int(k)> hash_function;
    function<void(T)> show;

public:
    /*number of buckets, show function*/
    Hash(int _n, function<void(T)> _show, function<int(k)> _hash_function) {
        this->n = _n;
        this->table = new List[n];
        this->hash_function = _hash_function;
        this->show = _show;
        this->ncol = 0;
    }
    ~Hash() {}

    int gethash(k hashkey) {
        int hashCode = hash_function(hashkey);
        return hashCode;
    }

    void insert(T key, k hashkey) {
        int hashCode = gethash(hashkey);
        if (!table[hashCode].isNull()) {
            ncol++;
        }
        table[hashCode].push(key);
    }

    void search(T key, k hashkey, function<void(k)> hash_function) {
        int pos = gethash(hashkey);
        if (table[pos].search(key)) {
            hash_function(key);
        }
        else {
            cout << "Not found\n";
        }
    }
    void print() {
        for (int i = 0; i < n; i++) {
            table[i].print(this->show);
        }
        cout << "\n";
    }
    int getN() { return n; }
    int getnCollisions() { return ncol; }
};

int main() {
    Hash<int, int>* table = new Hash<int, int>(
        11,
        [](int a) -> void {
            cout << a << " ";
        },
        [&table](int a) -> int {
            /*Simple hash functions*/
            int hashCode = a % table->getN();
            return hashCode;


            ///*hash for strings*/
            //string b = "asjda";
            //int preHash = 0;
            //int hashCode;
            //for (int i = 0; i < b.length(); ++i) {
            //    preHash += int(b[i])* (i + 1);
            //}
            //hashCode = preHash % table->getN();
            //return hashCode;


            /*polynomial for strings*/
            /*A collision occurs when we get the same index for two nodes.
            We use techniques such as separate chaining and open addressing
            for collision handling. The implementation
            in this tutorial does not handle collisions.*/
            //string b = "abc";
            //int hashCode = 0;
            //for (int i = 0; i < b.length(); i++) {
            //    hashCode += b[i] * pow(31, i);
            //}
            //return hashCode % table->getN();
        }
        );

    table->insert(6, 6);
    table->insert(6, 6);
    table->insert(2, 2);
    table->insert(3, 3);
    table->insert(1, 7);
    table->print();

    cout << "\n" << table->getnCollisions() << "\n";

    table->search(6, 6,
        [&table](int a) -> void {
            cout << "Found " << a;
            /*still need delete function*/
        }
    );

	_getch();
	return 0;
}