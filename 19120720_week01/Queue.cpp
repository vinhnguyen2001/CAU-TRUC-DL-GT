#include"Queue.h"

bool isEmtyQueue(NODE* S) {

	/*
	Kiem tra QUEUE rong hay khong ?
	+ Rong tra ve true, nguoc lai tra ve false.

	*/
	return S == nullptr;
}

void initQueue(NODE*& Q, int data) {

	// Khoi tao Queue tu mot gia tri cho truoc data

	Q = new (std::nothrow) NODE;
	if (Q) {
		Q->key = data;
		Q->pNext = nullptr;
	}
}

void enQueue(NODE*& Q, int data) {

	// Them gia tri data vao trong Queue
	if (isEmtyQueue(Q)) {
		initQueue(Q, data);
	}
	else {
		NODE* cur = nullptr;
		cur = new (std::nothrow) NODE;
		if (!cur) {
			cout << "\nHeap Overflow! ";
			return;
		}
		cur->key = data;
		cur->pNext = nullptr;
		NODE* req = Q;
		for (; req->pNext; req = req->pNext);
		req->pNext = cur;
	}
}


int countQueue(NODE* Q) {

	/*
	Dem so luong phan tu co trong Queue:
	+ Neu danh sach rong tra ve 0
	+ Nguoc lai, tra ve so phan tu co trong Queue

	*/

	int count = 0;
	if (!isEmtyQueue(Q)) {

		NODE* cur = Q;
		while (cur) {
			count++;
			cur = cur->pNext;
		}
	}
	return count;
}

int deQueue(NODE*& Q) {

	/* Lay mot gia tri ra khoi Queue:
	+ Neu Queue rong tra ve NULL
	+ Nguoc lai, tra ve phan tu dau tien cua QUEUE

	*/
	if (!isEmtyQueue(Q)) {

		int key = Q->key;
		if (countQueue(Q) == 1) {

			delete Q;
			Q = nullptr;
		}
		else {
			NODE* cur = Q;
			Q = Q->pNext;
			delete cur;
			cur = nullptr;
		}
		return key;
	}
	else return NULL;
}


void printQueue(NODE* top) {
	 
	//In gia tri cua cac phan tu co trong Queue

	NODE* cur = top;
	if (isEmtyQueue(top)) {
		cout << "\nStack Underflow!";
		return;
	}
	while (cur) {
		cout << cur->key << " ";
		cur = cur->pNext;
	}
	cout << endl;
}

void destroyQueue(NODE*& Q) {
	
	if(isEmtyQueue(Q)){
		return;
	}
	NODE* temp = Q;
	while (temp) {

		Q=temp->pNext;
		delete  temp;
		temp = Q;
	}
}

int main() {

	NODE* Q = nullptr;
	initQueue(Q,5);
	cout << "QUEUE RONG HAY KHONG : " << isEmtyQueue(Q);
	cout << "\nCOUNT : " << countQueue(Q);

	cout<<"\nGIA TRI :" <<deQueue(Q);
	cout << "\nCOUNT : " << countQueue(Q);

	enQueue(Q, 6);
	enQueue(Q, 7);
	enQueue(Q, 8);
	enQueue(Q, 9);
	enQueue(Q, 10);
	enQueue(Q, 11);
	enQueue(Q, 12);
	cout << "\nCOUNT : " << countQueue(Q);
	cout << "\nGIA TRI :" << deQueue(Q);
	cout << "\nCOUNT : " << countQueue(Q) << endl;
	printQueue(Q);

	destroyQueue(Q);
	
	return 0;
}