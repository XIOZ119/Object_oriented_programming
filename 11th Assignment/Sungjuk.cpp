#include "Student.h"
#include <algorithm>
#include <iostream>
using namespace std;

inline void InputValue(int& ref) {
	cin >> ref;
}

inline void InputValue(string& ref) {
	getline(cin, ref);
	if (ref.empty())
		getline(cin, ref);
}

inline void PrintMenu() {
	cout << "=========�޴�=========" << endl;
	cout << "1. �л� ���� �Է�" << endl;
	cout << "2. �л� ���� ����" << endl;
	cout << "3. �л� ���� ����" << endl;
	cout << "4. ���α׷� ����" << endl << endl;
	cout << "���ϴ� ����� �Է��ϼ��� : ";
}

int main() {
	int select_menu = 0;
	Students St;

	while (true)
	{
		PrintMenu();

		InputValue(select_menu);
		cout << "\n";

		if (select_menu == 1) {
			St.InputData(St);
		}

		else if (select_menu == 2) {
			cout.width(25);
			cout << "�л� ���� ����\n";
			St.PrintData(St);
		}

		else if (select_menu == 3) {
			St.DeleteData(St);
		}

		else if (select_menu == 4) {
			cout << "-------------------------";

			break;
		}
	}
}
