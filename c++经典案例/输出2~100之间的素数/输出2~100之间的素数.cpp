//输出2~100之间的素数
//要用到break语句
#include<iostream>
using namespace std;
int main()
{
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0 && i != j)  break;
			if (i == j)  cout << i << endl;
	}
}

}