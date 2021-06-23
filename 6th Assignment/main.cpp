#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Subject { //���� ���� 
	string SubName;  //���� �̸�
	int Hakjum;        //����������
	string Grade;    //���� ���
	float GPA;         //���� ����
};

struct Student { //�л� ���� 
	string StdName;  //�л� �̸�
	int Hakbun;        //�й�
	float AveGPA;      //������ ��� ����
	int SubNum;

	Subject* Sub;    //Subject �߰�
};

inline void PrintMenu() {

	//�޴� ���
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n";
	cout << "5. �л� ���� ����\n";
	cout << "6. ���α׷� ����\n\n";

	cout << "���ϴ� ����� �Է��ϼ��� : ";
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
		cout << "\n * " << stu + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		InputValue(pSt[stu].StdName);
		cout << "�й� : ";
		InputValue(pSt[stu].Hakbun);
		cout << "\n\n";

		cout << "�ش� �л��� ������ ���� ���� �Է��ϼ��� : ";
		InputValue(pSt[stu].SubNum);

		pSt[stu].Sub = new Subject[pSt[stu].SubNum];

		cout << "* ������ ����" << pSt[stu].SubNum << " ���� �� �������, ��������, �������� �Է��ϼ���.\n";

		for (int sub = 0; sub < pSt[stu].SubNum; sub++)
		{
			cout << "������� : ";
			InputValue(pSt[stu].Sub[sub].SubName);
			cout << "���� ���� �� : ";
			InputValue(pSt[stu].Sub[sub].Hakjum);
			cout << "������(A+ ~ F) : ";
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

Student* StdSearch(Student* pSt, int stdNum) {

	string searchname;
	cout << "�˻� �� �л� �̸� : ";
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
	cout << "�˻� �� ���� �̸� : ";
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
		cout << "�л��� �������� �ʽ��ϴ�.";
	}
}

void ModifyStdInfo(Student* pSt) {
	string Type;

	cout << "����(�л�����/��������) : ";
	InputValue(Type);
	cout << '\n';

	if (strcmp(Type.c_str(), "�л�����") == 0) { //���⼭���� ������ �� 
		cout << "* <" << pSt->StdName << " " << pSt->Hakbun << ">�� ������ �����ϼ���.\n\n";

		cout << "�̸� : ";
		InputValue(pSt->StdName);
		cout << "�й� : ";
		InputValue(pSt->Hakbun);
		cout << "\n\n";
	}
	else if (strcmp(Type.c_str(), "��������") == 0)
	{
		Subject* SearchSub = SubSearch(pSt);

		if (SearchSub != NULL) {
			cout << "<" << SearchSub->SubName << " " << SearchSub->Hakjum << " " << SearchSub->Grade << ">�� ������ �����ϼ���.\n\n";
			cout << "������� : ";
			InputValue(SearchSub->SubName);
			cout << "�������� : ";
			InputValue(SearchSub->Hakjum);
			cout << "������(A+ ~ F) : ";
			InputValue(SearchSub->Grade);
			cout << "\n";

			SearchSub->GPA = CalcGPA(*SearchSub);
			pSt->AveGPA = CalcAveGPA(pSt->Sub, pSt->SubNum);
		}
		else {
			cout << "<�ش� �л��� ã���� �ϴ� ������ �������� �ʽ��ϴ�.>\n\n";
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
		PrintMenu(); //�޴����
		InputValue(menu);
		cout << "\n";


		if (menu == 1) {
			cout << "���α׷��� ������ �л� ���� �Է��ϼ��� : ";
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
				cout << "�л��� �������� �ʽ��ϴ�.\n";
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
