//水仙花数
//所谓水仙花数（NarcissisticNumber）是指一个3位数，其各位数字的立方和等于它本身。
//思路：（1）将该数各位数字分解出来，然后求各数字立方和是否等于原数
//（2）凑3个数字，组成一个三位数，求各数字立方和是否等于凑成的数（注意百位数字从1开始）
//例如153是“水仙花数”，因为：153 = 13 + 53 + 33。
//输出100~1000之间的水仙花数
#include<iostream>
#include<cmath>
using namespace std;

bool func(int i)
{
	int a = i % 10;//获取个位数字
	int b = (i / 10) % 10;//获取十位数字
	int c = i / 100;//获取百位数字
	int temp = pow(a, 3) + pow(b, 3) + pow(c, 3);
	if (temp == i) return true;
	else return false;
}

int main()
{
	for (int i = 100; i < 1000; i++)
	{
		if (func(i)) cout << i << endl;
	}
}