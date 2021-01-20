#include"Tuan5.h"

using namespace std;

struct Company {
	string name = "";
	string profit_tax = "";
	string address = "";
};

Company readCompany(string line_info) {
	string buffer = "";
	Company temp;
	stringstream a(line_info);
	getline(a, buffer, '|');
	temp.name = buffer;
	getline(a, buffer, '|');
	temp.profit_tax = buffer;
	getline(a, buffer, '|');
	temp.address = buffer;
	return temp;
}
vector<Company> readCompanyList(string file_name) {
	vector<Company> company_list;
	ifstream f(file_name, ios::in);
	if (!f) {
		cout << "* Khong mo duoc file dau vao. Chuong trinh ket thuc." << endl;
		exit(0);
		return company_list;
	}
	string line_info;
	getline(f, line_info);
	while (!f.eof()) {
		getline(f, line_info);
		Company temp = readCompany(line_info);
		company_list.push_back(temp);
	}
	f.close();
	return company_list;
}
long long hashString(string company_name) {
	int n = company_name.length();
	int pos = 0;
	if (n > 20) pos = n - 20;
	unsigned long long temp = 0;
	for (int i = pos; i < n; i++) {
		unsigned long long s = unsigned long long(company_name[i]);
		int mu = i - pos;
		temp += s * (unsigned long long(pow(31, mu)));
	}
	unsigned long long m = unsigned long long(pow(10, 9) + 9);
	return temp % m;
}
Company* createHashTable(vector<Company> list_company) {
	Company* hash_table = new(nothrow)Company[2000];
	if (!hash_table) {
		cout << "* Khong du bo nho. Chuong trinh ket thuc." << endl;
		exit(0);
		return nullptr;
	}
	int n = list_company.size();
	//,cho rang file dau vao tao 1 bang bam khong co cong ty trung ten
	for (int i = 0; i < n; i++) {
		unsigned long long index = hashString(list_company[i].name) % 2000;
		long long pos = index;
		while (hash_table[index].name != "") {
			index = (index + 1) % 2000;
			if (index == pos) break;
		}
		hash_table[index] = list_company[i];
	}
	return hash_table;
}
void insert(Company* hash_table, Company company) {
	if (!hash_table) {
		cout << "* Bang khong ton tai. Vui long nhap ten file va tao bang." << endl;
		return;
	}
	unsigned long long index = hashString(company.name) % 2000;
	long long pos = index;
	bool checkdup = false;
	bool checkfull = false;
	while (hash_table[index].name != "") {
		if (hash_table[index].name == company.name) {
			checkdup = true;
			break;
		}
		index = (index + 1) % 2000;
		if (index == pos) {
			checkfull = true;
			break;
		}
	}
	if (checkdup) {
		cout << "* Ten cong ty da ton tai trong bang, khong the them." << endl;
		return;
	}
	if (checkfull) {
		cout << "* Bang bam da day. Khong the them cong ty." << endl;
		return;
	}
	hash_table[index] = company;
	cout << "-> Da them cong ty tren vao bang bam." << endl;
}
Company* search(Company* hash_table, string company_name) {
	if (!hash_table) {
		cout << "* Bang khong ton tai, khong the tim kiem." << endl;
		return nullptr;
	}
	Company* temp = nullptr;
	long long index = hashString(company_name) % 2000;
	if (hash_table[index].name == company_name) return &hash_table[index];
	for (int i = (index + 1) % 2000; i < 2000; i = (i + 1) % 2000) {
		if (hash_table[index].name == company_name) {
			temp = &hash_table[index];
			break;
		}
		if (i == index) break;;
	}
	return temp;
}

int main() {
	int lenh1 = 0, lenh2 = 0;
	bool exit = false;
	string fname;	
	Company* table = nullptr;
	do {
		if (lenh2 == 0) {
			cout << "- Nhap ten file dau vao: ";
			getline(cin, fname);
			vector<Company> list = readCompanyList(fname);
			table = createHashTable(list);
			//2 ham tren da bao gom viec kiem tra khong mo duoc file vaf khong tao duoc bang
			cout << endl << "-> Da doc duoc file va tao bang bam." << endl;
			cout << "------------------------------------------------------" << endl;
		}
		cout << "		Menu bai thuc hanh" << endl << endl;
		cout << "1. Nhap file dau vao va tao bang bam (xoa bang bam truoc neu co);" << endl
			 << "2. Xuat bang bam hien tai;" << endl
			 << "3. Them cong ty vao bang bam;" << endl
			 << "4. Tim cong ty trong bang bam;" << endl
			 << "5. Thoat." << endl
			 << "---------------------------------------------------------------" << endl;
		do {
			cout << "   Nhap lenh: ";
			cin >> lenh1;
			if ((lenh1 < 1) || (lenh1 > 5)) cout << "   * Vui long nhap lai lenh hop le." << endl;
		} while ((lenh1 < 1) || (lenh1 > 5));
		if ((lenh1 >= 1) && (lenh1 <= 4)) system("cls");
		switch (lenh1) {
		case 1: {
			cout << "1. Nhap file dau vao va tao bang bam (xoa bang bam truoc neu co):" << endl << endl;
			if (table) delete[] table;
			cin.ignore();
			cout << "- Nhap ten file dau vao: ";
			getline(cin, fname);
			vector<Company> list = readCompanyList(fname);
			table = createHashTable(list);
			cout << endl << "-> Da doc duoc file va tao bang bam." << endl;
			break;
		}
		case 2: {
			cout << "2. Xuat bang bam hien tai:" << endl << endl;
			if (!table) {
				cout << "<Rong>" << endl;
				break;
			}
			for (int i = 0; i < 2000; i++) {
				if (table[i].name == "") cout << "<Chua co phan tu>";
				else cout << table[i].name << "|" << table[i].profit_tax << "|" << table[i].address;
				cout << endl;
			}
			break;
		}
		case 3: {
			cout << "3. Them cong ty vao bang bam:" << endl << endl;
			cin.ignore();
			Company cinsert;
			cout << "- Nhap thong tin cong ty can them:" << endl;
			cout << " + Ten: ";
			getline(cin, cinsert.name);
			cout << " + Ma so thue: ";
			getline(cin, cinsert.profit_tax);
			cout << " + Dia chi: ";
			getline(cin, cinsert.address);
			cout << endl;
			insert(table, cinsert);
			break;
		}
		case 4: {
			cout << "4. Tim cong ty trong bang bam:" << endl << endl;
			string cname;
			cin.ignore();
			cout << "- Nhap ten cong ty can tim: ";
			getline(cin, cname);
			Company* result = search(table, cname);
			cout << endl;
			if (result) cout << "-> Cong ty tim duoc la: " << endl << result->name << "|" << result->profit_tax << "|" << result->address << endl;
			else cout << "-> Khong tim thay cong ty tren." << endl;
			break;
		}
		case 5: {
			exit = true;
			if (table) delete[] table;
			break;
		}
		}
		if ((lenh1 >= 1) && (lenh1 <= 4)) {
			cout << "--------------------------------------------------" << endl;
			cout << "   Chon hanh dong tiep theo:" << endl << endl;
			cout << "1. Quay lai menu chinh;" << endl;
			cout << "2. Thoat." << endl;
			cout << "--------------------------------------------------" << endl;
			do {
				cout << "   Nhap lenh: ";
				cin >> lenh2;
				if ((lenh2 < 1) || (lenh2 > 2)) cout << "   * Vui long nhap lai lenh hop le." << endl;
			} while ((lenh2 < 1) || (lenh2 > 2));
			if (lenh2 == 1) system("cls");
			else if (lenh2 == 2) {
				exit = true;
				if (table) delete[] table;
			}
		}
	} while (!exit);
	if (exit) cout << endl << endl << " * Chuong trinh ket thuc *";
	return 0;
}
