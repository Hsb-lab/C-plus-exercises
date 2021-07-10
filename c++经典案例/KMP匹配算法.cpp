//KMP 模式匹配算法实现

#include<iostream>
using namespace std;
#include<string>
#include<cstring>

//得到next数组的函数
void Get_Next(string T,int *next)//T代表目标子串
{
	int len = T.size();//获取子串的长度
	int i = 1, j = 0;

	next[0] = 0;
	while (i < len)
	{
		if (T[i] == T[j])
		{
			next[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j > 0) j = next[j - 1];
			else if (j == 0 && T[i] != T[j])
			{
				next[i] = 0;
				i++;
			}
		}
	}

	return;//不要返回局部变量的引用或地址
}

//完成KMP匹配的函数
void KMP(string MasterStr,string SubStr,int *next)
{
	int Times = 0;//统计子串出现的次数
	int len01 = MasterStr.length();
	int len02 = SubStr.length();
	int i = 0,j = 0;
	while (j < len01)
	{
		if (SubStr[i] == MasterStr[j])
		{
			i++;
			j++;
		}
		else
		{
			if (i > 0) i = next[i - 1];
			else
			{
				if (SubStr[0] != MasterStr[j]) j++;
			}
		}

		if (i == len02 - 1 && SubStr[i] == MasterStr[j])
		{
			Times++;
			i = 0;
			j++;
		}
	}

	if (Times == 0) cout << "未匹配到该字符" << endl;
	else cout << "匹配到该字符" << "该字符出现了" << Times << "次" << endl;
}

void test01()
{
	string T = "aa";
	int len = T.length();
	int *next = new int[len];
	Get_Next(T, next);
	for (int i = 0; i < len; i++)
	{
		cout << next[i];
	}
	cout << endl;

	KMP("abaaabaaa", T, next);
}

int main()
{
	test01();
}