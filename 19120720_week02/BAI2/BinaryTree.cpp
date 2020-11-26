#include"BinaryTree.h"



NODE* createNode(int data) {
	/*
	+ Ham tao NODE moi voi du lieu cho truoc data
	+ Tra ve NODE moi tao neu cap phat dong thanh cong
	+ Tra ve null neu nguoc lai

	*/
	NODE* temp = new (std::nothrow) NODE;

	if (temp) {

		temp->key = data;
		temp->p_left = nullptr;
		temp->p_right = nullptr;
	}
	return temp;
}

void NLR(NODE* pRoot) {

	// duyet tien thu tu

	if (!pRoot) return;

	cout << pRoot->key << " ";

	if (pRoot->p_left) {

		NLR(pRoot->p_left);
	}
	if (pRoot->p_right) {

		NLR(pRoot->p_right);
	}
}

void LNR(NODE* pRoot) {

	// duyet trung thu tu

	if (!pRoot) return;

	if (pRoot->p_left) {

		LNR(pRoot->p_left);

	}

	cout << pRoot->key << " ";


	if (pRoot->p_right) {

		LNR(pRoot->p_right);
	}
}

void LRN(NODE* pRoot) {

	//duyet hau thu tu

	if (!pRoot) return;

	if (pRoot->p_left) {
		LRN(pRoot->p_left);

	}
	if (pRoot->p_right) {
		LRN(pRoot->p_right);
	}
	cout << pRoot->key << " ";

}

void LevelOrder(NODE* pRoot) {
	
	//duyet tung tang

	int level = 1;

	while (printLevel(pRoot, level)) {
		level++;
		cout << endl;
	}
}


NODE* Search(NODE* pRoot, int x) {

	//tim phan tu co gia tri cho truoc x 

	//C1:

	if (pRoot == nullptr || pRoot->key == x) {

		return pRoot;
	}
	
	if (pRoot->key < x) {

		return	Search(pRoot->p_right, x);
	}
	return Search(pRoot->p_left, x);
}

void Insert(NODE*& cur, int x) {


	if (!cur ) {

		cur = createNode(x);
		return;
	}
	else {
		// giup nhanh duoc 1 vong buoc :)

		if (!cur->p_left && !cur->p_right) {

			if (cur->key < x) {
				cur->p_right = createNode(x);
			}
			else if (cur->key > x) {
				cur->p_left = createNode(x);
			}
			return;
		}

		if (x < cur->key) {
			Insert(cur->p_left, x);
		}
		else if (cur->key < x) {
			Insert(cur->p_right, x);
		}
	}
}

NODE* insertElement(NODE*& pRoot, int x) {

	// them phan tu co gia tri cho truoc

	if (pRoot == nullptr) {
	
		pRoot= createNode(x);
		return pRoot;
	}
	else {
		if (pRoot->key > x) {
			/*pRoot->p_left=*/insertElement(pRoot->p_left,x);
		}
		else if (pRoot->key < x) {
			/*pRoot->p_right= */insertElement(pRoot->p_right, x);
		}
		return pRoot;
	}

}

/*NODE* ReplaceElement(NODE* pRoot) {

	if (!pRoot->p_left) {
		return pRoot->p_left;
	}
	return ReplaceElement(pRoot->p_left);

}*/

NODE* minimunKey(NODE* pRoot) {

	while (pRoot->p_left) {
		pRoot = pRoot->p_left;
	}
	return pRoot;
}

void searchKey(NODE*& curr, int data, NODE*& parent) {

	//C2

	while (curr && curr->key != data) {
		
		parent = curr;
		if (data < curr->key) {
			curr = curr->p_left;
		}
		else curr = curr->p_right;
	}
}

void Remove(NODE*& pRoot, int x){

	// xoa phan tu co gia tri x cho truoc

	NODE* parent = nullptr;

	NODE* curr = pRoot;

	searchKey(curr, x, parent);

	if (curr == nullptr) {
		return;
	}

	//TH1: NODE BI XOA KHONG CO CON
	if (!(curr->p_left && curr->p_right)) {

		if (curr != pRoot) {
			if (parent->p_left == curr) {

				parent->p_left = nullptr;
			}
			else {
				parent->p_right = nullptr;
			}
		}
		else {
			pRoot = nullptr;
		}

		delete curr;
		curr = nullptr;
	}

	//TH2: NODE BI XOA CO 2 CON 
	else if (curr->p_left && curr->p_right) {

		NODE* succ = minimunKey(curr->p_right);

		int value = succ->key;

		Remove(pRoot, succ->key);

		curr->key = value;
	}
	
	//TH3:NODE BI XOA CHI CO 1 CON

	else {
		NODE* child = (curr->p_left) ? curr->p_left : curr->p_right;

		if (curr != pRoot) {
			if (curr == parent->p_left) {
				parent->p_left = child;
			}
			else {
				parent->p_right = child;
			}
		}
		else pRoot = child;

		delete curr;
		curr = nullptr;
	}
}

NODE* createTree(int a[], int n ) {

	// Khoi tao 1 cay nhi phan tim kiem tu 1 mang cho truoc 

	NODE* pRoot = nullptr;
	
	
	for (int i = 0; i < n; i++) {

		Insert(pRoot,  a[i]);
	}
	return pRoot;
}

void removeTree(NODE*& pRoot) {

	// xoa cay nhi phan tim kiem

	if (!pRoot) return;

	if (pRoot->p_left) {
		removeTree(pRoot->p_left);
	}
	if (pRoot->p_right) {
		removeTree(pRoot->p_right);
	}
	delete pRoot;
	pRoot = nullptr;
}

int Height(NODE* pRoot) {
 
	/*
	Chieu cao cua cay nhi phan:
	+Tra ve -1 neu root rong
	+Nguoc lai, tra ve chieu cao thuc cua cay.

	*/
	if (pRoot == nullptr) {
		return -1;
	}
	else { 
		int right = Height(pRoot->p_right);
		int left = Height(pRoot->p_left);
		//int value = (Height(pRoot->p_left) < Height(pRoot->p_right) ? Height(pRoot->p_right) : Height(pRoot->p_left));
		return 1 +(right<left?right:left);
	}	
}

int countNode(NODE* pRoot) {

	// dem so luong node

	if (!pRoot) return 0;
	int count = 1;
	if (pRoot->p_left) {
	    count += countNode(pRoot->p_left);
	}
	if (pRoot->p_right) {
	   count  += countNode(pRoot->p_right);
	}
	return count ;

}

int sumNode(NODE* pRoot) {

	// tinh tong cua toan bo cac node

	if (!pRoot) return 0;
	int sum = pRoot->key;
	
	if (pRoot->p_left ) {
		sum += sumNode(pRoot->p_left);
	}
	if (pRoot->p_right) {
		sum += sumNode(pRoot->p_right);
	}
	return sum;
}

int heightNode(NODE* pRoot, int value) {

	// chieu cao cua cay

	NODE* curr = pRoot;
	while (curr && curr->key!=value) {

		if (value < curr->key) {

			curr = curr->p_left;
		}
		else {
			curr = curr->p_right;
		}
	}

	 return Height(curr);
}

int Level(NODE* pRoot, NODE* p) {

	//tinh tong tang

	int sum = 0;
	if (!pRoot || !p) {
		return -1;
	}

	sum += LevelOrderTraversal(pRoot,Height(pRoot)-Height(p)+1);
	
	return sum;
}


int LevelOrderTraversal(NODE* pRoot, int level) {

	//duyet cay theo tang

	if (level == 1) {
		return pRoot->key;
	}
	else {
		return LevelOrderTraversal(pRoot->p_left, level - 1) + LevelOrderTraversal(pRoot->p_right, level - 1);
	}
}

int countLeaf(NODE* pRoot) {

	//dem so luong node la 

	if (!pRoot) return 0;

	int count = 0;
	if (!(pRoot->p_left && pRoot->p_right)) {
		return 1;
	}
	if (pRoot->p_left) {
		count += countLeaf(pRoot->p_left);
	}

	if (pRoot->p_right) {

		count += countLeaf(pRoot->p_right);
	}
	return count;

}

int countLess(NODE* pRoot, int x) {

	// dem so luong node nho hon node co gia tri cho truoc x

	if (!pRoot) return 0;

	int count = 0;

	if (pRoot->key < x) {
		count++;
	}
	if (pRoot->p_left) {
		count += countLess(pRoot->p_left, x);
	}
	if (pRoot->p_right) {
		count += countLess(pRoot->p_right, x);
	}
	return count;
}

int countGreater(NODE* pRoot, int x) {

	// dem co luong co gia tri lon hon gia tri node cho truoc

	/*
	//c1

	if (!pRoot) return 0;

	int count = 0;

	if ( x < pRoot->key ) {
		count++;
	}
	if (pRoot->p_left) {
		count += countGreater(pRoot->p_left, x);
	}
	if (pRoot->p_right) {
		count += countGreater(pRoot->p_right, x);
	}
	return count;*/
	

	//c2
	if (!pRoot) {
		return 0;
	}
	int left = countGreater(pRoot->p_left, x);
	int right = countGreater(pRoot->p_right, x);

	return left + right + (pRoot->key >x ? 1 : 0);
}


bool isBST(NODE* pRoot) {

	// kiem tra cay co phai cay nhi phan khong

	if (pRoot == nullptr) {
		return true;
	}

	if (pRoot->p_left && pRoot->key < pRoot->p_left->key) {
		return false;
	}

	if (pRoot->p_right && pRoot->p_right->key < pRoot->key) {
		return false;
	}
	if (!isBST(pRoot->p_left) || !isBST(pRoot->p_right)) {
		return false;
	}
	return true;

}

bool isFull(NODE* pRoot) {

	//kiem tra phai cay day du hay khong

	//TH cay rong 
	if (!pRoot) {
		return true;
	}


	if (!pRoot->p_left && !pRoot->p_right) {

		return true;
	}

	if (pRoot->p_right && pRoot->p_left) {

		return isFullBST(pRoot->p_left) && isFullBST(pRoot->p_right);
	}
	return false;

}
bool isFullBST(NODE* pRoot) {

	//kiem tra cay nhi phan tim kiem day du

	return isFull(pRoot)&&isBST(pRoot);
}

bool printLevel(NODE* pRoot, int level) {

	// in theo tang

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

int NumberOfNode(NODE* pRoot, int x) {

	if (!pRoot) return 0;
	
	// dem so luong node co gia tri nho hon gia tri x

	else {
		NODE* cur = pRoot;
		while (cur->p_left && cur && cur->key != x) {

			if (cur->key < x) {
				cur = cur->p_right;
			}
			else cur = cur->p_left;
		}
		
		return countNode(cur->p_left);
	
	}
}