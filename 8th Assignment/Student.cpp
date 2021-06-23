#include <iostream>
#include "Student.h"
using namespace std;

Student::Student() {
	m_name = "ȫ�浿";
	m_hakbun = 201900000;
	m_subnum = 1;
	m_sub = new Subject[m_subnum];
	m_aveGPA = 0.0f;
}
Student::~Student() {
	delete m_sub;
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
	cout << "=======================================================================\n";
	cout.width(15);
	cout << "�̸�";
	cout.width(15);
	cout << m_name;
	cout.width(15);
	cout << "�й�";
	cout.width(15);
	cout << m_hakbun << "\n";

	cout << "=======================================================================\n";
	cout.width(15);
	cout << "�������";
	cout.width(15);
	cout << "��������";
	cout.width(15);
	cout << "������";
	cout.width(15);
	cout << "��������\n";
	cout << "=======================================================================\n";

	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "=======================================================================\n";

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

void Student::Modify(Student* std) {
	string modifyInfo;

	cout << "\n����(�л�����/��������) : ";
	InputValue(modifyInfo);
	cout << "\n";

	if (modifyInfo == "�л�����") {
		cout << "<" << std->GetName() << " , " << std->GetHakbun() << ">�� ������ �����ϼ���.\n";

		cout << "�̸� : ";
		InputValue(std->m_name);
		cout << "�й� : ";
		InputValue(std->m_hakbun);
		cout << "\n";
	}
	else if (modifyInfo == "��������") {
		m_sub->Modify(SubSearch(std));
		CalcAveGPA();
	}
	else {
		cout << "<�����ϰ��� �ϴ� ������ ��Ȯ�� �Է����ּ���.>\n\n";
	}
}

Subject* Student::SubSearch(Student* std) {
	string searchname;
	cout << "�˻� �� ���� �̸� : ";
	InputValue(searchname);

	for (int i = 0; i < m_subnum; i++) {
		if (searchname == std->m_sub[i].GetName()) {
			return &std->m_sub[i];
		}
	}
	cout << "<ã���ô� �������� �����ϴ�.>\n";


	return NULL;
}
