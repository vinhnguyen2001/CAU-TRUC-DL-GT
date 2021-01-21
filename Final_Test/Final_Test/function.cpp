#include"myLib.h"

SinhVien readLine(string line_info) {

	// ham doc tung dong cua du lieu vao 
	SinhVien s;
	vector<string> arr;
	stringstream ss(line_info);
	string buffer;
	
	int i = 0;

	while (getline(ss, buffer, '	')) {
		// them buffer vao mang
		if (buffer != " ") {
			arr.push_back(buffer);
			
		}

	}
	if (arr.size() == 3) {
		buffer = '0';
		arr.push_back(buffer);
	}
	s.mssv = arr[0];
	s.hoten = arr[1] +" "+ arr[2];
	s.diem = stof(arr[3]);
	return s;
}


SinhVien* readStudents(string filename, int& n) {

	fstream is(filename, fstream::in);
	string line;
	getline(is, line,':');
	getline(is, line, '\n');
    n =(int) (stof(line));
	getline(is, line);
	SinhVien* arr = new(std::nothrow) SinhVien[n];
	if (!arr) {
		std::cout << "\nHeap Overflow !";
		return nullptr;
	}
	int i = 0;
	
	if (is.is_open()) {
		while (i < n) {
			getline(is, line);
			
			SinhVien ex = readLine(line);
			arr[i].mssv = ex.mssv;
			arr[i].hoten = ex.hoten;
			arr[i].diem = ex.diem;
		//	std::cout << arr[i].mssv << " " << arr[i].hoten << " " << arr[i].diem << endl;
			i++;
		}
	}
	else {
		std::cout << "\nError opening file !";
	}
	return arr;
}

SinhVien* heapSort(SinhVien* stu, int n) {
	SinhVien*  array = new (std::nothrow) SinhVien[n];
	if (!array) {
		cout << "\nHeap Overflow !";
		return nullptr;
	}
	for (int i= 0; i < n; i++) {
		array[i] = stu[i];
	}

	for (int i = n / 2 - 1; i >= 0; i--){
		heapify(array, n, i);
	}
	for (int i = n - 1; i > 0; i--) {

		swap(array[0], array[i]);

		heapify(array, i, 0);
	}
	return array;
}


void heapify(SinhVien*& a, int n, int i) {

	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[largest].diem < a[left].diem) {
		largest = left;
	}

	if (right < n && a[largest].diem < a[right].diem) {
		largest = right;
	}
	if (largest != i) {
		swap(a[largest], a[i]);
		heapify(a, n, largest);
	}
}

BSTNode* createNode(SinhVien x) {
	BSTNode* temp = nullptr;
		temp = new (std::nothrow) BSTNode;

	if (temp) {
		temp->data= x;
		temp->left = nullptr;
		temp->right = nullptr;
	}
	return temp;
}
BSTNode* createBST(SinhVien* dssv, int n) {
	/*
	Tao cay nhi phan tim kiem.
	*/
	BSTNode* root = nullptr;
	for (int i = 0; i < n; i++) {
		insertElement(root, dssv[i]);
	}
	return root;
}

void LRNODE(BSTNode* root) {

	if (root == nullptr) {
		return;
	}
	if (root->left) {
		LRNODE(root->left);
	}
	cout << root->data.hoten << ": " << root->data.diem << endl;
	if (root->right) {
		LRNODE(root->right);
	}
	
}

BSTNode* insertElement(BSTNode*& root, SinhVien x) {

	if (root == nullptr) {
		root = createNode(x);
		return root;
	}
	else {
		if (root->data.diem < x.diem) {
			insertElement(root->right, x);
		}
		else if (root->data.diem > x.diem) {
			insertElement(root->left, x);
		}
		return root;
	}
}

void lowestScore(BSTNode* root, string fileName) {
	BSTNode* min = nullptr;
	if (root->left) {
		lowestScore(root->left,fileName);
	}
	else {
		min = root;
		fstream os(fileName, fstream::out);
		if (!os) {
			cout << "\nError opening file!" << endl;
			return;
		}
		os << min->data.mssv << " " << min->data.hoten << ": " << min->data.diem;
	}
}

long long hashString(string name) {
	int index = 0;
	string temporary = name;
	unsigned long long number = 0;

	while (20 < temporary.size()) {

		temporary.erase(temporary.begin()+20);
	}

	for (int i = 0; i <(int) temporary.length(); i++) {
		//cout << i << endl;
		number += ((unsigned long long)(temporary[i])-48);
	}

	return number;
}

SinhVien* createHashTable(SinhVien* dssv, int n) {
	
	// cap phat mang dong hashtable & thuc hien kiem tra no duoc cap phat thanh cong chua
	SinhVien* hashtable = new (std::nothrow) SinhVien[n];

	if (!hashtable) {
		cout << "\nHeap Overflow!";
		return nullptr;
	}
	// tao bien index de luu vi tri cua phan tu trong bang bam
	unsigned long long index = 0;
	int flag = false;
	//cout << "\n n: " << n;
	for (int i = 0; i < n; i++) {
	
	    //cout << dssv[i].hoten << endl;
		index = hashString(dssv[i].hoten);
		//cout << "\nindex: " << index<<"\t"<<i;
		if (n <= index) {
			index = index % n;
		}
		//tao bien temp su dung de thoat vong lap trong trong hop cua bang bam bi day.
		unsigned long long temp = index;
		flag = false;
		while (hashtable[index].hoten != "") {
			index = (index + 1) % n;
			// giai quyet truong hop bang bam bi day phan tu.
			if (index == temp) {
				flag = true;
				break;
			}
		}
    //cout << "\nindex: " << index << "\t" << i;
		if (!flag) {
			hashtable[index] = dssv[i];
		}
	}
	return hashtable;
}

void writtinginFile(SinhVien* hashtable, int n, string filename) {

	// tao mot file voi ten la "filename" va kiem tra chung da duoc cap phat thanh cong chua 
	fstream os(filename, fstream::out);
	if (!os) {
		cout << "\nError opening file!";
		return;
	}
	// tien hanh ghi vao file
	int j = 0;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		os << i << " ";
		while (j<n) {
			j = i;
			if (hashtable[j].hoten != "") {
				os << hashtable[j].hoten << ": " << hashtable[j].diem << endl;
				break;
			}
			else {
				j++;
			}
		}
	}

}

SinhVien* searchStu(SinhVien* hashtable,int m , string hoten) {

	if (!hashtable) {
		cout << "\nHashtable does not exist!";
		return nullptr;
	}

	long long index = hashString(hoten);

	if (m <= index) {
		index = index % m;
	}
	long long temp = index;

	SinhVien* result = nullptr;

	while (hashtable[index].hoten != "") {

		if (hashtable[index].hoten == hoten) {

			result = &hashtable[index];
			break;
		}
		else {

			if (temp - 1 == index) {
				//khong ton tai gia tri cua hoten trong bang bam
				break;
			}
			else {
				index = (index + 1) % m;
			}
		}
	}
	return result;
}