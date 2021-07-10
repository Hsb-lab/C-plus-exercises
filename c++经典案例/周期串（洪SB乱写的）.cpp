//【题目描述】
//如果一个字符串可以由某个长度为k的字符串重复多次得到，我们说该串以k为周期。
//例如，abcabcabc以3为周期（注意它也以6和12为周期）。
//输入一个长度不超过80的串，输出它的最小周期。
//【输入格式】
//一行一个字符串
//【输出格式】
//一行一个整数表示最小周期
//【输入样例】
//HoHoHo
//【输出样例】
//2
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string m; cin >> m;//定义并输入一个字符串
	int len = m.length();//获取字符串的长度
	for (int i = 1; i <= len; i++)//遍历以i为周期
	{
		if (len % i != 0) continue;
		else
		{
			for (int j = i; j < len; j++)
			{
				if (m[j % i] != m[j])
				{
					break;
				}
				if (j == len - 1)
				{
					cout << i << endl; return 0;
				}
			}
		}
	}
	cout << len << endl;//如果此字符串没有周期，那么它的最小周期就是她本身的长度
	return 0;
}