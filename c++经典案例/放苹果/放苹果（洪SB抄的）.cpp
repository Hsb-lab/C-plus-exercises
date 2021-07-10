//放苹果
//把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问公有多少种不同的分法？
#include<iostream>
using namespace std;

int func(int m, int n)
{
	if (m == 0)  return 1;
	if (n == 0) return 0;
	if (m  < n)  return func(m, m);//盘子不会出现空的情况
	else
	{
		return func(m - n, n) + func(m, n - 1);//分情况讨论，有无空光盘子
	}
}

int main()
{
	int m, n;//m代表苹果数量，n代表盘子数量
	cin >> m >> n;
	cout << func(m, n) << endl;
}