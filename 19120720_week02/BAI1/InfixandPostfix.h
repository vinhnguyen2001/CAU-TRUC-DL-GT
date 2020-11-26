#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int Priority(char r_val);

void calculatePostfix(string a);

int convertChartoInt(char* r_Ch);

string convertInfixtoPostfix(string r, stack<char> s);
