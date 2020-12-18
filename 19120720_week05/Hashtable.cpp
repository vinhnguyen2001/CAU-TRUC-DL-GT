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
		cout << "Read file data done";
		os.close();
	}
	else {
		cout << "\nError opening file! ";
	}
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
		if (2000 <= index) {
			index = index % 2000;
		}
		long long temp = index;

		while ( hashtable[index].name != "" ) {
		
			index = (index + 1) % 2000;
			//xu li truong hop bang bam bi day phan tu.
			if (index == temp ) {
				break;
			}
		}
		hashtable[index] = list_company[i];
	}
	return hashtable;
}

bool insert(Company* hash_table, Company company) {
	// chen them thong tin cua 1 cong ty vao 1 bang bam cu the

	long long index = hashString(company.name);
	//xu li truong hop index lon hon so phan tu cua bang bam
	if (2000 <= index) {
		index = index % 2000;
	}
	long long temp = index;
	while (hash_table[index].name != "") {
		//xu li truong hop bang bam bi day phan tu
		if (index == temp - 1) {
			return false;
		}
		index = (index + 1) % 2000;
		
	}
	hash_table[index] = company;
	return true;
}

Company* search(Company* hash_table, string company_name) {

	// tim kiem ten cua mot cong ty trong bang bam
	long long index = hashString(company_name);
	
	if (2000 <= index) {
		index = index % 2000;
	}
	long long temp = index;
	Company* result = nullptr;
	while (hash_table[index].name != "") {
		
		if (hash_table[index].name == company_name) {
			result = &hash_table[index];
			return result;
		}
		else {
			//xu truong hop cong ty can tim khong co trong bang bam
			if (index == temp - 1) {
				return result;
			}
			else index = (index + 1) % 2000;
		}
	}
}


int main() {
	Company* hash_table = nullptr;
	Company VNG;
	VNG.name = "CONG TY VNG CORPORATION(VietNam)";
	VNG.profit_tax = "11134723452";
	VNG.address="182 LE DAI HANH - P.15 - Q.11 - TP HO CHI MINH";
	vector<Company> result = readCompanyList("data.txt");
	hash_table = createHashTable(result);
	if (insert(hash_table, VNG)) {
		cout << "\nCONG TY " << VNG.name << " DA DUOC THEM VAO BANG BAM" << endl;
	}
	else {
		cout << "\nBANG BAM DA DAY PHAN TU!";
	}
	Company* company = nullptr;
	
	company = search(hash_table, VNG.name);
	if (company!=nullptr) {
		cout << "\nTHONG TIN CUA CONG TY CAN TIM: " << endl;
		cout << company->name << "|" << company->profit_tax << "|" << company->address << endl;
	}
	else {
		cout << "\nCONG TY KHONG TON TAI TRONG BANG BAM!" << endl;
	}
	/*int count = 0;
	cout << "\nDANH SACH CAC CONG TY: " << endl;
	for (int i = 0; i < 2000; i++) {
		if (hash_table[i].name != "") {
			count++;
			cout<<i<<" " << hash_table[i].name << "|" << hash_table[i].profit_tax << "|" <<hash_table[i].address<< endl;
		}
	}*/
	if (hash_table) {
		delete hash_table;
		hash_table = nullptr;
	}
	return 0;
}