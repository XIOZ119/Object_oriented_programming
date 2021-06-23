#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "IOIinterface.h"

using namespace std;

class Subject : public IOIinterface {
protected:
	string _Name;    //�����
	int m_hakjum;        //���� ��
	string m_grade;     //���
	float m_GPA;         //����

public:
	Subject();
	void InputData();
	void PrintData() const;
	void CalcGPA();
	void Modify(Subject*);

	string GetName() {
		return _Name;
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
