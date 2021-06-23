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
		//메뉴 출력
		cout << "1. 정수 정렬\n";
		cout << "2. 실수 정렬\n";
		cout << "3. 종료\n";
		cout << "메뉴 선택 : ";
		cin >> menu;
		cout << "\n\n";

		if (menu == '3')
			break;

		switch (menu)
		{
		case '1':
		{
			int arr[5];
			cout << "5개의 정수를 입력하세요: ";

			for (int i = 0; i < 5; i++)
				cin >> arr[i];

			sort(arr, arr + 5);

			cout << "\n";
			cout << "정렬 결과 : ";
			for (int i = 0; i < 5; i++)
				cout << arr[i] << " ";
			cout << "\n\n";
			break;
		}
		case '2':
		{
			double arr[5];
			cout << "5개의 실수를 입력하세요: ";

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
			cout << "잘못 입력하셨습니다.\n";
			continue;
		}
	}
	return 0;
}
