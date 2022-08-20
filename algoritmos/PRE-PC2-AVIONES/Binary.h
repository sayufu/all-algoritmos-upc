#pragma once

#include"Node.h"

class Tree {
private:
    Node* root;
    void _postorder(Node* node);
    Node* _insert(Node* node, int _id, int _vuelo, string _mat);
    Node* _sort(Node* root);

public:
    Tree() { root = nullptr; }
    ~Tree() {}
    void postorder() { _postorder(root); cout << "\n"; }
    void insert(int _id, int _vuelo, string _mat) { this->root = _insert(root, _id, _vuelo, _mat); }
    void sort() { _sort(root); }

    Node* getRoot() { return root; }
};

void Tree::_postorder(Node* node) {
    if (node == nullptr) {
        return;
    }

    _postorder(node->left);
    _postorder(node->right);
    cout << node->id << "\t" << node->vuelo << "\t" << node->mat << "\n";
}

Node* Tree::_insert(Node* node, int _id, int _vuelo, string _mat) {
    if (node == nullptr) {
        return new Node(_id, _vuelo, _mat);
    }

    if (_id < node->id) {
        node->left = _insert(node->left, _id, _vuelo, _mat);
    }
    else {
        node->right = _insert(node->right, _id, _vuelo, _mat);
    }

    return node;
}


Node* Tree::_sort(Node* node) {


    return node;
}
