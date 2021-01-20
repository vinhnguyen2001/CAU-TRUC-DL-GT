#include"myLib.h"

int main() {

	//Cau 1
	int n = 10;
	SinhVien *arr= readStudents("DSSV.txt", n);
	SinhVien *x = heapSort(arr, n);
	fstream os ("D://BAI1.txt", ios::out);
	for (int i = 0; i < n; i++) {
		os <<  x[i].hoten << ": " << x[i].diem << endl;
	}
	cout << endl;
	/*for (int i = 0; i < n; i++) {
		std::cout << arr[i].mssv << " " << arr[i].hoten << " " << arr[i].diem << endl;
	}*/
	//Cau 2

	BSTNode* root = nullptr;
	root = createBST(arr, n);
	LRNODE(root);
	lowestScore(root, "example.txt");

	//Cau 3

	SinhVien *stu = createHashTable(arr, n-3);
	/*for (int i= 0; i < n - 3; i++) {
		cout << stu->hoten << ": "<< stu->diem << endl;
	}*/
	writtinginFile(stu,n-3,"D://CAU3.txt");

	SinhVien* sa = nullptr;
	sa = searchStu(arr, n - 3, "Phan Dinh Anh Quan");
	if (sa) {
		cout << "\nInformation of student:" << endl;
		cout << sa->mssv << "_" << sa->hoten << ": " << sa->diem;
	}
	else {
		cout << "\nThe name's student does not exits in the list!";
	}
	return 0;
}