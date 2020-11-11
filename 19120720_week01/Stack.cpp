#include"Stack.h"

bool isEmtyStack(NODE* top) {

	/*
       Kiem tra Stack rong hay khong ?
     + Rong tra ve true, nguoc lai tra ve false.

    */
	return top == nullptr;
}

void initStack(NODE*& top, int data) {

	// Khoi tao Stack tu mot gia tri cho truoc data

	top = new (std::nothrow) NODE;
	if (top) {
		top->key = data;
		top->pNext = nullptr;
	}
}

void pushStack(NODE*& top, int data) {	
	/*
	 Them gia tri data vao trong Stack

	*/
	if (isEmtyStack(top)) {
		initStack(top,data);

	}
	else {
		NODE* cur = nullptr;
		cur = new (std::nothrow) NODE;
		if (!cur) {
			cout << "\nHeap Overflow! ";
			return;
		}
		cur->key = data;
		cur->pNext = top;
		top = cur;
	}
}


int  countStack(NODE* top) {
	/*
	Dem so luong phan tu co trong Stack :
	+ Neu danh sach rong tra ve 0
	+ Nguoc lai, tra ve so phan tu co trong Queue

	*/
	int count = 0;
	if (!isEmtyStack(top)) {

		NODE* cur = top;
		while (cur) {
			count++;
			cur = cur->pNext;
		}
	}
	return count;
}


int popStack(NODE*& top) {
	
	/* Lay mot gia tri ra khoi Stack:
	+ Neu Queue rong tra ve NULL
	+ Nguoc lai, tra ve phan tu dau tien cua QUEUE

	*/

	NODE* cur = nullptr;
	if (!isEmtyStack(top)) {
		int key = top->key;
		if (countStack(top) == 1) {

			delete top;
			top = nullptr;
		}
		else {

			cur = top;
			top = top->pNext;
			delete cur;
		}
		return key;
	}
	else return NULL;
}

void printStack(NODE* top) {

	// in gia tri cua cac phan trong Stack 

	NODE* cur = top;
	if (isEmtyStack(top)) {
		cout << "\nStack Underflow!";
		return;
	}
	while (cur) {
		cout << cur->key << " ";
		cur = cur->pNext;
	}
	cout << endl;
}


int main() {



	NODE* Q = nullptr;
	initStack(Q, 5);
	cout << "STACK RONG HAY KHONG : " << isEmtyStack(Q);
	cout << "\nCOUNT : " << countStack(Q);

	cout << "\nGIA TRI :" << popStack(Q);
	cout << "\nCOUNT : " << countStack(Q);


	pushStack(Q, 6);
	pushStack(Q, 7);
	pushStack(Q, 8);
	pushStack(Q, 9);
	pushStack(Q, 10);
	pushStack(Q, 11);
	pushStack(Q, 12);
	cout << "\nCOUNT : " << countStack(Q);
	cout << "\nGIA TRI :" << popStack(Q);
	cout << "\nCOUNT : " << countStack(Q) << endl;
	printStack(Q);

}