#include "Student.h"
#include <algorithm>
#include <iostream>
using namespace std;

void Students::InputData(Students& St) {
	cout << "�̸� : ";
	InputValue(Name);
	Names.push_back(Name);
	cout << "�й� : ";
	InputValue(Hakbun);
	Hakbuns.push_back(Hakbun);
	cout << "\n";
}

void Students::PrintData(Students& St) {
	cout << "=====================================\n";
	cout.width(12);
	cout << "�̸�";
	cout.width(12);
	cout << "�й�" << endl;
	cout << "=====================================\n";
	for (int i = 0; i < Names.size(); i++)
	{
		cout.width(12);
		cout << Names[i];
		cout.width(12);
		cout << Hakbuns[i] << endl;
	}
	cout << "=====================================\n";
}

void Students::DeleteData(Students& St) {
	Names.pop_back();
	Hakbuns.pop_back();
}