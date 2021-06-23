#include "Subject.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;


inline void InputValue(string& str) {
	getline(cin, str);
}

inline void InputValue(int& i) {
	cin >> i;
	cin.ignore();
}

inline void PrintMenu() {
	cout << "=========�޴�=========\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� ���� ����\n";
	cout << "4. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ��� : ";
}

void PrintAllData(const Student*, int); //��� �л� ���� ���
void InputData(Student*, int); // ��� �л� ���� �Է�

Student* stdSearch(Student* m_stu, int num) {
	string searchname;
	cout << "�˻� �� �л� �̸� : ";
	InputValue(searchname);
	for (int i = 0; i < num; i++) {
		if (searchname == m_stu[i].GetName()) {
			return &m_stu[i];
		}
	}
	cout << "<ã���ô� �������� �����ϴ�.>\n";

	return NULL;
}

int main() {

	int menu;
	int stdnum = 0;

	Student* student = NULL;

	while (true)
	{
		PrintMenu();

		InputValue(menu);
		cout << "\n";

		if (menu == 1) {
			cout << "�л� �� �Է� : ";
			InputValue(stdnum);
			cout << "\n";

			student = new Student[stdnum];

			for (int i = 0; i < stdnum; i++) {
				cout << "*" << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
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

		else if (menu == 3) {
			student->Modify(stdSearch(student, stdnum));
		}

		else if (menu == 4) {
			cout << "4. ���α׷� ����";
			break;
		}
	}
	delete[] student;
}

