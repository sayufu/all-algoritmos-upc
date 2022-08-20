#pragma once

#include"Node.h"


struct hashNode {
    int id, vuelo;
    string mat;
    int hash;
    hashNode* next;
    hashNode(int _id, int _vuelo, string _mat, int _hash) {
        id = _id;
        vuelo = _vuelo;
        mat = _mat;
        hash = _hash;
        next = nullptr;
    }
};

class List {
private:
    hashNode* head;
    int size;
public:
    List() {
        head = nullptr;
        size = 0;
    }
    ~List() {}


    /*if not collision push front*/
    void push_front(int _id, int _vuelo, string _mat, int hash) {
        hashNode* newNode = new hashNode(_id, _vuelo, _mat, hash);

        if (head == nullptr)
            head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }


    /*if collision push back*/
    void push_back(int _id, int _vuelo, string _mat, int hash) {

        if (head == nullptr) {
            push_front(_id, _vuelo, _mat, hash);
            return;
        }

        hashNode* newLast = new hashNode(_id, _vuelo, _mat, hash);
        hashNode* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newLast;
    }

    ///*if collision push random*/
    //void push_random(int _id, int _vuelo, string _mat, int hash) {
    //    if (head == nullptr) {
    //        push_front(_id, _vuelo, _mat, hash);
    //        return;
    //    }

    //    int randomPos = rand() % size;
    //    hashNode* current = head;

    //    cout << randomPos << "\n";
    //    cout << size << "\n";
    //    for (int i = 0; i < randomPos - 1; i++) {
    //        cout << i << "\n";
    //        current = current->next;
    //    }

    //    if (current == nullptr || current->next == nullptr)
    //        return;

    //    hashNode* newNext = current->next->next;
    //    current->next = newNext;
    //    size++;
    //}

    void push(int _id, int _vuelo, string _mat, int hash) {

        if (head == nullptr) {
            //cout << "[TESTER ANNOUNCE] Pushed without further issues\n";
            push_front(_id, _vuelo, _mat, hash);
            return;
        }

        //cout << "[WARNING] Collision found in matricula " << _mat << "\n";
        push_back(_id, _vuelo, _mat, hash);
    }

    void show() {
        hashNode* current = head;

        while (current != nullptr) {
            cout << "[" << current->id << " , " << current->vuelo << " , " << current->mat << " , " << current->hash << "]\n";
            current = current->next;
        }
    }

    bool search(string hashString) {
        hashNode* current = head;

        while (current != nullptr) {
            if (current->mat == hashString) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void remove(string hashKey) {
        //// If linked list is empty
        //if (*head_ref == NULL)
        //    return;

        //// Store head node
        //Node* temp = *head_ref;

        //// If head needs to be removed
        //if (position == 0) {

        //    // Change head
        //    *head_ref = temp->next;

        //    // Free old head
        //    free(temp);
        //    return;
        //}

        //// Find previous node of the node to be deleted
        //for (int i = 0; temp != NULL && i < position - 1; i++)
        //    temp = temp->next;

        //// If position is more than number of nodes
        //if (temp == NULL || temp->next == NULL)
        //    return;

        //// Node temp->next is the node to be deleted
        //// Store pointer to the next of node to be deleted
        //Node* next = temp->next->next;

        //// Unlink the node from linked list
        //free(temp->next); // Free memory

        //// Unlink the deleted node from list
        //temp->next = next;
    }


};




class hashMap {
private:
    static const int nRows = 31;
    List* rows;

public:
    hashMap() {
        rows = new List[nRows];
    }
    ~hashMap(){}

    int hash(string key) {
        int hashCode = 0;

        for (char ch : key) {
            hashCode += int(ch);
        }

        return hashCode % nRows;
    }

    void insert(int _id, int _vuelo, string _mat) {
        int hashCode = hash(_mat);
        rows[hashCode].push(_id, _vuelo, _mat, hashCode);
    }

    void remove(string hashKey) {
        int listPos = hash(hashKey);
        rows[listPos].remove(hashKey);
    }

    void search(string hashKey) {
        int listPos = hash(hashKey);
        cout << listPos;
        rows[listPos].search(hashKey) ? cout << "Found\n" : cout << "Not found\n";
    }


    void show() {
        for (int i = 0; i < nRows; i++) {
            cout << "ROW " << i << "\n";
            rows[i].show();
            cout << "\n\n";
        }
    }
};