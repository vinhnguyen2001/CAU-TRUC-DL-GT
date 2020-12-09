#include"Pointer.h"

void inputArray(int*& a, int& n) {

	//tao mang cap phat dong
	cout << "\nNhap so phan tu cua mang: ";
	cin >> n;

	a = new(std::nothrow) int[n];

	cout << "\nNhap lan luot cac phan tu cua mang " << endl;
	if (!a) {
		cout << "\ncap phat khong thanh cong!";
		return;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void dellocateArray(int*& a) {

	//huy cap phat dong
	if (a != nullptr) {

		delete[]a;
		a = nullptr;
	}
}

void printArray(int* a, int n) {

	//in mang
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int findMin(int* a, int n) {
	
	//tim gia tri nho nhat
	int min = a[0];
	for (int i = 1; i < n; i++) {

		if (min > a[i]) {
			min = a[i];
		}
	}
	return min;
}

int findMaxModulus(int* a, int n) {

	//tim gia tri co tri tuyet doi lon nhat
	int max = a[0];

	for (int i = 1; i < n; i++) {

		if (max < abs(a[i])) {
			max = a[i];
		}

	}
	return max;
}

bool isAscending(int* a, int n) {

	//kiem tra mang co duoc sap xep tang dan hay khong
	for (int i = 0; i < n-1; i++) {

		for (int j = i + 1; j < n; j++) {

			if (a[j] < a[i]) {
				return false;
			}
		}
	}
	return true;
}

int sumOfArray(int* a, int n) {

	//tinh tong cua mang

	int total = 0;

	for (int i = 0; i < n; i++) {

		total += a[i];
	}

	return total;

}

int countPrime(int* a, int n) {
	
	//dem so luong so nguyen to co trong mang 

	int count = 0;
	for (int i = 0; i < n; i++) {

		if (isPrime(a[i],2)) {
			count++;
		}
	}
	return count;
}

void ReverseArray(int*& a, int n) {

	//dao mang
	int b = n / 2 ;
	for (int i = 0; i < b ; i++) {

		swap(a[i], a[n - 1 - i]);
   }

}

int linearSearch(int* a, int n, int key) {

	//duyet tuan tu
	for (int i = 0; i < n; i++) {

		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}

int sentinelLinearSearch(int* a, int n, int key) {

	//duyet tuan tu phuong phap linh canh
	int flag = -1;

	for (int i = 0; i < n; i++) {

		if (a[i] == key) {
			flag = i;
			break;
		}
	}

	return flag;
}

int binarySearch(int* a, int n, int key) {

	//tim kiem nhi phan 
	
	int k = n / 2 - 1;
	int flag = k;
	if (a[k] == key) return k;

	while (0 <= k && k < n && a[k] != key) {

		if (key < a[k]) {
			k--;
		}
		else if (key > a[k]) {
			k++;
		}
	}
	
	if (flag == k)return -1;
	else return k;

}

int recursiveBinarySearch(int* a, int left, int right, int key){

	//de quy nhi phan tim kiem
	if (a[left] == key) {

		return left;
	}
	else if (a[right] == key) {
		return right;
	}
	
	if (a[left] < key) {
		return recursiveBinarySearch(a, left, right + 1, key);
	}
	else return recursiveBinarySearch(a, left - 1, right, key);

}

bool isPrime(int n, int i = 2) {

	//kiem tra so nguyen to
	if (n < 0 || (n % i == 0 && n!= 1 && n!=2)){
		return false;
	}

	if (i *i>n || n == 1||n==2) {
		return true;
	}
	
	else return isPrime(n, i + 1);
}

void Ascending(int*& a, int  n) {
	/// sap xep  mang tang dan

	for (int i = 0; i < n - 1; i++) {

		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}

}
int main() {


	//int a[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	int n = 11;
	int*  a=nullptr;
	inputArray(a, n);
	cout << "\nCac phan tu cua mang: ";
	printArray(a, 11);

	int key = 9;
	int left = n / 2 - 1;
	int right = left + 1;
	cout << "\nGia tri nho nhat trong mang la: " << findMin(a, n) << endl;
	cout << "\nGia tri co tri tuyet doi lon nhat trong mang la: " << findMaxModulus(a, n) << endl;
	if (!isAscending(a, n)) {
		cout << "\nMang chua duoc sap xep tang dan" << endl;
	}
	else cout << "\nMang da duoc sap xep " << endl;
	cout << "\nTong gia tri cua cac so trong mang la: " << sumOfArray(a, n) << endl;
	cout << "\nSo luong so nguyen to co trong mang la: " << countPrime(a, n) << endl;
	cout << "\nMang sau khi dao: ";
	ReverseArray(a, 11);
	printArray(a, n);

	cout << "\nVi tri can tim cua gia tri " << key << ": " << linearSearch(a, n, key) << endl;
	cout << "\nVi tri can tim cua gia tri " << key << ": " << sentinelLinearSearch(a, n, key) << endl;
	if (!isAscending(a, n)) {
		Ascending(a, n);
	}

	cout << "\nCac phan tu cua mang: ";
	printArray(a, 11);
	cout << "\nVi tri can tim cua gia tri " << key << ": " << binarySearch(a, n, key) << endl;
	cout << "\nVi tri can tim cua gia tri " << key << ": " << recursiveBinarySearch(a,left,right, key) << endl;
	dellocateArray(a);
	return 0;
}