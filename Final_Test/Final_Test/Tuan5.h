#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

struct Company;

Company readCompany(string line_info);
vector<Company> readCompanyList(string file_name);
long long hashString(string company_name);
Company* createHashTable(vector<Company> list_company);
void insert(Company* hash_table, Company company);
Company* search(Company* hash_table, string company_name);