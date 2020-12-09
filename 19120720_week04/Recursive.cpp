#include"Recursive.h"

int sumOfSquares(int n) {

	//S = 1^2 + 2^2 + ... + n^2
	if (n == 1) return 1;
	return n * n + sumOfSquares(n - 1);
}

int gcd(int a, int b) {

	//uoc chung lon nhat 

	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a == b) {
		return a;
	}

	if (a < b) {
		return gcd(a, b - a);
	}
	else gcd(a - b, b);

}

int i = 0;
bool isPalindrome(int a[], int n) {

	//kiem tra mang doi xung hay khong
    if(i>n/2)
	{
		return true;
	}
	if (a[i] != a[n - 1 -i]) {
		return false;
	}
	i++;
	isPalindrome(a, n);

}

int Factorial(int n) {

	//tinh n du thua
	if (n == 0) return 0;

	if (n == 1) return 1;

	if (n == 2) {
		return 2;
	}
	return n * Factorial(n - 1);

}

int countDigit(int a) {
	
	//dem chu so
	if (a > 0) {

		return 1 + countDigit(a/10);
	}
	else return 0;
}

int FIB(int n) {

  // so fibonacci thu n
	if (n <= 0) return 0;
	if (n == 1||n==2) {
		return 1;
	}

	return FIB(n - 1) + FIB(n - 2);

}

int main() {

	int a[] = { 1,2,3,4,5,5,4,3,3,1 };


	if (isPalindrome(a, 10)) {
		cout << "\nMang doi xung " << endl;
	}
	else cout << "\nMang khong doi xung " << endl;
	int n = 7;

	cout << "\nTong binh phuong  cac so tu nhien nho hon hoac bang "<<n<<": " << sumOfSquares(n);
	cout <<"\n"<<n<<"! = "<< Factorial(4) << endl;

	int b = 21476589;
	cout << "so chu so cua "<<b<<": " << countDigit(b);
	
	cout << "\nSo Fibonacci thu " << n << " " << FIB(n) << endl;

	int e = 40;
	int f = 64;
	cout << "\nUoc chung lon nhat " << e << " & " << f << ": " << gcd(e, f) << endl;
	return 0;
}