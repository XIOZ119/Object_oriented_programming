#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Subject { // 과목정보
	char SubName[30];  // 과목이름
	int Hakjum;        // 과목학점수
	char Grade[10];    // 과목 등급
	float NumHakjum;    // 과목 등급 숫자
	float GPA;         // 과목 평점
};

struct Student { // 학생 정보
	char StdName[30];  // 학생 이름
	int Hakbun;		   // 학번
	float AveGPA;      // 교과목 평균 평점

	Subject Sub[3]; // Subject 추가
};

int main()
{
	struct Student student[2] = { 0 };
	int stu = 0;
	char menu;

	while (true)
	{
		// 메뉴 출력
		cout << "==== 메뉴 ====\n";
		cout << "1. 학생 성적 입력\n";
		cout << "2. 전체 학생 성적 보기\n";
		cout << "3. 프로그램 종료\n\n";
		cout << "원하는 기능을 입력하세요 : ";
		cin >> menu;
		cout << "\n";

		if (menu == '3')
			break;

		switch (menu)
		{
		case '1':
			if (stu == 2)
			{
				cout << "더이상 고객 정보를 입력하실 수 없습니다.\n";
				break;
			}
			for (int stu = 0; stu < 2; stu++)
			{
				cout << "*" << stu + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
				cout << "이름 : ";
				cin >> student[stu].StdName;
				cout << "학번 : ";
				cin >> student[stu].Hakbun;
				cout << "\n\n";

				for (int sub = 0; sub < 3; sub++)
				{
					cout << "* 수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
					cout << "교과목명 : ";
					cin >> student[stu].Sub[sub].SubName;
					cout << "과목학점수 : ";
					cin >> student[stu].Sub[sub].Hakjum;
					cout << "과목등급(A+ ~ F) : ";
					cin >> student[stu].Sub[sub].Grade;
					cout << "과목등급을 숫자로 : ";
					cin >> student[stu].Sub[sub].NumHakjum;
					cout << "\n";

					student[stu].Sub[sub].GPA = (student[stu].Sub[sub].Hakjum * student[stu].Sub[sub].NumHakjum);
				}

				student[0].AveGPA = (student[0].Sub[0].GPA + student[0].Sub[1].GPA + student[0].Sub[2].GPA) / 3;
				student[1].AveGPA = (student[1].Sub[0].GPA + student[1].Sub[1].GPA + student[1].Sub[2].GPA) / 3;

			}
		}

		if (menu == '2')
		{
			cout.precision(2);
			cout << fixed;

			//전체 학생 성적 보기 

			cout.width(10); cout << std::right << "전체 학생 성적 보기\n";
			cout << "-------------------------------------------------\n";
			for (int i = 0; i < 2; i++)
			{
				cout << "이름 : " << student[i].StdName << " 학번 : " << student[i].Hakbun;
				cout << "\n-------------------------------------------------\n";
				cout.width(10); cout << "과목명";
				cout.width(10); cout << "과목학점";
				cout.width(10); cout << "과목등급";
				cout.width(10); cout << "과목평점" << endl;
				cout << "-------------------------------------------------\n";
				for (int j = 0; j < 3; j++)
				{
					cout.width(10); cout << std::right << student[i].Sub[j].SubName;
					cout.width(10); cout << std::right << student[i].Sub[j].Hakjum;
					cout.width(13); cout << std::right << student[i].Sub[j].Grade;
					cout.width(11); cout << std::right << student[i].Sub[j].GPA << "\n";
				}
				cout << "=================================================\n";
				cout.width(43); cout << "평균평점" << student[i].AveGPA << "\n";
			}
		}
	}
	return 0;
}