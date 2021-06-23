#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Subject {
protected:
	string m_name;    //�����
	int m_hakjum;        //���� ��
	string m_grade;     //���
	float m_GPA;         //����

private:
	void InputValue(int&);
	void InputValue(string&);

public:
	void Initialize();						//������� �ʱ�ȭ(����,3,A)
	void Initialize(string, int, string);
	void InputData();
	void PrintData() const;
	void CalcGPA();

	string GetName() {
		return m_name;
	}
	int GetHakjum() {
		return m_hakjum;
	}
	string GetGrade() {
		return m_grade;
	}
	float GetGPA() {
		return m_GPA;
	}
};
