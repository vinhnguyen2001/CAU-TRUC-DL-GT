#pragma once
#include<iostream>

using namespace std;

struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
	int balance;
};


NODE* createNode(int data);

int  Insert(NODE*& pRoot, int x);

void Remove(NODE*& pRoot, int x);

void NLR(NODE* pRoot);

void LNR(NODE* pRoot);

void LRN(NODE* pRoot);

void LevelOrder(NODE* pRoot);

bool isAVL(NODE* pRoot);

int heightTree(NODE* pRoot);

void rightRotate(NODE*& pRoot);

void leftRotate(NODE*& pRoot);

bool printLevel(NODE* pRoot, int level);

void RightBalance(NODE*& P);

void LeftBalance(NODE*& P);

void removetree(NODE*& pRoot);;