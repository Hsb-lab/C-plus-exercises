//【题目描述】
//哥德巴赫猜想：一个大于2的偶数是两个素数的和。
//编写程序验证哥德巴赫猜想，输入一个大于2但是小于等于500的偶数，
//如果它能表示成为2个素数的和，则输出所有的可能情况（输出格式为 大素数 + 小素数 = 偶数）.
//【输入格式】
//一行一个符合数据范围的偶数
//【输出格式】
//若干行表示所有表示的可能情况(注意空格分隔)
//【输入样例】
//24
//【输出样例】
//19 + 5 = 24
//17 + 7 = 24
//13 + 11 = 24
#include <iostream>
#include <cmath>
using namespace std;
//判断一个数是否为素数的函数，若为素数则返回1，否则返回0
bool func(int a)
{
	for (int i = 2; i < sqrt(a) + 1; i++)
	{
		if (a % i == 0 && a!= i) return false;

	}
	return true;
}
int main()
{
	int n; cin >> n;
	if (n % 2 != 0 || n <= 2)  return 0;
	for (int a = n - 1; a > 1; a--)
	{
		for (int b = 2; b <= a; b++)
		{
			if ((a + b) == n)
			{
				if (func(a) && func(b))
				{
					cout << a << " + " << b << " =" << n << endl;
				}

			}
		}

	}
	return 0;
}