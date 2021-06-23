#include "Subject.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;


void InputValue(string& str) {
	getline(cin, str);
}

void InputValue(int& i) {
	cin >> i;
	cin.ignore();
}

int main() {

	int menu;
	int stdnum = 0;
	Student* student = NULL;

	while (true)
	{
		cout << "====메뉴====\n";
		cout << "1. 학생 성적 입력\n";
		cout << "2. 전체 학생 성적 보기\n";
		cout << "3. 프로그램 종료\n\n";
		cout << "원하는 기능을 입력하세요 : ";

		InputValue(menu);
		cout << "\n";

		if (menu == 1) {
			cout << "학생 수 입력 : ";
			InputValue(stdnum);

			student = new Student[stdnum];

			for (int i = 0; i < stdnum; i++) {
				cout << "*" << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
				student[i].Initialize();
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
	}
	delete[] student;
}