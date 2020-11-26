
#include"InfixandPostfix.h"

int Priority(char r_val) {

	//Do uu tien 
	if (r_val == '(' || r_val == ')') return 0;
	else if (r_val == '+' || r_val == '-') return 1;
	else if (r_val == '*' || r_val == '/') return 2;
	else if (r_val == '^') return 3;
	else return 4;
}

string convertInfixtoPostfix(string r ,stack<char> s) {

	// doi sang hau to 
	int i = 0;
	int length = r.length();
	string a;
	string str;
	while (i < length) {

		char Character = r[i];

		if (Character != ' ') {

			if (('0' <= Character && Character <= '9') ||
				(Character == '-' && (i == 0 || r[i - 1] == '-' || r[i - 1] == '+' ||
			     r[i - 1] == '*' || r[i - 1] == '/' || r[i - 1] == '*'))) {
				a += Character;
			}
			else {
				str +=a;
				str += ' ';
				a = "";
			
				if (Character == '(') {
					s.push(Character);

				}
				else {

					if (Character == ')') {
						while (s.top() != '(') {

							str += s.top();
							s.pop();
						}
						s.pop();
					}
					else {

						while (!s.empty() && Priority(Character) <= Priority(s.top())) {
							str += s.top();
							str+= ' ';
							s.pop();
						}
						s.push(Character);
					}
				}
			}
		}
		i++;
	}
	if (a != "") {
		str+= a;
		str+= ' ';
	}
	while (!s.empty()) {
		str += s.top();
		str += ' ';
		s.pop();
	}
	
	return str;
}

int convertChartoInt(char* r_Ch) {

	// doi tu ki tu sang so (ap dung cho ca 2 chu so )
	int result = 0;
	int len_r_ch = strlen(r_Ch);
	for (int i = strlen(r_Ch) - 1, j = 0; i >= 0; i--, j++) {
		result += int (int (r_Ch[i] - 48) * pow(10, j));
	}
	return result;
}


void calculatePostfix(string a) {

	// tinh toan hau to 

	int j = 0;
	int length = a.length();
	string temp;

	stack<double> s;

	for (int i = 0; i < length; i++) {

		int flag = 0; // dat co tinh truong hop so am

		/*
		Tinh truong hop so nguyen am (line 126)
		*/
		
		if ((0 <= a[i]- '0' && a[i] - '0' <= 9) || (a[i] == '-' && '0' <= a[i + 1] && a[i + 1] <= '9'))
		{
			
			if (a[i] == '-') {
			
				flag = 1;
				i++;
			}
			j = i;
			
			// dung de cat chuoi con (line 120)

			while (a[j] != ' ') {
				j++;
			}
			temp = a.substr(i, j-i );
		
			double number = convertChartoInt((char*)temp.c_str());

			if (flag == 1) {

				number = -number;
			}
			s.push(number);
			number = 0;
			i = j;
			temp = "";
		}
		else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '^') {

			double c = 0;
			double b = 0;

			if (!s.empty()) {
				c = s.top();
				s.pop();
			}
	
			if (!s.empty()) {
				b = s.top();
				s.pop();
			}
		
			double result = 0;
			if (a[i] == '+') result = c + b;
			else if (a[i] == '-') result = b - c;
			else if (a[i] == '*') result = c * b;
			else if (a[i] == '/') result = b/ c;
			else if (a[i] == '^') result = pow(b,c);
			s.push(result);
		}
	}

	cout << "\nKET QUA CUA PHEP TINH: " << s.top() << endl;
	s.pop();
}


int main() {
	
	string a;
	a= "(10--1)*2-2*3^2";
	//getline(cin, a);
	stack<char> s;

	string b = convertInfixtoPostfix(a, s);
	cout << "\nBIEU THUC HAU TO:" << b;
	calculatePostfix(b);
	
	return 0;
}