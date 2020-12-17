#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

struct Company
{
	string name;
	string profit_tax;
	string address;
};

vector<Company> readCompanyList(string file_name);

ostream& operator<<(ostream& os, Company ex);

Company readCompany(string line_info);

long long hashString(string company_name);

Company* createHashTable(vector<Company> list_company);

void insert(Company* hash_table, Company company);

Company* search(Company* hash_table, string company_name);