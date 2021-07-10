//求字符串的子串

//奈斯，一命通关！

#include<iostream>
using namespace std;

void Swap(string& str1, string& str2)
{
	string temp = str1;
	str1 = str2;
	str2 = temp;
}

//判断子串是否存在，如果存在，返回在主串中的起始位置
int Func(string str1,string str2)
{
	int len01 = str1.length();
	int len02 = str2.length();

	//这里默认str1为主串，str2为子串
	if (len01 < len02) Swap(str1, str2);

	for (int i = 0; i < len01; i++)
	{
		for (int j = 0,temp = i; j < len02; j++,temp++)
		{
			if (str2[j] != str1[temp]) break;
			if (j == len02 - 1) return i;
		}
	}

	return 0;
}

void test01()
{

	string str1,str2;
	cin >> str1 >> str2;

	int ret = Func(str1, str2);
	if (ret)
	{
		cout << "子串在主串中找到" << endl;
		cout << "在主串中的起始位置为：" << ret << endl;
	}
	else
	{
		cout << "在主串中没有找到该子串" << endl;
	}

}

int main()
{
	test01();
}