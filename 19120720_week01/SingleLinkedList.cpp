
#include"SinghleLinkedList.h"


void initList(List*& L) {

	/*
	Khoi tao danh sach lien ket don 
	
	*/
	L = new List();
	if (!L) {
		cout << "\nError Memory!";
		return;
	}
	L->pHead = nullptr;
	L->pTail = nullptr;
}

bool isEmty( const List * r_List) {

	/*kiem tra danh sach lien ket rong hay khong:
	+ Rong tra ve true
	+ Nguoc lai, tra ve false

	*/

	//C1
	if (r_List->pHead == nullptr) {
		return true;
	}
	return false;

	//C2
	/*
	return (r_List->pHead==nullptr);
	|| return !r_List->pHead;
	*/
}

List* createList(Node* pNode) {
	

	/*
	Tao Node moi trong danh sach lien ket 

	*/
	List* p = new List;
	if (!p) {
		return nullptr;
	}

	p->pHead = p->pTail = pNode;
	return p;
}

Node* createNode(int data) {
	/*
	Tao Node moi voi du lieu cho truoc data.

	*/

	Node* pNode = new (std:: nothrow) Node;
	if (!pNode) {
		return nullptr;
	}

	pNode->data = data;
	pNode->pNext = nullptr;
	return pNode;
}

bool addHead(List*& L, int data) {

	// them vao dau danh sach 

	Node* pNode = createNode(data);
	if (L->pHead == nullptr) {

		L = createList(pNode);
		return true;
	}
	else {

		pNode->pNext = L->pHead;
		L->pHead = pNode;
		return true;
	}

	return false;
}

bool addTail(List*& L, int data) {

	// them vao cuoi danh sach 

	Node* pNode = createNode(data);

	if (L->pHead == nullptr) {

		L = createList(pNode);
		return true;
	}
	else {

		L->pTail->pNext = pNode;
		L->pTail = pNode;
		return true;
	}
	return false;

}
void removeHead(List*& L) {
	//xoa Node dau tien danh sach 

	if (L->pHead == nullptr) {
		return;
	}
	else if (L->pHead == L->pTail) {

		delete L->pHead;
		L->pHead = L->pTail = nullptr;
	}
	else {

		Node* pNode = L->pHead->pNext;
		delete L->pHead;
		L->pHead = pNode;
	}
}

void removeTail(List*& L) {

	//Xoa Node o cuoi danh sach 
	if (L->pHead == nullptr) {
		return;
	}
	else if (L->pHead == L->pTail) {

		delete L->pHead;
		L->pHead = L->pTail = nullptr;
	}
	else {

		Node* pNode = L->pHead;
		for (; pNode->pNext != L->pTail; pNode = pNode->pNext);
		delete L->pTail;
		L->pTail = pNode;
		pNode->pNext = nullptr;
	}
}



void removeAll(List*& u_List) {

	// huy danh sach lien ket don 

	if (!isEmty(u_List)) {

		for (Node* cur = u_List->pHead; cur; ) {

			Node* temp = cur->pNext;
			delete cur;
			cur = temp;
		}
	}
} 

void printList(List* L) {

	// in danh sach lien ket don 

	Node* cur = L->pHead;
	while (cur) {

		cout << cur->data << " ";
		cur = cur->pNext;
	}

}

int countElements(List* L) {

	// dem so luong phan tu trong danh sach lien ket don 

	int count = 0;
	Node* cur = L->pHead;
	while (cur ) {
		count++;
		cur = cur->pNext;
	}
	return count;
}

List* reverseList(List* L) {
	/*
	+ Dao nguoc danh sach lien ket 
	+ Tra ve 1 danh sach lien ket moi nguoc chieu so voi danh sach ban dau 

	*/
	List *newList;
	initList(newList);

	while (L->pHead) {
		addHead(newList, L->pHead->data);
		L->pHead = L->pHead->pNext;
	}

	return newList; 
	
}

void removeDuplicate(List*& L) { 

	/*
	Xoa phan tu trung nhau trong danh sach lien ket 
	*/

	if (!isEmty(L)) { // kiem tra danh sach rong hay khong 

		Node* cur = L->pHead;
		Node* red = nullptr;
		Node* req = nullptr;
			while (cur && cur->pNext) {
			   req = cur;
				
				while( req->pNext)  {
				
					if (req->pNext->data == cur->data) {
						/*
						Truong hop req->pNext la phan tu cuoi cung nen can cap nhat lai Tail.

						*/
						if (req->pNext == L->pTail) { 

							red = req->pNext;
							L->pTail = req;

							delete red;
							req->pNext = nullptr;
							red = nullptr;
						}
						else {

							red = req->pNext;
							req->pNext = red->pNext;
							delete red;
							red = nullptr;
						}
					}
					else req = req->pNext;
				}

				cur = cur->pNext;
			}
		
	}
}
bool removeElement(List*& L, int key) {
	/*
	Xoa phan tu co gia tri bang key trong danh sach lien ket:

	+ Neu co & xoa duoc tra ve true
	+ Neu khong co hoac khong xoa dc tra ve false

	*/

	int flag = 0;
	if (!isEmty(L)) {
		if (L->pHead == L->pTail && L->pHead->data == key) {
			delete L->pHead;
			L->pHead = L->pTail = nullptr;
			flag = 1;
		}
		else {

			Node* cur = L->pHead;
			while (cur && cur->pNext) {

				if (L->pHead->data == key) { //TH trung voi phan tu dau tien 
					Node* temp = L->pHead;
					L->pHead = L->pHead->pNext; // cap nhat lai pHead.
					cur = L->pHead;
					delete temp;
					temp = nullptr;
					flag = 1;
				}
				else if (cur->pNext->data == key) {

					if (cur->pNext == L->pTail) { //TH trung voi phan tu cuoi cung 
						delete L->pTail;
						L->pTail = cur; //cap nhat lai pTail
						cur->pNext = nullptr;
						flag = 1;
					}
					else {
						Node* temp = cur->pNext;
						cur->pNext = temp->pNext;
						delete temp;
						temp = nullptr;
						flag = 1;
					}
				}
				else cur = cur->pNext;
			}
		}
		if (flag == 1) return true;
		return false;
	}
	else return false;
	
}



/*

List* createList(Node * pNode){

 List*L = new List {pNode, pNode};

 return L;
}

Node* createNode(int data){

 Node*p=new Node{data,nullptr};
 return p;

}

void initList(List *&L){
L= new List();
L->pHead =nullptr;
L->pTail=nullptr;
}

Cai isEmty;
*/
