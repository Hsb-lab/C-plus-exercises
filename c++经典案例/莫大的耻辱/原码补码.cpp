//【问题描述】
//编写程序，输入字符串形式的二进制整数（长度为16位，采用补码表示），
//把它转换为十进制整数，输出该十进制整数。补码首位表示符号，
//0代表正数，1代表负数。
//需要注意的是：求负整数的补码，
//将其对应正数二进制表示所有位取反（包括符号位，0变1，1变0）后加1。
//【输入形式】
//输入一个16位补码表示的二进制整数
//【输出形式】
//二进制整数对应的十进制数
//【样例输入】
//0000000000001101
//【样例输出】
//13

#include<iostream>
using namespace std;
#include<cmath>

int main()
{
	string str;//输入一个16位补码表示的二进制整数
	cin >> str;

	int len = str.length();//求字符串的长度
	int sum = 0;
	if (str[0] == '0')//输入的是正整数的原码
	{
		for (int i = 1; i <= len - 1; i++)
		{
			int temp = str[i] - '0';
			sum += temp * pow(2, len - 1 - i);
		}
		cout << sum << endl;
		return 0;
	}
	else//输入的是负整数的原码
	{
		//将负数的原码转化为补码
		//step1:减去一（二进制加法）
		for (int i = len - 1; i >= 1; i--)
		{
			if (str[i] == '1')
			{
				str[i] = '0';
				break;
			}
			else
			{
				str[i] = '1';
			}
		}

		//step2:进行取反操作
		for (int i = 1; i <= len - 1; i++)
		{
			if (str[i] == '0') str[i] = '1';
			else if (str[i] == '1') str[i] = '0';
		}

		//求负数的真值
		for (int i = 1; i <= len - 1; i++)
		{
			int temp = str[i] - '0';
			sum += temp * pow(2, len - 1 - i);
		}
		cout << sum * (-1) << endl;
		return 0;
	}
	return 0;
}