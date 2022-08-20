
#include"Binary.h"
#include"Hash.h"

#include <fstream>
#include <sstream>

struct stlData {
    int id, vuelo;
    string mat;

    stlData(int _id, int _vuelo, string _mat) {
        id = _id;
        vuelo = _vuelo;
        mat = _mat;
    }
    stlData(){}
};

void generateData(vector<stlData>*stlVector, hashMap*hMap, bool isVector, bool isHash) {
    int numData = rand() % 4901 + 100;
    int id, vuelo;
    string mat = "";

    for (int i = 0; i < numData; i++) {
        id = rand() % 9000 + 1000;
        vuelo = rand() % 90000 + 10000;
        mat += char(rand() % 26 + 65);
        mat+= char(rand() % 26 + 65);
        mat += char(rand() % 10 + 48);
        mat += char(rand() % 10 + 48);
        mat += char(rand() % 10 + 48);


        if (isVector){
            stlVector->push_back(stlData(id, vuelo, mat));
        }
        else if (isHash) {
            hMap->insert(id, vuelo, mat);
        }

        mat = "";
    }

    cout << numData << " generados en el vector de aviones\n";
}

void showSTL(vector<stlData>* stlVector) {
    cout << "AEROLINEA\tVUELO\tMATRICULA\n";
    for (int i = 0; i < stlVector->size(); i++) {
        cout << stlVector->at(i).id << "\t";
        cout << stlVector->at(i).vuelo << "\t";
        cout << stlVector->at(i).mat << "\n";
    }
    cout <<"Cantidad de datos: "<< stlVector->size() << "\n";
}

auto indexTree(vector<stlData>* stlVector, Tree*root) {
    for (int i = 0; i < stlVector->size(); i++) {
        root->insert(stlVector->at(i).id, stlVector->at(i).vuelo, stlVector->at(i).mat);
    }
    cout << "Vector indexado en arbol\n";
    return root;
}


void read_csv(string filename, vector<stlData>* stlVector) {
    ifstream inputFile;
    inputFile.open(filename);
    string line = "";
    if (inputFile.is_open()) {
        while (getline(inputFile,line)) {
            string id, vuelo, mat;

            stringstream inputString(line);

            getline(inputString, id, ',');
            getline(inputString, vuelo, ',');
            getline(inputString, mat, ',');

            stlVector->push_back(stlData(stoi(id), stoi(vuelo), mat));
        }
    }

    inputFile.close();
}




int main() {
    srand(time(NULL));
	int option = 0;

    vector<stlData>* aviones = new vector<stlData>();
    Tree* root = new Tree();
    hashMap* table = new hashMap();

	do {
		system("CLS");
		cout << "MENU\n";
		cout << "1. Generar datos\n";
        cout << "2. Mostrar datos de stl vector sin indexar \n";
		cout << "3. Indexar en arbol binario de busqueda\n";
		cout << "4. Ordenar por ID VUELO\n";
		cout << "5. Mostrar datos de arbol binario por postorder\n";
		cout << "6. Hash Table\n";
		cout << "7. Show hash\n";
        cout << "8. Salir\n";
		cout << "Tu opcion ->"; cin >> option;
        system("CLS");

		switch (option) {
		case 1:
            generateData(aviones, nullptr, true, false);
			break;
		case 2:
            showSTL(aviones);
			break;
		case 3:
            root = indexTree(aviones, root);
			break;
		case 4:
			break;
		case 5:
            root->postorder();
            break;
        case 6:
            generateData(nullptr, table, false, true);
            break;
		case 7:
            table->show();
			break;
        case 8:
            exit(0);
            break;
		default:
			break;
		}

		cout << "\n";
		system("PAUSE");

	} while (option < 8);



	_getch();
	return 0;
}