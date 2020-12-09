#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

struct Examinee {
	string id{};
	float math{};
	float literature{};
	float physic{};
	float chemistry{};
	float biology{};
	float history{};
	float geography{};
	float civic_education{};
	float natural_science{};
	float social_science{};
	float foreign_language{};
	
};

ostream& operator<<(ostream& os, Examinee ex);

Examinee readExaminee(string line_info);

vector<Examinee> readExamineeList(string file_name);

void writeTotal(vector<Examinee> examinee_list, string out_file_name);

