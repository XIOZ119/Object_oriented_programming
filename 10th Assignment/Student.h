#pragma once
#include "Subject.h"
#include "IOIinterface.h"
#include <string>
using namespace std;

class Student : public IOIinterface {
protected:
	int m_hakbun;        //학번
	float m_aveGPA;      //평균 평점
	int m_subnum;        //과목 수
	string _Name;

	Subject* m_sub;      //과목 클래스


public:
	Student();
	~Student();
	void InputData();
	void PrintData() const;
	void CalcAveGPA();
	void Modify(Student*);
	Subject* SubSearch(Student*);

	string GetName() {
		return _Name;
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