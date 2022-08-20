
/*PC2 Fu Ye Liliana*/
/*U20201E987*/

#include<iostream>
#include<conio.h>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;
using namespace System;


struct vNode {
	int id;
	int age;
	string education;
	string marital;
	string occupation;
	string relationship;
	string sex;
	int gain;
	int loss;
	int hours;
	string country;

	vNode(int _id, int _age, string _education, string _marital, string _occupation, string _relationship, string _sex, int _gain, int _loss, int _hours, string _country) {
		id = _id;
		age = _age;
		education = _education;
		marital = _marital;
		occupation = _occupation;
		relationship = _relationship;
		sex = _sex;
		gain = _gain;
		loss = _loss;
		hours = _hours;
		country = _country;
	}
	vNode() {}
};


struct treeNode {
	int id;
	int age;
	string education;
	string marital;
	string occupation;
	string relationship;
	string sex;
	int gain;
	int loss;
	int hours;
	string country;

	treeNode* left;
	treeNode* right;

	treeNode(int _id, int _age, string _education, string _marital, string _occupation, string _relationship, string _sex, int _gain, int _loss, int _hours, string _country ) {
		id = _id;
		age = _age;
		education = _education;
		marital = _marital;
		occupation = _occupation;
		relationship = _relationship;
		sex = _sex;
		gain = _gain;
		loss = _loss;
		hours = _hours;
		country = _country;
		left = right = nullptr;
	}
	treeNode() {}
};



class Tree {
private:
	treeNode* root;
	void _preorder(treeNode* node);
	treeNode* _insert(treeNode* node, int id, int age, string education, string marital, string occupation, string relationship, string sex, int gain, int loss, int hours, string country);
	int registers;
	int _rangeCount(treeNode* root, int low, int high);
public:
	Tree() { 
		root = nullptr; 
		registers = 0;
	}
	~Tree() {}
	void preorder() { _preorder(root); cout << "\n"; }
	void insert(int id, int age, string education, string marital, string occupation, string relationship, string sex, int gain, int loss, int hours, string country) { 
		root = _insert(root, id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country); 
	}
	void Register();
	int rangeCount(int low, int high) { return _rangeCount(root, low, hight); }
};

void Tree::_preorder(treeNode* node) {
	if (node == nullptr) {
		cout << "No data\n";
		return;
	}
	cout << "[" << node->id << " , " << node->age << " , " << node->education << " , " << node->marital << " , " << node->occupation << " , " << node->relationship << " , " << node->sex << " , " << node->gain << " , " << node->loss << " , " << node->hours << " , " << node->country << "]\n";
	_preorder(node->left);
	_preorder(node->right);

}

treeNode* Tree::_insert(treeNode* node, int id, int age, string education, string marital, string occupation, string relationship, string sex, int gain, int loss, int hours, string country) {
	/*first root*/
	if (node == nullptr) {
		return new treeNode(id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);
	}

	/*then lef*/
	if (id < node->id) {
		node->left = _insert(node, id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);
	}
	/*at last right (PREORDER)*/
	else {
		node->right = _insert(node, id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);
	}

	registers++;
	return node;
}


void Tree::Register() {
	int id;
	int age;
	string education;
	string marital;
	string occupation;
	string relationship;
	string sex;
	int gain;
	int loss;
	int hours;
	string country;

	id = registers + 1;
	cout << "(int) age: "; cin >> age;
	cout << "(str) education: "; cin >> education;
	cout << "(str) marital: "; cin >> marital;
	cout << "(str) occupation: "; cin >> occupation;
	cout << "(str) relationship: "; cin >> relationship;
	cout << "(str) sex: "; cin >> sex;
	cout << "(int) gain: "; cin >> gain;
	cout << "(int) loss: "; cin >> loss;
	cout << "(int) hours: "; cin >> hours;
	cout << "(str) country: "; cin >> country;

	insert(id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);
}


int Tree::_rangeCount(treeNode* root, int low, int high) {

	if (root == nullptr) {
		return 0;
	}
	if (root->id <= low && root->id >= high) {
		return 1 + _rangeCount(root->left, low, high) + _rangeCount(root->right, low, high);
	}
	else if (root->id < low) {
		return _rangeCount(root->right, low, high);
	}
	else {
		return _rangeCount(root->left, low, high);
	}

}





//int partition(vector<vNode>*v, int left, int right) {
//	int pivot = v->at(right);
//	int i = left;
//	for (int j = left; j < right; j++) {
//		if (v->at(j) <= pivot) {
//			swap(v->at(i), v->at(j));
//			i++;
//		}
//	}
//	swap(v->at(i), v->at(right));
//	return i;
//}
//
//
//void quickSort(vector<vNode>v, int left, int right) {
//	if (left < right) {
//		int pivot_index = partition(v, left, right);
//		quickSort(v, left, pivot_index - 1);
//		quickSort(v, pivot_index + 1, right);
//	}
//}





struct hashNode {
	int id;
	int age;
	string education;
	string marital;
	string occupation;
	string relationship;
	string sex;
	int gain;
	int loss;
	int hours;
	string country;

	hashNode* next;
	hashNode(int _id, int _age, string _education, string _marital, string _occupation, string _relationship, string _sex, int _gain, int _loss, int _hours, string _country) {
		id = _id;
		age = _age;
		education = _education;
		marital = _marital;
		occupation = _occupation;
		relationship = _relationship;
		sex = _sex;
		gain = _gain;
		loss = _loss;
		hours = _hours;
		country = _country;
		next = nullptr;
	}
};

class List {
private:
	hashNode* head;
	int size;
	int collisions;
public:
	List() {
		head = nullptr;
		size = 0;
		collisions = 0;
	}
	~List() {}


	/*if not collision push front*/
	void push_front(int id, int age, string education, string marital, string occupation, string relationship, string sex, int gain, int loss, int hours, string country) {
		hashNode* newNode = new hashNode(id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);

		if (head == nullptr)
			head = newNode;
		else {
			newNode->next = head;
			head = newNode;
		}
		size++;
	}


	/*if collision push back, nope no hice el push al centro de la lista :c*/
	void push_back(int id, int age, string education, string marital, string occupation, string relationship, string sex, int gain, int loss, int hours, string country) {

		if (head == nullptr) {
			push_front(id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);
			return;
		}

		hashNode* newLast = new hashNode(id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);
		hashNode* current = head;

		while (current->next != nullptr) {
			current = current->next;
		}

		current->next = newLast;
	}

	void push(int id, int age, string education, string marital, string occupation, string relationship, string sex, int gain, int loss, int hours, string country) {

		if (head == nullptr) {
			//cout << "[] Sin colisiones\n";
			push_front(id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);
			return;
		}

		//cout << "[WARNING] Hay colision \n";
		collisions++;
		push_back(id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);
	}

	void show() {
		hashNode* node = head;

		while (node != nullptr) {
			cout << "[" << node->id << " , " << node->age << " , " << node->education << " , " << node->marital << " , " << node->occupation << " , " << node->relationship << " , " << node->sex << " , " << node->gain << " , " << node->loss << " , " << node->hours << " , " << node->country << "]\n";
			node = node->next;
		}
		cout << "NUMERO DE COLISIONES EN ESTA LISTA: " << collisions << "\n";
	}
};



class hashMap {
private:
	static const int nRows = 10;
	List* rows;

public:
	hashMap() {
		rows = new List[nRows];
	}
	~hashMap() {}

	int hash(int key) {
		return key % nRows;
	}

	void insert(int id, int age, string education, string marital, string occupation, string relationship, string sex, int gain, int loss, int hours, string country) {
		int hashCode = hash(id);
		rows[hashCode].push(id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country);
	}

	void show() {
		for (int i = 0; i < nRows; i++) {
			cout << "ROW " << i << "\n";
			rows[i].show();
			cout << "\n\n";
		}
	}
};



void read_csv(string filename, vector<vNode>* vector, Tree* root, bool isVector, bool isTree) {

	ifstream inputFile;
	inputFile.open(filename);
	string line = "";
	if (inputFile.is_open()) {
		string firstLine;
		getline(inputFile, firstLine);
		while (getline(inputFile, line)) {
			string id, age, education, marital, occupation, relationship, sex, gain, loss, hours, country;

			stringstream inputString(line);
			getline(inputString, id, ',');
			getline(inputString, age, ',');
			getline(inputString, education, ',');
			getline(inputString, marital, ',');
			getline(inputString, occupation, ',');
			getline(inputString, relationship, ',');
			getline(inputString, sex, ',');
			getline(inputString, gain, ',');
			getline(inputString, loss, ',');
			getline(inputString, hours, ',');
			getline(inputString, country, ',');

			if (isVector) {
				vector->push_back(vNode(stoi(id), stoi(age), education, marital, occupation, relationship, sex, stoi(gain), stoi(loss), stoi(hours), country));
			}
			else if (isTree) {
				root->insert(stoi(id), stoi(age), education, marital, occupation, relationship, sex, stoi(gain), stoi(loss), stoi(hours), country);
			}

		}
	}
	else {
		cout << "No se ha podido abrir el csv\n";
		_getch();
	}

	inputFile.close();
}


int main() {
	srand(time(NULL));
	int option = 0;

	Tree* root = new Tree();
	vector<vNode>* stl = new vector<vNode>();
	hashMap* hash = new hashMap();

	/*En estos dos casos deberia haber colision por el id*/
	hash->insert(121, 23, "education", "marital", "occuptaion", "relationship", "sex", 23, 45, 21, "pais");
	hash->insert(121, 23, "education", "marital", "occuptaion", "relationship", "sex", 23, 45, 21, "pais");

	hash->insert(1123, 23, "education", "marital", "occuptaion", "relationship", "sex", 23, 45, 21, "pais");
	hash->insert(93, 23, "education", "marital", "occuptaion", "relationship", "sex", 23, 45, 21, "pais");
	hash->insert(83, 23, "education", "marital", "occuptaion", "relationship", "sex", 23, 45, 21, "pais");
	hash->insert(31, 23, "education", "marital", "occuptaion", "relationship", "sex", 23, 45, 21, "pais");
	hash->insert(13, 23, "education", "marital", "occuptaion", "relationship", "sex", 23, 45, 21, "pais");


	/*insert para arbol*/
	root->insert(123123, 23, "education", "marital", "occuptaion", "relationship", "sex", 23, 45, 21, "pais");
	/*CSV READ*/
	cout << "Iniciando programa, se estan leyendo los datos . . . \n";
	//read_csv("ingresos.csv", nullptr, root, false, true);
	read_csv("ingresos.csv", stl, nullptr, true, false);

	//root->rangeCount(3, 6);

	do {
		system("CLS");
		cout << "MENU\n";
		cout << "1. Registro a arbol\n";
		cout << "2. Mostrar datos de arbol\n";
		cout << "3. Ordenar por nacimiento MERGESORT\n";
		cout << "4. Show hash\n";
		cout << "5. Salir\n";
		cout << "Tu opcion ->"; cin >> option;
		system("CLS");

		switch (option) {
		case 1:
			root->Register();
			break;
		case 2:
			root->preorder();
			break;
		case 3:
			//quickSort(stl, 0, stl->size() - 1)
			break;
		case 4:
			hash->show();
			break;
		case 5:
			exit(0);
			break;
		default:
			break;
		}

		cout << "\n";
		system("PAUSE");

	} while (option < 6);



	_getch();
	return 0;
}