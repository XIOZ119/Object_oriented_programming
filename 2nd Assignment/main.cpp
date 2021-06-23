#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Subject { // ��������
	char SubName[30];  // �����̸�
	int Hakjum;        // ����������
	char Grade[10];    // ���� ���
	float NumHakjum;    // ���� ��� ����
	float GPA;         // ���� ����
};

struct Student { // �л� ����
	char StdName[30];  // �л� �̸�
	int Hakbun;		   // �й�
	float AveGPA;      // ������ ��� ����

	Subject Sub[3]; // Subject �߰�
};

int main()
{
	struct Student student[2] = { 0 };
	int stu = 0;
	char menu;

	while (true)
	{
		// �޴� ���
		cout << "==== �޴� ====\n";
		cout << "1. �л� ���� �Է�\n";
		cout << "2. ��ü �л� ���� ����\n";
		cout << "3. ���α׷� ����\n\n";
		cout << "���ϴ� ����� �Է��ϼ��� : ";
		cin >> menu;
		cout << "\n";

		if (menu == '3')
			break;

		switch (menu)
		{
		case '1':
			if (stu == 2)
			{
				cout << "���̻� �� ������ �Է��Ͻ� �� �����ϴ�.\n";
				break;
			}
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
					cout << "���������� : ";
					cin >> student[stu].Sub[sub].Hakjum;
					cout << "������(A+ ~ F) : ";
					cin >> student[stu].Sub[sub].Grade;
					cout << "�������� ���ڷ� : ";
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

			//��ü �л� ���� ���� 

			cout.width(10); cout << std::right << "��ü �л� ���� ����\n";
			cout << "-------------------------------------------------\n";
			for (int i = 0; i < 2; i++)
			{
				cout << "�̸� : " << student[i].StdName << " �й� : " << student[i].Hakbun;
				cout << "\n-------------------------------------------------\n";
				cout.width(10); cout << "�����";
				cout.width(10); cout << "��������";
				cout.width(10); cout << "������";
				cout.width(10); cout << "��������" << endl;
				cout << "-------------------------------------------------\n";
				for (int j = 0; j < 3; j++)
				{
					cout.width(10); cout << std::right << student[i].Sub[j].SubName;
					cout.width(10); cout << std::right << student[i].Sub[j].Hakjum;
					cout.width(13); cout << std::right << student[i].Sub[j].Grade;
					cout.width(11); cout << std::right << student[i].Sub[j].GPA << "\n";
				}
				cout << "=================================================\n";
				cout.width(43); cout << "�������" << student[i].AveGPA << "\n";
			}
		}
	}
	return 0;
}