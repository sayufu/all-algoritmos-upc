#include<iostream>
#include<conio.h>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	int height;
	Node(int _key) {
		key = _key;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
	Node(){ }
};

//procuramos siempre O(logn)
class AVL {
private:
	Node* root;

	int max(int a, int b) {
		return (a > b) ? a : b;
	}
	int height(Node* node) {
		if (node == nullptr) {
			return 0;
		}
		return node->height;
	}
	int getBalance(Node* node) {
		if (node == nullptr) {
			return 0;
		}
		return height(node->left) - height(node->right);
	}

	Node* rightRotate(Node* y){
		Node* x = y->left;
		Node* T2 = x->right;

		x->right = y;
		y->left = T2;

		y->height = max(height(y->left),height(y->right)) + 1;
		x->height = max(height(x->left),height(x->right)) + 1;

		return x;
	}

	Node* leftRotate(Node* x) {
		Node* y = x->right;
		Node* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(height(x->left),height(x->right)) + 1;
		y->height = max(height(y->left),height(y->right)) + 1;

		return y;
	}

	Node* _insert(Node* node, int key) {
		if (node == nullptr) {
			return new Node(key);
		}

		if (key < node->key) {
			node->left = _insert(node->left, key);
		}
		else if (key > node->key) {
			node->right = _insert(node->right, key);
		}
		else {
			return node;
		}

		node->height = 1 + max(height(node->left), height(node->right));

		int balance = getBalance(node);

		if (balance > 1 && key < node->left->key)
			return rightRotate(node);

		if (balance < -1 && key > node->right->key)
			return leftRotate(node);

		if (balance > 1 && key > node->left->key) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		if (balance < -1 && key < node->right->key) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}

	Node* minValueNode(Node* node) {
		Node* current = node;

		while (current->left != nullptr)
			current = current->left;

		return current;
	}

	Node* _deleteNode(Node* node, int key) {
		if (node == nullptr) {
			return node;
		}
		if (key < node->key) {
			node->left = _deleteNode(node->left, key);
		}
		else if (key > node->key) {
			node->right = _deleteNode(node->right, key);
		}
		//Cuando encontremos el nodo
		else {
			if ((node->left == nullptr) ||(node->right == nullptr)){
				Node* temp = node->left ? node->left : node->right;
				if (temp == nullptr) {
					temp = node;
					node = nullptr;
				}
				else {
					*node = *temp;
				}
				free(temp);
			}
			else {
				Node* temp = minValueNode(node->right);

				node->key = temp->key;

				node->right = _deleteNode(node->right,temp->key);
			}
		}

		if (node == nullptr)
			return node;

		node->height = 1 + max(height(node->left),height(node->right));

		int balance = getBalance(node);

		if (balance > 1 && getBalance(node->left) >= 0) {
			return rightRotate(node);
		}

		if (balance > 1 && getBalance(node->left) < 0) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		if (balance < -1 && getBalance(node->right) <= 0) {
			return leftRotate(node);
		}

		if (balance < -1 && getBalance(node->right) > 0) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}


	void _preorder(Node*node) {
		if (node == nullptr) {
			return;
		}
		cout << node->key << " ";
		_preorder(node->left);
		_preorder(node->right);
	}

public:
	AVL() {
		root = nullptr;
	}
	~AVL() {}

	void insert(int key) {
		this->root = _insert(root, key);
	}
	void preorder() {
		_preorder(this->root);
	}
	void deletenode(int key) {
		this->root = _deleteNode(root, key);
	}
};

int main() {
	AVL* tree = new AVL();
	tree->insert(10);
	tree->insert(20);
	tree->insert(30);
	tree->insert(40);
	tree->insert(70);
	tree->insert(90);
	tree->insert(110);
	tree->insert(120);
	tree->preorder();
	tree->deletenode(20);
	tree->deletenode(120);
	tree->deletenode(110);
	cout << "\n";
	tree->preorder();

	_getch();
	return 0;
}