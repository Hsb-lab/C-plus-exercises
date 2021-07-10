//【题目描述】
//编写程序，输入城市名，按字母顺序输出城市名清单。
//（注：城市按拼音排列输出）
//【思路】
//（1）利用字符串比较函数（strcmp）和数组排序算法实现；
//（2）动态申请指针数组，每个数组元素的数据类型为，char* ；
//【输入格式】
//第一行一个整数 n 表示城市名的个数
//接下来 n 行每行一个字符串表示城市名
//【输出格式】
//n 行 n 个字符串, 表示城市名按顺序排序后的结果
//【输入样例】
//3
//chongqing
//beijing
//shanghai
//【输出样例】
//beijing
//chongqing
//shanghai
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
int main()
{
	int n; cin >> n;//n代表元素的个数
	string m;//m代表城市的名字
	string* arr = new string[n];//创建动态数组
	for (int i = 0; i < n; i++)//给动态数组赋值
	{
		cin >> m; arr[i] = m;
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i][0] > arr[i + 1][0])
		{
			string temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
}