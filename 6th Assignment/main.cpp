#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Subject { //과목 정보 
	string SubName;  //과목 이름
	int Hakjum;        //과목학점수
	string Grade;    //과목 등급
	float GPA;         //과목 평점
};

struct Student { //학생 정보 
	string StdName;  //학생 이름
	int Hakbun;        //학번
	float AveGPA;      //교과목 평균 평점
	int SubNum;

	Subject* Sub;    //Subject 추가
};

inline void PrintMenu() {

	//메뉴 출력
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n\n";

	cout << "원하는 기능을 입력하세요 : ";
}

inline void InputValue(string& str) {
	getline(cin, str);
}

inline void InputValue(int& i) {
	cin >> i;

	cin.ignore();
}

float CalcGPA(Subject& Sub) {
	int ret;

	if ((ret = strcmp(Sub.Grade.c_str(), "A+")) == 0)
	{
		Sub.GPA = 4.5 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade.c_str(), "A0")) == 0)
	{
		Sub.GPA = 4.0 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade.c_str(), "B+")) == 0)
	{
		Sub.GPA = 3.5 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade.c_str(), "B0")) == 0)
	{
		Sub.GPA = 3.0 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade.c_str(), "C+")) == 0)
	{
		Sub.GPA = 2.5 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade.c_str(), "C0")) == 0)
	{
		Sub.GPA = 2.0 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade.c_str(), "D+")) == 0)
	{
		Sub.GPA = 1.5 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade.c_str(), "D0")) == 0)
	{
		Sub.GPA = 1.0 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade.c_str(), "F")) == 0)
	{
		Sub.GPA = 0.0 * Sub.Hakjum;
	}
	return Sub.GPA;
}

float CalcAveGPA(Subject* Sub, int SubNum) {
	float sum = 0;
	int sumHakjum = 0;

	for (int i = 0; i < SubNum; i++) {
		sumHakjum += Sub[i].Hakjum;
		sum += Sub[i].GPA;
	}

	return (sum / (float)sumHakjum);
}

void InputData(Student* pSt, int stdNum)
{
	for (int stu = 0; stu < stdNum; stu++)
	{
		cout << "\n * " << stu + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		InputValue(pSt[stu].StdName);
		cout << "학번 : ";
		InputValue(pSt[stu].Hakbun);
		cout << "\n\n";

		cout << "해당 학생이 수강한 과목 수를 입력하세요 : ";
		InputValue(pSt[stu].SubNum);

		pSt[stu].Sub = new Subject[pSt[stu].SubNum];

		cout << "* 수강한 과목" << pSt[stu].SubNum << " 개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

		for (int sub = 0; sub < pSt[stu].SubNum; sub++)
		{
			cout << "교과목명 : ";
			InputValue(pSt[stu].Sub[sub].SubName);
			cout << "과목 학점 수 : ";
			InputValue(pSt[stu].Sub[sub].Hakjum);
			cout << "과목등급(A+ ~ F) : ";
			InputValue(pSt[stu].Sub[sub].Grade);
			cout << "\n";

			CalcGPA(pSt[stu].Sub[sub]);
		}
		pSt[stu].AveGPA = CalcAveGPA(pSt[stu].Sub, pSt[stu].SubNum);
	}
}

void printSub(const Subject* sub, int SubNum) {
	for (int i = 0; i < SubNum; i++) {
		cout.width(15);
		cout << sub[i].SubName;
		cout.width(15);
		cout << sub[i].Hakjum;
		cout.width(15);
		cout << sub[i].Grade;
		cout.width(15);
		cout << sub[i].GPA << "\n";
	}
}

void PrintOneData(const Student& rSt) {
	cout << " 이름 : " << rSt.StdName << "   학번 : " << rSt.Hakbun << "\n";
	cout << "============================================================\n";

	cout.width(15);
	cout << "과목명";
	cout.width(15);
	cout << "과목학점";
	cout.width(15);
	cout << "과목등급";
	cout.width(15);
	cout << "과목평점\n";
	cout << "=============================================\n";

	printSub(rSt.Sub, rSt.SubNum);
	cout << "==============================================\n";

	cout.width(45);
	cout << "평균평점 :";
	cout << rSt.AveGPA << "\n\n";
}

void PrintAllData(const Student* pSt, int stdNum) {
	cout << "                전체 학생 성적 보기" << "\n";
	cout << "======================================================\n";

	for (int i = 0; i < stdNum; i++) {
		PrintOneData(pSt[i]);
	}
}

void PrintAllStdList(const Student* pSt, int stdNum) {
	cout << "====================================================\n";
	cout.width(15);
	cout << "학번";
	cout.width(15);
	cout << "이름\n";
	cout << "=====================================================\n";
	for (int i = 0; i < stdNum; i++)
	{
		cout.width(15);
		cout << pSt[i].Hakbun;
		cout.width(15);
		cout << pSt[i].StdName << "\n";
	}
}

Student* StdSearch(Student* pSt, int stdNum) {

	string searchname;
	cout << "검색 할 학생 이름 : ";
	InputValue(searchname);

	for (int i = 0; i < stdNum; i++)
	{
		if (searchname == pSt[i].StdName)
		{
			return &pSt[i];
		}
		else;
	}
}

Subject* SubSearch(const Student* pSt) {

	string searchsub;
	cout << "검색 할 과목 이름 : ";
	InputValue(searchsub);

	for (int i = 0; i < pSt->SubNum; i++)
	{
		if (searchsub == pSt->Sub[i].SubName)
		{
			return &(pSt->Sub[i]);
		}
		else;
	}
	return NULL;
}

void Search(Student* pSt, int stdNum) {
	Student* searchStd = NULL;

	searchStd = StdSearch(pSt, stdNum);

	if (searchStd) {
		PrintOneData(*searchStd);
	}
	else {
		cout << "학생이 존재하지 않습니다.";
	}
}

void ModifyStdInfo(Student* pSt) {
	string Type;

	cout << "수정(학생정보/과목정보) : ";
	InputValue(Type);
	cout << '\n';

	if (strcmp(Type.c_str(), "학생정보") == 0) { //여기서부터 문제인 듯 
		cout << "* <" << pSt->StdName << " " << pSt->Hakbun << ">의 정보를 수정하세요.\n\n";

		cout << "이름 : ";
		InputValue(pSt->StdName);
		cout << "학번 : ";
		InputValue(pSt->Hakbun);
		cout << "\n\n";
	}
	else if (strcmp(Type.c_str(), "과목정보") == 0)
	{
		Subject* SearchSub = SubSearch(pSt);

		if (SearchSub != NULL) {
			cout << "<" << SearchSub->SubName << " " << SearchSub->Hakjum << " " << SearchSub->Grade << ">의 정보를 수정하세요.\n\n";
			cout << "교과목명 : ";
			InputValue(SearchSub->SubName);
			cout << "과목학점 : ";
			InputValue(SearchSub->Hakjum);
			cout << "과목등급(A+ ~ F) : ";
			InputValue(SearchSub->Grade);
			cout << "\n";

			SearchSub->GPA = CalcGPA(*SearchSub);
			pSt->AveGPA = CalcAveGPA(pSt->Sub, pSt->SubNum);
		}
		else {
			cout << "<해당 학생은 찾고자 하는 과목을 수강하지 않습니다.>\n\n";
		}

	}

}

int main()
{
	Student* student = NULL, * SearchStd = NULL;
	int menu;
	int stdNum = 0;

	cout.precision(2);
	cout << fixed;

	while (true)
	{
		PrintMenu(); //메뉴출력
		InputValue(menu);
		cout << "\n";


		if (menu == 1) {
			cout << "프로그램에 저장할 학생 수를 입력하세요 : ";
			InputValue(stdNum);

			student = new Student[stdNum];

			InputData(student, stdNum);
		}

		else if (menu == 2) {
			PrintAllData(student, stdNum);
		}
		else if (menu == 3) {
			Search(student, stdNum);
		}
		else if (menu == 4) {
			PrintAllStdList(student, stdNum);
		}
		else if (menu == 5) {
			Student* FindStd = NULL;

			FindStd = StdSearch(student, stdNum);

			if (FindStd != NULL) {
				ModifyStdInfo(FindStd);
			}
			else {
				cout << "학생이 존재하지 않습니다.\n";
			}
		}
		else if (menu == 6)
		{
			break;
		}
	}
	delete[] student;
	return 0;
}
