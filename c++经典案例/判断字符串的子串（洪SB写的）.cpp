//【题目描述】
//对主串s按序号递增的顺序选出一个子串t，称t是s的子序列。
//例如，对于主串s = "abcbda"，子串"bcd"是s的一个子序列。
//给定两个主串s1和s2，当子串t既是s1的子序列又是s2的子序列时，称t是s1和s2的公共子序列。
//例如，主串s1 = "abcbda"，主串s2 = "abcab"，子串"acb"是主串s1和s2的公共子序列。
//要求编写程序，判断给定的子串是否为两个主串的公共子序列。
//【输入格式】
//一行三个字符串(中间用一个空格分隔)，分别表示两个主串 s1，s2 和 t
//【输出格式】
//按要求输出 "yes" 或 "no" (不带引号)
//【样例输入1】
//abcdef abcffff abc
//【样例输出1】
//yes
//【样例输入2】
//abcdef ffff abc
//【样例输出2】
//no
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//获取字符串的长度
int func01(string str)
{
	int len = str.length();
	return len;
}

//判断两个字符串是否构成字串关系
bool func02(string str1, string str2)
{
	int len_1 = func01(str1); int len_2 = func01(str2);
	  if (len_1 < len_2) return 0;
	for (int i = 0; i < len_2; i++)
	{
		for (int j = 0; j < len_1; j++)
		{
			if (str2[i] == str1[j]) break;
			if (j == len_1 - 1)  return 0;
	}
		
	}
	return 1;
}
int main()
{
	string s1, s2, t;
	cin >> s1 >> s2 >> t;
	if (func02(s1, t) && func02(s2, t))   cout << "yes";
	else  cout << "no";
}