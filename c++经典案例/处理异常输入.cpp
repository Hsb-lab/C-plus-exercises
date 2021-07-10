//处理异常输入
#include<iostream>
using namespace std;

int main()
{
	int a = 0;

	
	while (1)
	{
		cin >> a;
		if (cin.fail() == 1)
		{
			cout << "输入有误，请重新输入" << endl;
			cin.clear();
			cin.ignore();
		}
		else break;
	}

	cout << a << endl;
	return 0;
}