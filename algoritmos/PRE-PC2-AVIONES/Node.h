#pragma once
#include<iostream>
#include<conio.h>
#include<vector>
#include<string>

using namespace std;
using namespace System;

struct Node {
    int id, vuelo;
    string mat;
    Node* left;
    Node* right;
    Node(int _id, int _vuelo, string _mat) {
        id = _id;
        vuelo = _vuelo;
        mat = _mat;
        left = right = nullptr;
    }
};