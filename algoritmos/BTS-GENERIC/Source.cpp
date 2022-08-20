#include<iostream>
#include<conio.h>
#include<functional>
using namespace std;


//Espacio O(n) insertion y eliminacion O(logn) Peor caso en todo O(n)
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

    void destroyBST(Node* node) {
        if (node == nullptr) return;
        destroyBST(node->left);
        destroyBST(node->right);
        delete node;
        node = nullptr;
    }

    int _height(Node* node) {
        if (node == nullptr)
            return 0;
        int height_left = _height(node->left);
        int height_right = _height(node->right);

        return max(height_left, height_right) + 1;
    }

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

        if (compare(key,node->key)) {
            node->left = _insert(node->left, key);
        }
        else {
            node->right = _insert(node->right, key);
        }

        return node;
    }

    void _print(Node*node) {
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

    int height() { 
        return _height(root);
    }
    void search(T key, function<void(T)> doWhat) {
        _search(root, key, doWhat);
    }
    void insert(T key) {
        this->root = _insert(root, key);
    }
    void print() {
        _print(root);
    }
};



int main() {
    srand(time(NULL));

    BST<int>* root = new BST<int>(
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

    int n = 100;
    for (int i = 0; i < n; i++) {
        root->insert(rand() % 100 + 10);
    }

    root->insert(80);
    root->print();


    int query = 80;
    root->search(query,
        [&query](int query) -> void {
            cout << "Found " << query;
        }
    );

    _getch();
    return 0;
}