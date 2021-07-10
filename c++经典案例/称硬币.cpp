//称硬币
//案例描述：有12枚硬币。其中有11枚真币和1枚假币。假币和真币重量不同，
//但不知道假币比真币重还是轻。现在，用一架天平称了这些币三次，
//告诉你称的结果，请你找出假币并且确定假币是轻是重

//输入样例
//1
//ABCD EFGH even / up / down 天平左右两边的硬币数总是相等的

//strchr函数功能为在一个串中查找给定字符的第一个匹配之处。
//函数原型为：char* strchr(const char* str, int c)，
//即在参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置。
//strchr函数包含在C 标准库 <string.h>中。

//char* strchr(const char* str, int c)
//str-- 要被检索的 C 字符串。
//c-- 在 str 中要搜索的字符。
//在参数str所指向的字符串中搜索第一次出现字符c（一个无符号字符）的位置
//返回一个指向该字符串中第一次出现的字符的指针，如果字符串中不包含该字符则返回NULL空指针。

#include<iostream>
using namespace std;
#include<cstring>
char Left[3][7];//天平左边硬币
char Right[3][7];//天平右边硬币
char Result[3][7];//结果

//light为真表示假设假币为轻，否则表示假设假币为重
bool IsFake(char c, bool light);

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> Left[i] >> Right[i] >> Result[i];
		}
		for (char c = 'A'; c <= 'L'; c++)
		{
			if (IsFake(c, true))
			{
				cout << c << " is the counterfeit coin and it is light" << endl;
				break;
			}
			else if (IsFake(c, false))
			{
				cout << c << " is the counterfeit coin and it is heavy" << endl;
				break;
			}
		}

	}
}

bool IsFake(char c, bool light)
{
	//light为真表示假设假币为轻，否则表示假币为重
	for (int i = 0; i < 3; i++)
	{
		char* pLeft, * pRight;//指向天平两边的字符串
		if (light)
		{
			pLeft = Left[i];
			pRight = Right[i];
		}
		else
		{
			pLeft = Right[i];
			pRight = Left[i];
		}

		switch (Result[i][0])//天平右边的情况
		{
		case'u':
			if (strchr(pRight, c) == NULL) return false;
			break;

		case'e':
			if (strchr(pLeft, c) || strchr(pRight, c)) return false;
			break;

		case'd':
			if (strchr(pLeft, c) == NULL) return false;
			break;
		}
	}
	return true;
}