//算法与建模
//数值或数学问题
//质数判断
//理论依据：算法2：（质数筛选定理）n不能够被不大于根号n的任何质数整除，则n是一个质数
//（根据这个定理可以简化运算）
//易错提示：1不是质数
#include<iostream>
#include<cmath>
using namespace std;

//判断一个数是否为质数（素数）的函数
bool func(int m)
{
	for (int i = 2; i <= sqrt(m); i++)
	{
		if (m % i == 0)  return 0;
	}
	return 1;
}

int main()
{
	int m;
	cin >> m;
	if (func(m)) cout << "m为质数" << endl;
	else cout << "m不是质数" << endl;
}