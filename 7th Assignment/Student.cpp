#include <iostream>
#include "Student.h"
using namespace std;

void Student::Initialize() {
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0f;
}
void Student::Initialize(string stdName, int stdHakbun, int subNum) {
	m_name = stdName;
	m_hakbun = stdHakbun;
	m_subnum = subNum;
	m_sub = new Subject[m_subnum];

	CalcAveGPA();
}
void Student::Remove() {
	delete[] m_sub;
}

void Student::InputValue(string& str) {
	getline(cin, str);
}

void Student::InputValue(int& i) {
	cin >> i;
	cin.ignore();
}

void Student::InputData() {
	cout << "�̸� : ";
	InputValue(m_name);
	cout << "�й� : ";
	InputValue(m_hakbun);
	cout << "���� �� : ";
	InputValue(m_subnum);
	cout << "\n\n\n";

	m_sub = new Subject[m_subnum];

	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].InputData();
	}

	CalcAveGPA();
}
void Student::PrintData() const {
	cout << "====================================================\n";
	cout.width(15);
	cout << "�̸�";
	cout.width(15);
	cout << m_name; // ���� ��� �� �ǰ� �����
	cout.width(15);
	cout << "�й�";
	cout << m_hakbun << "\n";

	cout << "====================================================\n";
	cout.width(15);
	cout << "�������";
	cout.width(15);
	cout << "��������";
	cout.width(15);
	cout << "������";
	cout.width(15);
	cout << "��������\n";
	cout << "====================================================\n";

	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "====================================================\n";

	cout.width(45);
	cout << "������� : ";
	cout << m_aveGPA << "\n";

}
void Student::CalcAveGPA() {
	int SumHakjum = 0;
	float SumGPA = 0.0;

	for (int i = 0; i < m_subnum; i++) {
		SumHakjum += m_sub[i].GetHakjum();
		SumGPA += m_sub[i].GetGPA();
	}
	m_aveGPA = SumGPA / (float)SumHakjum;
}