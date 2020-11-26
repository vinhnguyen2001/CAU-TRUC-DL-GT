#include"BalanceTree.h"

NODE* createNode(int data) {

	//Khoi tao 1 node tu 1 gia tri cho truoc

	NODE* temp = new (std::nothrow) NODE;
    
	if (temp) {
		temp->key = data;
		temp->p_left = temp->p_right = nullptr;
		temp->balance = 0;
	}

	return temp;
}

int Insert(NODE*& pRoot, int x) {

	// Them vao 1 node co gia tri cho truoc x 

	int temp = 0;
	if (!pRoot) {
		pRoot = createNode(x);
	}
	else if (pRoot->key > x) {

		temp = Insert(pRoot->p_left, x);

		if (temp < 2) {
			return temp;
		}
		switch (pRoot->balance) {

		case 0:pRoot->balance = -1; return 2;
		case 1:pRoot->balance = 0; return 1;
		case -1:getBalance(pRoot); return 1;
		}
	}
	else if (pRoot->key < x) {

		temp = Insert(pRoot->p_right, x);

		if (temp < 2) {
			return temp;
		}
		switch (pRoot->balance) {

		case 0:pRoot->balance = 1; return 2;
		case -1:pRoot->balance = 0; return 1;
		case 1:getBalance(pRoot); return 1;
		}
	}
}

void Remove(NODE*& pRoot, int x) {

	// xoa 1 node co gia tri cho truoc x

	if (!pRoot) {
		return;
	}
	else if (x > pRoot->key) Remove(pRoot->p_right, x);

	else if (x < pRoot->key) Remove(pRoot->p_left, x);

	else if (x == pRoot->key) {

		NODE* p = pRoot;

		if (!pRoot->p_left) {

			pRoot = pRoot->p_right;
			delete p;
		}
		else if (!pRoot->p_right) {

			pRoot = pRoot->p_left;
			delete p;
		}
		else {
			NODE* q = pRoot->p_right;

			while (q->p_left) {

				q = q->p_left;
			}

			p->key = q->key;
			Remove(pRoot->p_right, q->key);
		}
	}
}

void NLR(NODE* pRoot) {

	// duyet tien thu tu

	if (!pRoot) {
		return;
	}

	cout << pRoot->key<<" ";
	NLR(pRoot->p_left);
	NLR(pRoot->p_right);
}

void LNR(NODE* pRoot) {

	// duyet trung thu tu 

	if (!pRoot) {
		return;
	}

	NLR(pRoot->p_left);
	cout << pRoot->key<<" ";

	NLR(pRoot->p_right);
}

void LRN(NODE* pRoot) {

	//duyet hau thu tu

	if (!pRoot) {
		return;
	}

	NLR(pRoot->p_left);
	NLR(pRoot->p_right);

	cout << pRoot->key<<" ";
}

void LevelOrder(NODE* pRoot) {

	//duyet theo tang 

	int level = 1;

	while (printLevel(pRoot, level)) {
		level++;
		cout << endl;
	}

}

bool isAVL(NODE* pRoot){

	// kiem tra cay co phai la cay avl hay khong 

	if (!pRoot) return true;

	int a = heightTree(pRoot->p_left);
	int b = heightTree(pRoot->p_right);

	if (a - b > 1 || a - b < -1) {
		return false;
	}
	return isAVL(pRoot->p_left) && isAVL(pRoot->p_right);
}

int heightTree(NODE* pRoot){

	// chieu cao cua cay 

	if (!pRoot) return 0;
	int left = heightTree(pRoot->p_left);
	int right = heightTree(pRoot->p_right);
	return 1 + (left > right ? left : right);
}

void rightRotate(NODE*& pRoot){
	
	// xoay phai 

	if (!pRoot) return;
	NODE* q = pRoot->p_left;
	pRoot->p_left = q->p_right;
	q->p_right = pRoot;
	switch (q->balance) {
	case -1: {
		q->balance = 0;
		pRoot->balance = 0;
		break;
	}
	case 0: {
		if (!q->p_right) {
			q->balance = 0;
			pRoot->balance = -1;
		}
		else {
			q->balance = 1;
			pRoot->balance = -1;
		}
		break;
	}
	}
	pRoot = q;
}
void leftRotate(NODE*& pRoot) {

	// xoay trai 

	if (!pRoot) return;

	NODE* q = pRoot->p_right;
	pRoot->p_right = q->p_left;
	q->p_left = pRoot;
	switch (q->balance) {
	case 1: {
		q->balance = 0;
		pRoot->balance = 0;
		break;
	}
	case 0: {
		if (!q->p_right) {
			q->balance = 0;
			pRoot->balance = 1;
		}
		else {
			q->balance = -1;
			pRoot->balance = 1;
		}
		break;
	}
	}
	pRoot = q;
}

void getBalance(NODE*& pRoot){

	// lam cay can bang

	if (pRoot->balance == 0 || !pRoot) {
		return;
	}
	else if (!isAVL(pRoot) && pRoot->balance == 1) {

		if (pRoot->p_right->balance == 0) {

			return;
		}
		else if (pRoot->p_right->balance == 1) {

			leftRotate(pRoot);
		}
		else {

			rightRotate(pRoot->p_right);
			leftRotate(pRoot);
		}
	}
	else if (!isAVL(pRoot) && pRoot->balance == -1) {
		if (pRoot->p_left->balance == 0) {

			return;
		}
		else if (pRoot->p_left->balance == -1) {

			rightRotate(pRoot);
		}
		else {

			leftRotate(pRoot->p_left);
			rightRotate(pRoot);
		}
	}
}

bool printLevel(NODE* pRoot, int level) {

	if (!pRoot) {
		return false;
	}
	if (level == 1) {
		cout << "  " << pRoot->key;
		return true;
	}

	int leftKey = printLevel(pRoot->p_left, level - 1);
	int rightKey = printLevel(pRoot->p_right, level - 1);

	return leftKey || rightKey;

}

int main() {

	NODE* pRoot = nullptr;

	int n = 13;

	int a[] = { 15,10,33,4,21,12,35,3,7,11,34,27,45 };

	

	for (int i = 0; i < n; i++) {
		Insert(pRoot, a[i]);
	}
	/*
											 15

									 /                 \
								   10                     33

							  /         \             /        \
							4            12        21          35

						/       \    /                 \     /     \
					  3          7  11                  27  34       45

	*/

	if (isAVL(pRoot)) {
		cout << "\nLA CAY AVL ";
	}
	else cout << "\nKHONG PHAI CAY AVL";

	cout << "\nDUYET THEO LNR: ";
	LNR(pRoot);

	cout << "\nDUYET THEO LRN: ";
	LRN(pRoot);

	cout << "\nDUYET THEO NLR: ";
	NLR(pRoot);

	cout << "\nIN THEO TANG " << endl;
	LevelOrder(pRoot);
	int value = 15;
	cout << "\nXOA NODE CO GIA TRI: " << value << endl;

	Remove(pRoot, 15);
	cout << "\nCAY SAU KHI XOA: " << endl;
	LevelOrder(pRoot);



}