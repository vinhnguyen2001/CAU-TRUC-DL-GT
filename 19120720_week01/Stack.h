#pragma once

#include<iostream>
using namespace std;


struct NODE{
	int key ;
  struct NODE* pNext;
};

bool isEmtyStack(NODE* top);

void initStack(NODE*& top , int data );

void pushStack(NODE*& top, int data);

int  popStack(NODE*& top);

void printStack( NODE * top);

int  countStack(NODE* top);

