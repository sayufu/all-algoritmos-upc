#include <iostream>
#include <conio.h>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int _data) {
        data = _data;
        left = right = nullptr;
    }
};


//Espacio O(n) insertion y eliminacion O(logn) Peor caso en todo O(n)
class BST {
private:
    Node* root;
    void _insertFromArray(int* array, int size);
    int _height(Node* node);
    void _preorder(Node* node);
    void _inorder(Node* node);
    void _postorder(Node* node);
    int _countNodes(Node* node);
    int _sumOfValues(Node* node);
    void destroyBST(Node* node);
    bool _search(Node* node, int key);
    Node* _insert(Node* node, int data);

public:
    BST() {
        root = nullptr;
    }
    ~BST() {
        destroyBST(root);
    }
    void createBSTTest() {
        root = new Node(2);
        root->left = new Node(12);
        root->right = new Node(16);
        root->left->left = new Node(-123);
        root->left->right = new Node(65);
    }
    void insertFromArray(int* array, int size) {
        _insertFromArray(array, size);
    }

    int height(){ return _height(root); }
    void inorder(){ 
        _inorder(root); 
        cout << "\n";
    }
    void preorder(){ 
        _preorder(root); 
        cout << "\n";
    }
    void postorder(){ 
        _postorder(root); cout << "\n";
    }
    int countNodes(){ 
        return _countNodes(root); 
    }
    int sumOfValues(){
        return _sumOfValues(root); 
    }

    bool search(int key) { 
        return _search(root, key);
    }
    void insert(int key) { 
        this->root = _insert(root, key); 
    }

    Node* getRoot() { 
        return root; 
    }
};

void BST::destroyBST(Node* root) {
    if (root == nullptr) return;
    destroyBST(root->left);
    destroyBST(root->right);
    delete root;
    root = nullptr;
}

int BST::_height(Node* node) {
    if (node == nullptr)
        return 0;
    int height_left = _height(node->left);
    int height_right = _height(node->right);

    return max(height_left, height_right) + 1;
    //return 1 + max(_height(node ->left), _height(node->right));
}

void BST::_inorder(Node* node) {
    if (node == nullptr) {
        return;
    }

    _inorder(node->left);
    cout << node->data << " ";
    _inorder(node->right);
}

void BST::_preorder(Node* node) {
    if (node == nullptr) {
        return;
    }

    cout << node->data << " ";
    _preorder(node->left);
    _preorder(node->right);
}

void BST::_postorder(Node* node) {
    if (node == nullptr) {
        return;
    }

    _postorder(node->left);
    _postorder(node->right);
    cout << node->data << " ";
}

int BST::_countNodes(Node* root) {
    if (root == nullptr)
        return 0;
    int nodes_left = _countNodes(root->left);
    int nodes_right = _countNodes(root->right);
    return nodes_left + nodes_right + 1;
}

int BST::_sumOfValues(Node* root) {
    if (root == nullptr)
        return 0;

    int sum = root->data + _sumOfValues(root->left) + _sumOfValues(root->right);
    
    return sum;
}

void BST:: _insertFromArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        _insert(root, array[i]);
    }
}

bool BST::_search(Node*node, int key) {
    if (node == nullptr) {
        return false;
    }
    else if (node->data == key) {
        return true;
    }
    else if (node->data > key) {
        return _search(node->left, key);
    }

    return _search(node->right, key);
}

Node* BST::_insert(Node* node, int data) {
    if (node == nullptr) {
        return new Node(data);
    }

    if (data < node->data) {
        node->left = _insert(node->left, data);
    }
    else {
        node->right = _insert(node->right, data);
    }

    return node;
}

int main() {
    srand(time(NULL));
    BST* root = new BST();

    root->insert(10);
    root->insert(20);
    root->insert(30);
    root->insert(40);
    root->insert(50);
    root->insert(60);
    root->insert(70);
    root->insert(80);

    int n = 10;
    int* array = new int[n];

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100 + 10;
        //root->insert(array[i]);
    }

    root->inorder();
    root->preorder();
    root->postorder();

    cout << "Root: " << root->getRoot()->data << "\n";

    int query = 29;
    if (root->search(query)) {
        cout << "Found " << query << "\n";
    }
    else {
        cout << query << " was not found\n";
    }

    int suma = root->sumOfValues();
    cout << suma;

    cout << "\n" << root->countNodes();
    cout << "\n"<< root->height();


    _getch();
    return 0;
}