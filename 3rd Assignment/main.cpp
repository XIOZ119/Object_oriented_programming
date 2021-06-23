#include <iostream>
#include <iomanip>

using namespace std;

struct Subject { //���� ���� 
	char SubName[30];  //���� �̸�
	int Hakjum;        //����������
	char Grade[10];    //���� ���
	double GPA;         //���� ����
};

struct Student { //�л� ���� 
	char StdName[30];  //�л� �̸�
	int Hakbun;        //�й�
	double AveGPA;      //������ ��� ����

	Subject Sub[3];    //Subject �߰�
};


void PrintMenu() {
	//�޴� ���
	cout << "==== �޴� ====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ��� : ";
}

void CalcGPA(Subject& Sub) {
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

double CalcAveGPA(Subject* Sub) {
	double sum = 0;

	for (int i = 0; i < 3; i++) {
		sum += Sub[i].GPA;
	}

	return (sum / 3);
}

void printSub(const Subject* sub) {
	for (int i = 0; i < 3; i++) {
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
	cout << " �̸� : " << rSt.StdName << "�й� : " << rSt.Hakbun << "\n";
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

	printSub(rSt.Sub);
	cout << "==============================================\n";

	cout.width(45);
	cout << "������� :";
	cout << rSt.AveGPA << "\n\n";
}

void PrintAllData(const Student* pSt) {
	cout << "                ��ü �л� ���� ����" << "\n";
	cout << "======================================================\n";

	for (int i = 0; i < 2; i++) {
		PrintOneData(pSt[i]);
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

int main()
{
	struct Student student[2] = { 0 };
	char menu;

	while (true)
	{
		PrintMenu(); //�޴����
		cin >> menu;
		cout << "\n";

		if (menu == '4')
			break;

		switch (menu)
		{
		case '1':
			for (int stu = 0; stu < 2; stu++)
			{
				cout << "*" << stu + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
				cout << "�̸� : ";
				cin >> student[stu].StdName;
				cout << "�й� : ";
				cin >> student[stu].Hakbun;
				cout << "\n\n";

				for (int sub = 0; sub < 3; sub++)
				{
					cout << "* ������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���.\n";
					cout << "������� : ";
					cin >> student[stu].Sub[sub].SubName;
					cout << "���� ���� �� : ";
					cin >> student[stu].Sub[sub].Hakjum;
					cout << "������(A+ ~ F) : ";
					cin >> student[stu].Sub[sub].Grade;

					CalcGPA(student[stu].Sub[sub]);
				}
				student[stu].AveGPA = CalcAveGPA(student[stu].Sub);
			}
			break;

		case '2':
		{
			PrintAllData(student);
			break;
		}

		case '3':
			Search(student);
			break;
		}
	}
	return 0;
}
