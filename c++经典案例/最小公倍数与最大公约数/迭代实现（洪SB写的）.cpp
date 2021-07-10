//算法与建模
//一、数值或数学问题
//最小公倍数   与    最大公约数
//算法：辗转相除法
//结论：两个自然数的最大公约数与它们的最小公倍数的乘积等于这两个数的乘积
#include<iostream>
using namespace std;

void Swap(int& m, int& n)
{
	int temp = m;
	m = n;
	n = temp;
}

int func(int m, int n)
{
	int s ;//两个工具人
	do
	{
		s = m % n;
		m = n;
		n = s;
	} while (s != 0);
	return m;
}

int main()
{
	int m, n;
	cin >> m >> n;
	if (m < n)  Swap(m, n);
	int p1 = func(m, n);
	int p2 = m * n / p1;
	cout << p1 << endl;//求最大公约数
	cout << p2 << endl;//求最小公倍数

}