#include <iostream>
#include <iomanip>

using namespace std;

struct Subject { //과목 정보 
	char SubName[30];  //과목 이름
	int Hakjum;        //과목학점수
	char Grade[10];    //과목 등급
	float GPA;         //과목 평점
};

struct Student { //학생 정보 
	char StdName[30];  //학생 이름
	int Hakbun;        //학번
	float AveGPA;      //교과목 평균 평점
	int SubNum;

	Subject* Sub;    //Subject 추가
};

inline void PrintMenu() {

	//메뉴 출력
	cout << "==== 메뉴 ====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요 : ";
}

inline void InputValue(char* str) {
	cin >> str;
}

inline void Inputvalue(int& i) {
	cin >> i;
}

void CalcGPA(Subject& Sub, int SubNum) {
	int ret;

	if ((ret = strcmp(Sub.Grade, "A+")) == 0)
	{
		Sub.GPA = 4.5 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade, "A0")) == 0)
	{
		Sub.GPA = 4.0 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade, "B+")) == 0)
	{
		Sub.GPA = 3.5 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade, "B0")) == 0)
	{
		Sub.GPA = 3.0 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade, "C+")) == 0)
	{
		Sub.GPA = 2.5 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade, "C0")) == 0)
	{
		Sub.GPA = 2.0 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade, "D+")) == 0)
	{
		Sub.GPA = 1.5 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade, "D0")) == 0)
	{
		Sub.GPA = 1.0 * Sub.Hakjum;
	}
	else if ((ret = strcmp(Sub.Grade, "F")) == 0)
	{
		Sub.GPA = 0.0 * Sub.Hakjum;
	}
}

double CalcAveGPA(Subject* Sub, int SubNum) {
	float sum = 0;

	for (int i = 0; i < SubNum; i++) {
		sum += Sub[i].GPA;
	}


	return (sum / 3);
}

void InputData(Student* pSt, int StudentNum)
{
	for (int stu = 0; stu < StudentNum; stu++)
	{
		cout << "\n * " << stu + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		InputValue(pSt[stu].StdName);
		cout << "학번 : ";
		Inputvalue(pSt[stu].Hakbun);
		cout << "\n\n";

		cout << "해당 학생이 수강한 과목 수를 입력하세요 : ";
		cin >> pSt[stu].SubNum;

		pSt[stu].Sub = new Subject[pSt[stu].SubNum];

		for (int sub = 0; sub < pSt[stu].SubNum; sub++)
		{
			cout << "* 수강한 과목" << pSt[stu].SubNum << " 개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
			cout << "교과목명 : ";
			InputValue(pSt[stu].Sub[sub].SubName);
			cout << "과목 학점 수 : ";
			Inputvalue(pSt[stu].Sub[sub].Hakjum);
			cout << "과목등급(A+ ~ F) : ";
			InputValue(pSt[stu].Sub[sub].Grade);

			CalcGPA(pSt[stu].Sub[sub], pSt[stu].SubNum);
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
	//출력될 정보들을 화면에 표시 
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

Student* StdSearch(Student* pSt) {

	char searchname[20];
	cout << "검색 할 학생 이름 : ";
	cin >> searchname;
	for (int i = 0; i < 2; i++)
	{
		if (strcmp(searchname, pSt[i].StdName) == 0)
		{
			return &pSt[i];
		}
		else;
	}
	return NULL;
}

void Search(Student* pSt) {
	Student* searchStd = NULL;

	searchStd = StdSearch(pSt);

	if (searchStd) {
		PrintOneData(*searchStd);
	}
	else {
		cout << "학생이 존재하지 않습니다.";
	}
}

void ModifyStdInfo(Student* pSt) {
	cout << "<" << pSt->StdName << " " << pSt->Hakbun << ">의 정보를 수정하세요.\n\n";

	cout << "이름 : ";
	InputValue(pSt->StdName);
	cout << "학번 : ";
	Inputvalue(pSt->Hakbun);
	cout << "\n\n";
}

int main()
{
	Student* student = NULL;
	char menu;
	int stdNum = 0;

	while (true)
	{

		PrintMenu(); //메뉴출력
		cin >> menu;
		cout << "\n";

		if (menu == '6')
			break;

		switch (menu)
		{
		case '1':
		{
			cout << "프로그램에 저장할 학생 수를 입력하세요 : ";
			cin >> stdNum;

			student = new Student[stdNum];

			InputData(student, stdNum);
			break;
		}

		case '2':
		{
			PrintAllData(student, stdNum);
			break;
		}

		case '3':
			Search(student);
			break;
		case '4':
			PrintAllStdList(student, stdNum);
			break;
		case '5':
			Student * FindStd = NULL;

			FindStd = StdSearch(student);

			if (FindStd != NULL) {
				ModifyStdInfo(FindStd);
			}
			else {
				cout << "학생이 존재하지 않습니다.\n";
			}
		}

	}
	return 0;
}
