//提取数字
#include<iostream>
using namespace std;

//可以将输入的字符串的数字和字母分开并输出
int main()
{
	string str1 , str2;//str2用于保留str1中的字母
	cin >> str1;
	int sum = 0, index = 0;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if ('0' <= str1[i] && str1[i] <= '9')
		{
			sum *= 10;
			sum += str1[i] - '0';//数字字符的ascii-字符'0'的ascii码就等于该数字
			//（不要直接用int转换，会存在很大的数值差值）
		}
		if ('A' <= str1[i] && str1[i] <= 'Z' || 'a' <= str1[i] && str1[i] <= 'z')
		{
			str2 += str1[i];
		}
	}
	cout << sum << endl;
	cout << str2 << endl;
}