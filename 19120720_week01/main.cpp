
#include"SinghleLinkedList.h"

int main() {
	List* L;
	initList(L);
	addTail(L, 14);
	addTail(L, 14);
	addTail(L, 15);
	addTail(L, 7);
	addTail(L, 12);
	addTail(L, 33);
	addTail(L, 12);

	printList(L);
	cout << "\n" << L->pHead->data;
	cout << " \nCOUNT : " << countElements(L);
	cout << "\nTAIL " << L->pTail->data;
	removeDuplicate(L);
	cout << endl;
	printList(L);
	cout << "\nTAIL " << L->pTail->data;
	cout << "\nHEAD TRUOC XOA " << L->pHead->data;
	removeElement(L, 14);
	cout << "\nHEAD SAU XOA "<< L->pHead->data;
	cout << endl;
	printList(L);
	cout << "\nHEAD " << L->pHead->data;
	removeHead(L);
	cout << endl;
	printList(L);
	cout << "\nTAIL " << L->pTail->data;
	removeTail(L);
	cout << endl;
	printList(L);
	List * newList = reverseList(L);
	cout << endl;
	printList(newList);
	
	removeAll(L);
	printList(L);
	
	return 0;
}