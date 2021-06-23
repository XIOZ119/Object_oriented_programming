#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Subject {
protected:
	string m_name;    //과목명
	int m_hakjum;        //학점 수
	string m_grade;     //등급
	float m_GPA;         //평점

private:
	void InputValue(int&);
	void InputValue(string&);

public:
	void Initialize();						//멤버변수 초기화(국어,3,A)
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
