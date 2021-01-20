#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;


struct SinhVien
{
	string mssv;
	string hoten;
	float diem  = 0;
};

struct BSTNode
{
	SinhVien data;
	BSTNode* left =nullptr;
	BSTNode* right = nullptr;
};

SinhVien readLine(string line_info);

SinhVien* readStudents(string filename, int& n);

SinhVien* heapSort(SinhVien*stu, int n);

void heapify(SinhVien*&a, int n ,int i);

BSTNode* createBST(SinhVien* dssv, int n);

BSTNode* createNode(SinhVien x);

void LRNODE(BSTNode* root);

BSTNode* insertElement(BSTNode*& root, SinhVien x);

void lowestScore(BSTNode* root, string fileName);

SinhVien* createHashTable(SinhVien* dssv, int n);

void writtinginFile(SinhVien* hashtable, int n, string filename);

long long hashString(string company);

SinhVien* searchStu(SinhVien* hashtable, int m, string hoten);