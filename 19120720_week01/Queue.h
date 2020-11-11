#pragma once
#include<iostream>
using namespace std;

struct NODE {
	int key;
	struct NODE*pNext;
};


bool isEmtyQueue(NODE* Q);

void initQueue(NODE*& Q , int data );

void enQueue(NODE*& Q, int k);

int deQueue(NODE*& Q);

int countQueue(NODE* Q);

void printQueue(NODE*Q);