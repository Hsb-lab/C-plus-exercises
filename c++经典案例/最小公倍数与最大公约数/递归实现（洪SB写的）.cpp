//算法与建模
//一、数值或数学问题
//最小公倍数   与    最大公约数
//算法：辗转相除法
/*
欧几里得算法是用来求两个正整数最大公约数的算法。古希腊数学家欧几里得在其著作《The Elements》中最早描述了这种算法,所以被命名为欧几里得算法。
扩展欧几里得算法可用于RSA加密等领域。
假如需要求 1997 和 615 两个正整数的最大公约数,用欧几里得算法，是这样进行的：
1997 / 615 = 3 (余 152)
615 / 152 = 4(余7)
152 / 7 = 21(余5)
7 / 5 = 1 (余2)
5 / 2 = 2 (余1)
2 / 1 = 2 (余0)
至此，最大公约数为1
以除数和余数反复做除法运算，当余数为 0 时，取当前算式除数为最大公约数，所以就得出了 1997 和 615 的最大公约数 1。
*/
#include<iostream>
using namespace std;

void function(int& m, int& n)
{
	int temp = m;
	m = n;
	n = temp;
}

int func(int m, int n)
{
	if (m < n) function(m, n);
	if (m % n == 0)    return n;
	else  func(m %n , n);
}

int func_(int m, int n)
{
	int i = m > n ? m : n;
	while (i % m != 0 || i % n != 0)
	{
		i++;
	}
	return i;
}

int main()
{
	int m, n;
	cin >> m >> n;
	cout << func(m, n) << endl;//求最大公约数的算法
	cout << func_(m, n) << endl;//求最小公倍数的算法
}