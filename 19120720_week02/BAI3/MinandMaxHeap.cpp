#include"MinandMaxheap.h"

void buildMinHeap(int arr[], int n) {
	//tao min heap

	int start = (n / 2) - 1;
	for (int i = start; i >= 0; i--) {

		MinHeap(arr, n, i);
	}
}

void buildMaxHeap(int arr[], int n) {
	//tao max heap

	int start = (n / 2) - 1;
	for (int i = start; i >= 0; i--) {

		MaxHeap(arr, n, i);
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
	
}
void MinHeap(int a[], int n, int i) {
   // sap xep minheap
	int min = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[left] < a[min]) {
		min = left;
	}

	if (right < n && a[right] < a[min]) {
		min = right;
	}

	if (min != i) {
		swap(a[i], a[min]);

		MinHeap(a, n, min);
	}

}

void MaxHeap(int a[], int n, int i) {
	//sap xep maxheap

	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[left] > a[max]) {
		max = left;
	}

	if (right < n && a[right] > a[max]) {
		max = right;
	}

	if (max != i) {
		swap(a[i], a[max]);

		MaxHeap(a, n, max);
	}
}

void deleteMaxValue(int a[], int& n) {

	//xoa phan tu lon nhat cua maxheap
	buildMaxHeap(a, n);

	for (int i = 0; i < n-1; i++) {

		a[i] = a[i + 1];
	}
	n--;

}

void deleteMinValue(int a[], int& n) {

	//xoa phan tu nho nhat cua min heap

	buildMinHeap(a, n);

	for (int i = 0; i < n - 1; i++) {

		a[i] = a[i + 1];
	}
	n--;
	
	//buildMinHeap(a, n);
}
void printArrray(int a[], int n) {

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[] = { 3,92,25,32,65,45,89,11,14,38 };
	int n = 10;
	buildMinHeap(a, n);
	cout << "\nMANG SAU KHI TAO MINHEAP: ";
	printArrray(a, n);

	buildMaxHeap(a, n);
	cout << "\nMANG SAU KHI TAO MAXHEAP: ";
	printArrray(a, n);

	deleteMinValue(a, n);
	cout << "\nMANG SAU KHI XOA PHAN TU NHO NHAT: ";
	printArrray(a, n);

	deleteMaxValue(a, n);
	cout << "\nMANG SAU KHI XOA PHAN TU LON NHAT: ";
	printArrray(a, n);
	return 0;
}