#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<conio.h>

using namespace std;

template<class T>
class Trie {
    class Node {
    public:
        T key;
        char ch;
        bool isWord;
        Node** children;
        Node(char _ch, T _key) {
            this->key = _key;
            this->ch = _ch;
            this->isWord = false;
            children = new Node * [SIZE];
            for (size_t i = 0; i < SIZE; ++i) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;
public:
    Trie() {
        T rootKey;
        root = new Node('\0', rootKey);
    }

    void insert(string word, T key) {
        Node* current = root;
        for (int i = 0; i < word.size(); i++) {
            char newc = word.at(i);
            if (current->children[newc - 'a'] == nullptr) {
                current->children[newc - 'a'] = new Node(newc, key);
            }
            current = current->children[newc - 'a'];
        }
        current->isWord = true;
    }

    Node* getNode(string word) {
        Node* current = root;
        for (int i = 0; i < word.size(); i++) {
            char newc = word.at(i);
            if (current->children[newc - 'a'] == nullptr) {
                cout << "A";
                return nullptr;
            }
            current = current->children[newc - 'a'];
        }
        return current;
    }


    bool search_exact(string word) {
        Node* node = getNode(word);
        return node != nullptr && node->isWord;
    }

    bool search_starts(string word) {
        return getNode(word) != nullptr;
    }
};



int main() {
    Trie<string>* test = new Trie<string>();
    test->insert("word", "word");
    test->insert("assfg", "assfg");
    test->insert("aasqtu", "aasqtu");
    test->insert("palabra", "palabra");
    cout << test->getNode("pala")->key;
    //if (test->search_exact("aipeoi")) {
    //    cout << "Yes\n";
    //    cout << test->getNode("aipeoi")->key;
    //}


	_getch();
	return 0;
}