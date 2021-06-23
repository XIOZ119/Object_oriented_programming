#include <iostream>
#include <algorithm>

using namespace std;


// default
template <typename T>
void sort(T arr[]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[i] > arr[j])
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	char menu;

	while (true)
	{
		//�޴� ���
		cout << "1. ���� ����\n";
		cout << "2. �Ǽ� ����\n";
		cout << "3. ����\n";
		cout << "�޴� ���� : ";
		cin >> menu;
		cout << "\n\n";

		if (menu == '3')
			break;

		switch (menu)
		{
		case '1':
		{
			int arr[5];
			cout << "5���� ������ �Է��ϼ���: ";

			for (int i = 0; i < 5; i++)
				cin >> arr[i];

			sort(arr, arr + 5);

			cout << "\n";
			cout << "���� ��� : ";
			for (int i = 0; i < 5; i++)
				cout << arr[i] << " ";
			cout << "\n\n";
			break;
		}
		case '2':
		{
			double arr[5];
			cout << "5���� �Ǽ��� �Է��ϼ���: ";

			for (int i = 0; i < 5; i++)
				cin >> arr[i];

			sort(arr, arr + 5);

			for (int i = 0; i < 5; i++)
				cout << arr[i] << " ";
			cout << "\n";
			break;
		}
		break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�.\n";
			continue;
		}
	}
	return 0;
}
