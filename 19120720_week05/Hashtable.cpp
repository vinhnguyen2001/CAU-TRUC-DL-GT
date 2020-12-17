#include"HashTable.h"

Company readCompany(string line_info) {
	//ham doc 1 hang
	Company com;
	vector<string> arr;
	string buffer;
	stringstream ss(line_info);
	while (getline(ss, buffer, '|')) {
		if (buffer == "") {
			buffer = '0';
		}
		arr.push_back(buffer);
	}
	com.name = arr[0];
	com.profit_tax = arr[1];
	com.address = arr[2];
	return com;

}
vector<Company> readCompanyList(string file_name) {

	// doc danh sach
	fstream os;
	os.open(file_name, fstream::in);

	string line_info;
	
	vector<Company> result;

	if (os.is_open()) {

		//khong doc dong dau tien cua du lieu data
		os.ignore(numeric_limits<streamsize>::max(), '\n');

		int index = 0;
		while (getline(os, line_info, '\n')&&!os.eof()) {
			result.push_back(readCompany(line_info));
		}
	}
	else {
		cout << "\nError opening file! ";
	}
	cout << "Read file data done";
	os.close();

	return result;
}

ostream& operator<<(ostream& os, Company ex) {
	os << ex.name << "|" << ex.profit_tax << "|" << ex.address << endl;
	return os;
}

long long hashString(string company_name) {

	// tim vi tri thich hop trong hashtable
	int index = 0;
	string temporary = company_name;
	unsigned long long sum = 0;
	int p = 31;
	long long m =(long long) pow(10, 9) + 9;

	while (20 < temporary.size()) {
		//xoa phan tu cua chuoi neu chuoi co so phan tu do lon 20
		temporary.erase(temporary.begin());
	}

	for (int i = 0; i <int(temporary.size()); i++) {
	
		sum += ((long long)temporary[i] *(long long) pow(p, i));
	}

	return sum % m;
}

Company* createHashTable(vector<Company> list_company) {

	// tao 1 bang bam voi list_company
	Company* hashtable = new (std::nothrow) Company[2000];
	if (!hashtable) {
		cout << "\nHeap overflow";
		return nullptr;
	}
	long long index = 0;
	
	for (int i = 0; i < int(list_company.size()); i++) {

		index = hashString(list_company[i].name);
		//xu li truong hop index roi ra ngoai mang (2000-phan tu)
		while (2000 <= index || (index < 2000 && hashtable[index].name != "")) {
			index = (index + 1) % 2000;
		}
	
		hashtable[index] = list_company[i];
	}

	return hashtable;
}

void insert(Company* hash_table, Company company) {
	// chen them thong tin cua 1 cong ty vao 1 bang bam cu the

	long long index = hashString(company.name);

	while (2000 <= index || (index < 2000 && hash_table[index].name != "")) {
		index = (index + 1) % 2000;
	}
	hash_table[index] = company;

}

Company* search(Company* hash_table, string company_name) {

	// tim kiem ten cua mot cong ty trong bang bam
	long long index = hashString(company_name);
	Company* result = nullptr;
	for (int i = 0; i < 2000; i++) {

		if((hash_table[i].name != "") && (hash_table[i].name == company_name)) { 
			result = &hash_table[i];
			break;
		}
	}
	return result;
}


int main() {
	Company* hash_table = nullptr;
	Company VNG;
	VNG.name = "CONG TY VNG CORPORATION(VietNam)";
	VNG.profit_tax = "11134723452";
	VNG.address="182 LE DAI HANH - P.15 - Q.11 - TP HO CHI MINH";
	vector<Company> result = readCompanyList("data.txt");
	
	hash_table = createHashTable(result);
	insert(hash_table, VNG);
	Company* a =search(hash_table, VNG.name);
	cout << "\nTEN CONG TY CAN TIM: " << a->name << endl;
	int count = 0;
	for (int i = 0; i < 2000; i++) {
		if (hash_table[i].name != "") {
			count++;
			cout<<i << hash_table[i].name << endl;
		}
	}
	return 0;
}