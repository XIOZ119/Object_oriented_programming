#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Students {
	vector<string>Names;
	vector<int>Hakbuns;
	string Name;
	int Hakbun;

public:
	void InputData(Students& St);
	void PrintData(Students& St);
	void DeleteData(Students& St);

	inline void InputValue(int& ref) {
		cin >> ref;
		cin.ignore();
	}

	inline void InputValue(string& ref) {
		getline(cin, ref);
		if (ref.empty())
			getline(cin, ref);
	}
};