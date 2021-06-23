#pragma once
#include "Subject.h"
#include <string>
using namespace std;

class Student {
protected:
	string m_name;       //�̸�
	int m_hakbun;        //�й�
	float m_aveGPA;      //��� ����
	int m_subnum;        //���� ��

	Subject* m_sub;      //���� Ŭ����

public:
	Student();
	~Student();
	void InputValue(int&);
	void InputValue(string&);
	void InputData();
	void PrintData() const;
	void CalcAveGPA();
	void Modify(Student*);
	Subject* SubSearch(Student*);

	string GetName() {
		return m_name;
	}
	int GetHakbun() {
		return m_hakbun;
	}
	int GetSubNum() {
		return m_subnum;
	}
	float GetAveGPA() {
		return m_aveGPA;
	}

	friend void ShowData(const Student& s);
};
