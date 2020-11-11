#pragma once
#include<iostream>

using namespace std;

struct Node {
	int data;
	struct Node* pNext;
};

struct List {
	Node* pHead;
	Node* pTail;
};

bool isEmty(const List* r_List);

void initList(List*& L);

List* createList(Node* pnode);

Node* createNode(int data);

bool addHead(List*& L, int data);

bool addTail(List*& L, int data);

void removeHead(List*& L);

void removeTail(List*& L);

void removeAll(List*& u_List);

void printList(List* L);

int countElements(List* L);

List* reverseList(List* L);

void removeDuplicate(List*& L);

bool removeElement(List*& L, int key);


