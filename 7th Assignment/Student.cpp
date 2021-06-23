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
	cout << "이름 : ";
	InputValue(m_name);
	cout << "학번 : ";
	InputValue(m_hakbun);
	cout << "과목 수 : ";
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
	cout << "이름";
	cout.width(15);
	cout << m_name; // 여기 출력 안 되고 종료됨
	cout.width(15);
	cout << "학번";
	cout << m_hakbun << "\n";

	cout << "====================================================\n";
	cout.width(15);
	cout << "교과목명";
	cout.width(15);
	cout << "과목학점";
	cout.width(15);
	cout << "과목등급";
	cout.width(15);
	cout << "과목평점\n";
	cout << "====================================================\n";

	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "====================================================\n";

	cout.width(45);
	cout << "평균평점 : ";
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