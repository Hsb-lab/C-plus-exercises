//【题目描述】
//编写一个函数，接收一个整数值，返回这个数中数字逆序后的结果值。
//【输入格式】
//一行一个整数
//【输出格式】
//一行一个整数表示结果
//【输入样例】
//7631
//【输出样例】
//1367
#include <iostream>
using namespace std;
int main()
{
	long long n = 0; cin >> n;
	while (n)
	{
		cout << n % 10;
		n /= 10;
}

}