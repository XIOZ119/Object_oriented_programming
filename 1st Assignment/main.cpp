/* 성적처리프로그램#0 */

#include <iostream>
using namespace std;

int main()
{
	char name[20];

	cout << "(cout) 이름을 입력하세요.\n";
	std::cin >> name;
	cout << "(cout) 당신의 이름은 " << name << " 입니다.\n" << std::endl;

	return 0;
}