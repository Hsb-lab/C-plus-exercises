//【题目描述】
//现有一个 m* n 的网格，从最左上角出发，每次只能向右或者向下移动一格，问有多少种不同的方法可以到达最右下角的格子？
//【输入格式】
//一行两个整数表示 m, n
//【输出格式】
//一行一个整数表示答案
//【输入样例】
//2 2
//【输出样例】
//2
#include <iostream>
using namespace std;
int waysum(int m , int n)
{
	int sum = 0;
	if (m == 1 || n == 1) return 1;
	else if (m == 2 && n == 2) return 2;
	else if (m == 2 && n == 3 || m == 3 && n == 2) return 3;
	else { sum += waysum(m - 1, n) + waysum(m, n - 1); return sum; }
}
int main()
{
	int m, n; cin >> m >> n;
	cout << waysum(m, n);
}