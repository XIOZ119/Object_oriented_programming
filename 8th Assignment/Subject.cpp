#include <iostream>
#include "Student.h"
#include "Subject.h"

Subject::Subject() {
	m_name = "����";
	m_hakjum = 3;
	m_grade = "A";
	m_GPA = 0.0f;
}

void Subject::InputValue(string& str) {
	getline(cin, str);
}

void Subject::InputValue(int& i) {
	cin >> i;
	cin.ignore();
}

void Subject::InputData() {
	cout << "* ������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���.\n";
	cout << "������� : ";
	InputValue(m_name);
	cout << "�������� : ";
	InputValue(m_hakjum);
	cout << "������(A+ ~ F) : ";
	InputValue(m_grade);
	cout << "\n";

	CalcGPA();
}

void Subject::PrintData() const {
	cout.width(15);
	cout << m_name;
	cout.width(15);
	cout << m_hakjum;
	cout.width(15);
	cout << m_grade;
	cout.width(15);
	cout << m_GPA << "\n";
}

void Subject::CalcGPA() {
	float result;

	if (m_grade == "A+")
	{
		result = 4.5;
	}
	else if (m_grade == "A0")
	{
		result = 4.0;
	}
	else if (m_grade == "B+")
	{
		result = 3.5;
	}
	else if (m_grade == "B0")
	{
		result = 3.0;
	}
	else if (m_grade == "C+")
	{
		result = 2.5;
	}
	else if (m_grade == "C0")
	{
		result = 2.0;
	}
	else if (m_grade == "D+")
	{
		result = 1.5;
	}
	else if (m_grade == "D0")
	{
		result = 1.0;
	}
	else if (m_grade == "F")
	{
		result = 0.0;
	}

	m_GPA = result * m_hakjum;
}

void Subject::Modify(Subject* sub) {
	cout << "������� : ";
	InputValue(sub->m_name);

	cout << "�������� : ";
	InputValue(sub->m_hakjum);

	cout << "������(A+ ~ F) : ";
	InputValue(sub->m_grade);
	cout << "\n";

	CalcGPA();
}
