#include "Subject.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;


inline void InputValue(string& str) {
	getline(cin, str);
}

inline void InputValue(int& i) {
	cin >> i;
	cin.ignore();
}

inline void PrintMenu() {
	cout << "=========메뉴=========\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 정보 수정\n";
	cout << "4. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요 : ";
}

void PrintAllData(const Student*, int); //모든 학생 정보 출력
void InputData(Student*, int); // 모든 학생 정보 입력

Student* stdSearch(Student* m_stu, int num) {
	string searchname;
	cout << "검색 할 학생 이름 : ";
	InputValue(searchname);
	for (int i = 0; i < num; i++) {
		if (searchname == m_stu[i].GetName()) {
			return &m_stu[i];
		}
	}
	cout << "<찾으시는 교과목이 없습니다.>\n";

	return NULL;
}

int main() {

	int menu;
	int stdnum = 0;

	Student* student = NULL;

	while (true)
	{
		PrintMenu();

		InputValue(menu);
		cout << "\n";

		if (menu == 1) {
			cout << "학생 수 입력 : ";
			InputValue(stdnum);
			cout << "\n";

			student = new Student[stdnum];

			for (int i = 0; i < stdnum; i++) {
				cout << "*" << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
				student[i].InputData();
			}
		}

		else if (menu == 2) {
			cout.precision(2);
			cout << fixed;
			//전체 학생 성적 보기
			cout.width(10);

			cout << "전체 학생 성적 보기\n";
			for (int i = 0; i < stdnum; i++)
			{
				student[i].PrintData();
			}
		}

		else if (menu == 3) {
			student->Modify(stdSearch(student, stdnum));
		}

		else if (menu == 4) {
			cout << "4. 프로그램 종료";
			break;
		}
	}
	delete[] student;
}

