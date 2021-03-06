#include <iostream>
#include "Student.h"
#include "IOIinterface.h"
using namespace std;

Student::Student() {
	_Name = "홍길동";
	m_hakbun = 201900000;
	m_subnum = 1;
	m_sub = new Subject[m_subnum];
	m_aveGPA = 0.0f;
}

Student::~Student() {
	delete m_sub;
}

void Student::InputData() {
	cout << "이름 : ";
	IOIinterface::InputValue(_Name);
	cout << "학번 : ";
	IOIinterface::InputValue(m_hakbun);
	cout << "과목 수 : ";
	IOIinterface::InputValue(m_subnum);
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
	cout << "이름";
	cout.width(15);
	cout << IOIinterface::_Name;
	cout.width(15);
	cout << "학번";
	cout.width(15);
	cout << m_hakbun << "\n";

	cout << "=======================================================================\n";
	cout.width(15);
	cout << "교과목명";
	cout.width(15);
	cout << "과목학점";
	cout.width(15);
	cout << "과목등급";
	cout.width(15);
	cout << "과목평점\n";
	cout << "=======================================================================\n";

	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "=======================================================================\n";

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

void Student::Modify(Student* std) {
	string modifyInfo;

	cout << "\n수정(학생정보/과목정보) : ";
	IOIinterface::InputValue(modifyInfo);
	cout << "\n";

	if (modifyInfo == "학생정보") {
		cout << "<" << std->GetName() << " , " << std->GetHakbun() << ">의 정보를 수정하세요.\n";

		cout << "이름 : ";
		IOIinterface::InputValue(std->_Name);
		cout << "학번 : ";
		IOIinterface::InputValue(std->m_hakbun);
		cout << "\n";
	}
	else if (modifyInfo == "과목정보") {
		m_sub->Modify(SubSearch(std));
		CalcAveGPA();
	}
	else {
		cout << "<수정하고자 하는 정보를 정확히 입력해주세요.>\n\n";
	}
}

Subject* Student::SubSearch(Student* std) {
	string searchname;
	cout << "검색 할 과목 이름 : ";
	IOIinterface::InputValue(searchname);

	for (int i = 0; i < m_subnum; i++) {
		if (searchname == std->m_sub[i].GetName()) {
			return &std->m_sub[i];
		}
	}
	cout << "<찾으시는 교과목이 없습니다.>\n";


	return NULL;
}
