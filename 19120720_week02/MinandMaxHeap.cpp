#include"MinandMaxheap.h"

void buildMinHeap(int arr[], int n) {

	int start = (n / 2) - 1;
	for (int i = start; i >= 0; i--) {

		MinHeap(arr, n, i);
	}
}

void buildMaxHeap(int arr[], int n) {
	
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
int main() {
	int a[] = { 3,92,25,32,65,45,89,11,14,38 };
	int n = 10;
	buildMinHeap(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	buildMaxHeap(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}