#include"BTfile.h"


ostream& operator<<(ostream& os, Examinee ex) {
	os << ex.id << " " << ex.math << " " << ex.literature << " " << ex.physic << " " << ex.chemistry << " " << ex.biology << " "
		<< ex.history << " " << ex.geography << " " << ex.civic_education << " " << ex.natural_science << " " << ex.social_science << " "
		<< ex.foreign_language << endl;
	return os;
}

Examinee readExaminee(string line_info) {
	//doc 1 dong

	stringstream ss(line_info);
	string buffer;
	int i = 0;
	vector<string>arr;
	while (getline(ss, buffer, ',')) {
		if (buffer == "") {
			buffer = '0';
		}
		arr.push_back(buffer);
		//cout <<i++<<" "<< buffer << endl;
	}

	Examinee ex;

	ex.id = arr[0];
	ex.math =stof(arr[2]);
	ex.literature = stof(arr[3]);
	ex.physic = stof(arr[4]);
	ex.chemistry= stof(arr[5]);
	ex.biology = stof(arr[6]);
	ex.history = stof(arr[7]);
	ex.geography = stof(arr[8]);
	ex.civic_education = stof(arr[9]);
	ex.natural_science = stof(arr[10]);
	ex.social_science = stof(arr[11]);
	ex.foreign_language = stof(arr[12]);
	
	return ex;
}

vector<Examinee> readExamineeList(string file_name) {

	// doc toan bo du lieu trong file
	fstream is;
	is.open(file_name, fstream::in);
	string line_info;
	vector<Examinee> ex;
	if (is.is_open()) {
		
		is.ignore(numeric_limits<streamsize>::max(), '\n');

		int index = 0;

		/*while (!is.eof()) {
			getline(is, line_info,'\n');
			if (!is.eof()) {
				ex.push_back(readExaminee(line_info));
			}
		}*/

		while (getline(is, line_info, '\n') && !is.eof()){
				ex.push_back(readExaminee(line_info));
		}

	}
	else cout << "\nError opening file! ";
	return ex;
}

void writeTotal(vector<Examinee> examinee_list, string out_file_name) {

	//viet ra file moi tong diem

	ofstream file_out;
	file_out.open(out_file_name, fstream::out);
	if (!file_out.is_open()) {
		cout << "\nError opening file! ";
		return;
	}

	for (int i = 0; i < examinee_list.size(); i++) {

		Examinee ex = examinee_list[i];
		examinee_list[i].natural_science = ex.biology + ex.chemistry + ex.physic;
		examinee_list[i].social_science = ex.civic_education + ex.history + ex.geography;
		float GPA = examinee_list[i].math+examinee_list[i].literature + examinee_list[i].foreign_language + examinee_list[i].natural_science
			+ examinee_list[i].social_science;

		file_out << ex.id << " " << GPA<<endl;
	}

	file_out.close();
}
int main() {
	fstream file_in;
	file_in.open("data.txt", fstream::in);
	
	if (file_in.is_open()) {
		cout << "\nOpen file successfully!" << endl;

		string line_info;
		file_in.ignore(numeric_limits<streamsize>::max(), '\n');
		file_in >> line_info;


		Examinee ex = readExaminee(line_info);
		cout << "First line " << ex;

		file_in.close();
		vector<Examinee>arr;
		arr = readExamineeList("data.txt");
		unsigned int arrsize = arr.size();
		for (int i = 0; i < arrsize; i++) {
			cout << arr[i];
		}
		writeTotal(arr, "Output.txt");
	}
	else cout << "\nError opening file!";
	return 0;
}