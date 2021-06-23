#include "Student.h"
#include <algorithm>
#include <iostream>
using namespace std;

inline void InputValue(int& ref) {
	cin >> ref;
}

inline void InputValue(string& ref) {
	getline(cin, ref);
	if (ref.empty())
		getline(cin, ref);
}

inline void PrintMenu() {
	cout << "=========메뉴=========" << endl;
	cout << "1. 학생 정보 입력" << endl;
	cout << "2. 학생 정보 보기" << endl;
	cout << "3. 학생 정보 삭제" << endl;
	cout << "4. 프로그램 종료" << endl << endl;
	cout << "원하는 기능을 입력하세요 : ";
}

int main() {
	int select_menu = 0;
	Students St;

	while (true)
	{
		PrintMenu();

		InputValue(select_menu);
		cout << "\n";

		if (select_menu == 1) {
			St.InputData(St);
		}

		else if (select_menu == 2) {
			cout.width(25);
			cout << "학생 정보 보기\n";
			St.PrintData(St);
		}

		else if (select_menu == 3) {
			St.DeleteData(St);
		}

		else if (select_menu == 4) {
			cout << "-------------------------";

			break;
		}
	}
}
