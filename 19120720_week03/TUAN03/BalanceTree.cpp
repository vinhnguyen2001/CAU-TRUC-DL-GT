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

void LeftBalance(NODE*& P)
{
	switch (P->p_left->balance) {
	case 1: //mất cân bằng trái trái
		rightRotate(P);
		P->balance = 0;
		P->p_right->balance = 0;
		break;
	case 2: 
		leftRotate(P->p_left);
		rightRotate(P);
		switch (P->balance) {
		case 0:
			P->p_left->balance = 0;
			P->p_right->balance = 0;
			break;
		case 1:
			P->p_left->balance = 0;
			P->p_right->balance = 2;
			break;
		case 2:
			P->p_left->balance = 1;
			P->p_right->balance = 0;
			break;
		}
		P->balance = 0;
		break;
	}
}
void RightBalance( NODE*& P){

	switch (P->p_right->balance) {
	case 1: 
		rightRotate(P->p_right);
		leftRotate(P);
		switch (P->balance) {
		case 0:
			P->p_left->balance = 0;
			P->p_right->balance = 0;
			break;
		case 1:
			P->p_left->balance = 1;
			P->p_right->balance = 0;
			break;
		case 2:
			P->p_left->balance = 0;
			P->p_right->balance = 2;
			break;
		}
		P->balance = 0;
		break;
	case 2: 
		leftRotate(P);
		P->balance = 0;
		P->p_left->balance = 0;
		break;
	}
}
int Insert(NODE*& tree, int x){

	// them 1 node co gia tri x cho truoc

	int res;
	if (!tree) { 
		tree = createNode(x);
		if (tree == NULL) {
			return -1; 
		}
		return 2;
	}
	else {
		if (tree->key == x) {
			return 0; 
		}
		else if (tree->key > x) {
			res = Insert(tree->p_left, x);
			if (res < 2) {
				return res;
			}
			switch (tree->balance) { 
				
			case 0:
				tree->balance = 1;
				return 2;
			case 1:
				LeftBalance(tree);
				return 1;
			case 2:
				tree->balance = 0;
				return 1;
			}
		}
		else {
			res = Insert(tree->p_right, x);
			if (res < 2) {
				return res;
			}
			switch (tree->balance) {
			case 0:
				tree->balance = 2;
				return 2;
			case 1:
				tree->balance = 0;
				return 1;
			case 2:
				RightBalance(tree);
				return 1;
			}
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
	LNR(pRoot->p_left);
	cout << pRoot->key << " ";
	LNR(pRoot->p_right);
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
	NODE* q = nullptr;
	q = pRoot->p_left;
	pRoot->p_left = q->p_right;
	q->p_right = pRoot;
	pRoot = q;
	
}
void leftRotate(NODE*& pRoot) {

	// xoay trai 

	if (!pRoot) return;

	NODE* Q=nullptr;
	Q = pRoot->p_right;
	pRoot->p_right = Q->p_left;
	Q->p_left = pRoot;
	pRoot = Q;
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

void removetree(NODE*& pRoot)
{
	if (!pRoot)
		return;
	removetree(pRoot->p_left);
	removetree(pRoot->p_right);
	if (!pRoot->p_left && !pRoot->p_right)
	{
		NODE* p = pRoot;
		pRoot = pRoot->p_right;
		delete p;
	}
}

int main() {

	NODE* pRoot = nullptr;

	int n = 13;

	//int a[] = { 15,10,33,4,21,12,35,3,7,11,34,27,45 };

	int a[] = { 15,10,11,34,27,45, 33,4,21,12,35,3,7 };

	for (int i = 0; i < n; i++) {
		Insert(pRoot, a[i]);
	}
	/*
											 27

									 /                 \
								   11                     34

							  /         \             /        \
							4            15        33          45

						/       \    /       \         \
					  3          10  12       21        35
					    \
					      7
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

	Remove(pRoot, value);
	cout << "\nCAY SAU KHI XOA: " << endl;
	LevelOrder(pRoot);
	
	removetree(pRoot);
	return 0;


}