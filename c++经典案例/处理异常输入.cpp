//�����쳣����
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
			cout << "������������������" << endl;
			cin.clear();
			cin.ignore();
		}
		else break;
	}

	cout << a << endl;
	return 0;
}