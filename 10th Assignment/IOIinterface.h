#pragma once
#include <string>
#include <iostream>
using namespace std;

class IOIinterface {
public:
	inline static void InputValue(int& i) {
		cin >> i;
		cin.ignore();
	}
	inline static void InputValue(string& str) {
		getline(cin, str);
	}
	string _Name;
	virtual string GetName() = 0; // 가상함수 생성
};