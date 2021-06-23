#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "IOIinterface.h"

using namespace std;

class Subject : public IOIinterface {
protected:
	string _Name;    //과목명
	int m_hakjum;        //학점 수
	string m_grade;     //등급
	float m_GPA;         //평점

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
