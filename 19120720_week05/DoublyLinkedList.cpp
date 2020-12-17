#include"DoublyLinkedList.h"


bool isEmty(d_List* r_list) {
  // kiem tra danh sach rong.Neu dung tra ve true
	if (r_list->pHead == nullptr) {
		return true;
	}
	return false;
}

d_List* createList( int value) {
	//Khoi tao mot danh sach voi gia tri value

	d_List*p = new (std::nothrow)d_List;

	if (!p) {
		return nullptr;
	}

	d_NODE* newNode = createNode(value);

	p->pHead = p->pTail = newNode;

	return p;
}

d_NODE* createNode(int value) {

	//khoi tao node moi voi gia tri cho truoc la value

	d_NODE* newNode = new(std::nothrow) d_NODE;

	if (!newNode) {
		cout << "\nLoi cap phat!";
		return nullptr;
	}

	newNode->key = value;
	newNode->pNext = nullptr;
	newNode->pPrev = nullptr;
	
	return newNode;
}

void addHead(d_List*& u_list, int value) {
	
	// them vao dau danh sach gia tri value

	if (isEmty(u_list)) {
		u_list = createList(value);
	}
	else {
		d_NODE* newNode = createNode(value);

		u_list->pHead->pPrev = newNode;

		newNode->pNext = u_list->pHead;
		u_list->pHead = newNode;
	}
}

void addTail(d_List*& u_list, int value) {

	// them vao cuoi danh sach gia tri value

	if (isEmty(u_list)) {
		u_list = createList(value);
	}
	else {
		d_NODE* newNode = createNode(value);

		u_list->pTail->pNext = newNode;
		newNode->pPrev = u_list->pTail;
		u_list->pTail = newNode;
	}
}

void insertBefore(d_List*& u_list, d_NODE* pre_Node, int value) {

	// chen gia tri value vao truoc 1 node da cho 
	if (!pre_Node) {
		cout << "\nNode da cho khong ton tai! ";
		return;
	}

	d_NODE* newNode = createNode(value);

	newNode->pPrev = pre_Node->pPrev;

	pre_Node->pPrev = newNode;

	newNode->pNext = pre_Node;
	if (newNode->pPrev) {
		newNode->pPrev->pNext = newNode;
	}
	else{
		u_list->pHead = newNode;
	}
}

void insertAfter(d_List*& u_list, d_NODE* pre_Node, int value) {

	//chen gia tri value vao sau 1 node da cho

	if (!pre_Node) {
		cout << "\nNode da cho khong ton tai! ";
		return;
	}
	d_NODE* newNode = createNode(value);

	newNode->pNext = pre_Node->pNext;
	newNode->pPrev = pre_Node;
	pre_Node->pNext = newNode;

	if (newNode->pNext) {
		newNode->pNext->pPrev= newNode;
	}
	else {
		u_list->pTail = newNode;
	}
}


void deleteHead(d_List*& u_list) {

	//xoa node dau danh sach 
	if (isEmty(u_list)) {
		return;
	}
	d_NODE* current = u_list->pHead;

	u_list->pHead = u_list->pHead->pNext;
	u_list->pHead->pPrev = nullptr;

	delete current;
	current = nullptr;
}

void deleteTail(d_List*& u_list) {

	// xoa node cuoi danh sach
	if (isEmty(u_list)) {
		return;
	}
	d_NODE* current = u_list->pTail;

	u_list->pTail = u_list->pTail->pPrev;
	u_list->pTail->pNext = nullptr;
	
	delete current;
	current = nullptr;
}


void printList(d_List* r_list) {

	cout << "\nHEAD-->TAIL: ";
	d_NODE* current = r_list->pHead;
	while (current)
	{
		cout << current->key << " ";
		current = current->pNext;
	}

	cout << "\nTAIL-->HEAD: ";
	current = r_list->pTail;
	while (current)
	{
		cout << current->key << " ";
		current = current->pPrev;
	}
	cout << endl;
}

int main() {

	d_List* list = nullptr;
	list = createList(4);
	int a[] = { 5,7,9,10,13,17,21};

	for (int i = 0; i < 7; i++) {
		addTail(list, a[i]);
	}

	printList(list);

	deleteTail(list);
	printList(list);

	deleteHead(list);
	printList(list);
	return 0;

}