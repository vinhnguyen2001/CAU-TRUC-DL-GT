#include<iostream>

using namespace std;

struct d_NODE {
	int key;
	d_NODE* pNext;
	d_NODE* pPrev;
};


struct d_List {
	d_NODE* pHead;
	d_NODE* pTail;
};

bool isEmty(d_List* r_list);

d_List* createList(int value);

d_NODE* createNode(int value);

void addHead (d_List*& u_list, int value);

void addTail(d_List*& u_list, int value);

void insertBefore(d_List*& u_list,d_NODE *pre_Node, int value);

void insertAfter(d_List*& u_list, d_NODE* pre_Node, int value);

void deleteHead(d_List*& u_list);

void deleteTail(d_List*& u_list);

void printList(d_List* r_list);