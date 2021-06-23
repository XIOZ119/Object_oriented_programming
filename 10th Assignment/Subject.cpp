#include <iostream>
#include "Student.h"
#include "Subject.h"
#include "IOIinterface.h"

Subject::Subject() {
	_Name = "����";
	m_hakjum = 3;
	m_grade = "A";
	m_GPA = 0.0f;
}


void Subject::InputData() {
	cout << "* ������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���.\n";
	cout << "������� : ";
	IOIinterface::InputValue(_Name);
	cout << "�������� : ";
	IOIinterface::InputValue(m_hakjum);
	cout << "������(A+ ~ F) : ";
	IOIinterface::InputValue(m_grade);
	cout << "\n";

	CalcGPA();
}

void Subject::PrintData() const {
	cout.width(15);
	cout << _Name;
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
	IOIinterface::InputValue(sub->_Name);

	cout << "�������� : ";
	IOIinterface::InputValue(sub->m_hakjum);

	cout << "������(A+ ~ F) : ";
	IOIinterface::InputValue(sub->m_grade);
	cout << "\n";

	CalcGPA();
}
