#include "Subject.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;


void InputValue(string& str) {
	getline(cin, str);
}

void InputValue(int& i) {
	cin >> i;
	cin.ignore();
}

int main() {

	int menu;
	int stdnum = 0;
	Student* student = NULL;

	while (true)
	{
		cout << "====�޴�====\n";
		cout << "1. �л� ���� �Է�\n";
		cout << "2. ��ü �л� ���� ����\n";
		cout << "3. ���α׷� ����\n\n";
		cout << "���ϴ� ����� �Է��ϼ��� : ";

		InputValue(menu);
		cout << "\n";

		if (menu == 1) {
			cout << "�л� �� �Է� : ";
			InputValue(stdnum);

			student = new Student[stdnum];

			for (int i = 0; i < stdnum; i++) {
				cout << "*" << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
				student[i].Initialize();
				student[i].InputData();
			}

		}

		else if (menu == 2) {
			cout.precision(2);
			cout << fixed;
			//��ü �л� ���� ����
			cout.width(10);

			cout << "��ü �л� ���� ����\n";
			for (int i = 0; i < stdnum; i++)
			{
				student[i].PrintData();
			}
		}
	}
	delete[] student;
}