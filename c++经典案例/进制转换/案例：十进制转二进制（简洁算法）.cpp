//【题目描述】
//输入1个正整数n（n > 0），将其转换为二进制后输出。
//【输入格式】
//一行一个正整数 n
//【输出格式】
//一行一个二进制数表示结果
//【样例输入】
//15
//【样例输出】
//1111
#include <iostream>
using namespace std;
#include <cmath>
int main()
{
	long long n, i = 0, sum = 0;
	cin >> n;
	while (n)
	{
		sum += (n % 2) * pow(10, i);
		n = n / 2;
		++i;
	}
	cout << sum;
}