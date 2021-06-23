#include <iostream>
#include <iomanip>

using namespace std;

struct Subject { //���� ���� 
	char SubName[30];  //���� �̸�
	int Hakjum;        //����������
	char Grade[10];    //���� ���
	float GPA;         //���� ����
};

struct Student { //�л� ���� 
	char StdName[30];  //�л� �̸�
	int Hakbun;        //�й�
	float AveGPA;      //������ ��� ����
	int SubNum;

	Subject* Sub;    //Subject �߰�
};

inline void PrintMenu() {

	//�޴� ���
	cout << "==== �޴� ====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n";
	cout << "5. �л� ���� ����\n";
	cout << "6. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ��� : ";
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
		cout << "\n * " << stu + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		InputValue(pSt[stu].StdName);
		cout << "�й� : ";
		Inputvalue(pSt[stu].Hakbun);
		cout << "\n\n";

		cout << "�ش� �л��� ������ ���� ���� �Է��ϼ��� : ";
		cin >> pSt[stu].SubNum;

		pSt[stu].Sub = new Subject[pSt[stu].SubNum];

		for (int sub = 0; sub < pSt[stu].SubNum; sub++)
		{
			cout << "* ������ ����" << pSt[stu].SubNum << " ���� �� �������, ��������, �������� �Է��ϼ���.\n";
			cout << "������� : ";
			InputValue(pSt[stu].Sub[sub].SubName);
			cout << "���� ���� �� : ";
			Inputvalue(pSt[stu].Sub[sub].Hakjum);
			cout << "������(A+ ~ F) : ";
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
	//��µ� �������� ȭ�鿡 ǥ�� 
	cout << " �̸� : " << rSt.StdName << "   �й� : " << rSt.Hakbun << "\n";
	cout << "============================================================\n";

	cout.width(15);
	cout << "�����";
	cout.width(15);
	cout << "��������";
	cout.width(15);
	cout << "������";
	cout.width(15);
	cout << "��������\n";
	cout << "=============================================\n";

	printSub(rSt.Sub, rSt.SubNum);
	cout << "==============================================\n";

	cout.width(45);
	cout << "������� :";
	cout << rSt.AveGPA << "\n\n";
}

void PrintAllData(const Student* pSt, int stdNum) {
	cout << "                ��ü �л� ���� ����" << "\n";
	cout << "======================================================\n";

	for (int i = 0; i < stdNum; i++) {
		PrintOneData(pSt[i]);
	}
}

void PrintAllStdList(const Student* pSt, int stdNum) {
	cout << "====================================================\n";
	cout.width(15);
	cout << "�й�";
	cout.width(15);
	cout << "�̸�\n";
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
	cout << "�˻� �� �л� �̸� : ";
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
		cout << "�л��� �������� �ʽ��ϴ�.";
	}
}

void ModifyStdInfo(Student* pSt) {
	cout << "<" << pSt->StdName << " " << pSt->Hakbun << ">�� ������ �����ϼ���.\n\n";

	cout << "�̸� : ";
	InputValue(pSt->StdName);
	cout << "�й� : ";
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

		PrintMenu(); //�޴����
		cin >> menu;
		cout << "\n";

		if (menu == '6')
			break;

		switch (menu)
		{
		case '1':
		{
			cout << "���α׷��� ������ �л� ���� �Է��ϼ��� : ";
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
				cout << "�л��� �������� �ʽ��ϴ�.\n";
			}
		}

	}
	return 0;
}
