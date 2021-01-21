#include"myLib.h"

int main() {

	//Cau 1
	cout << "\n========= Cau 1 =========" << endl;
	int n = 10;
	SinhVien *arr= readStudents("DSSV.txt", n);
	if (arr) {
		cout << "\nSuccessfully read the file!";
		SinhVien* x = heapSort(arr, n);
		fstream os("D://cau1.txt", ios::out);
		for (int i = 0; i < n; i++) {
			os << x[i].hoten << ": " << x[i].diem << endl;
		}
		cout << endl;
	}
	else {
		cout << "\nFailed to read file";
	}
	

	//Cau 2
	cout << "\n========= Cau 2 =========" << endl;
	BSTNode* root = nullptr;
	root = createBST(arr, n);
	if (root) {
		cout << endl;
		LRNODE(root);
		lowestScore(root, "D://cau2.txt");
	}
	else {
		cout << "\nfailed to create a binary tree" << endl;
	}

	//Cau 3
	cout << "\n========= Cau 3 =========" << endl;

	SinhVien *stu = createHashTable(arr, n-3);

	writtinginFile(stu,n-3,"D://cau3.txt");

	SinhVien* sa = nullptr;
	sa = searchStu(arr, n - 3, "Phan Dinh Anh Quan");
	if (sa) {
		cout << "\nThe nam's student: "<<sa->hoten;
		cout << "\nInformation of student" << endl;
		cout << "MSSV: " << sa->mssv << "\nScore: " << sa->diem << endl;
	}
	else {
		cout << "\nThe name's student does not exits in the list!";
	}
	return 0;
}