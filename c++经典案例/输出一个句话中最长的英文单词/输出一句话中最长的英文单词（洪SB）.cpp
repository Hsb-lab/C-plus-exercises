//输出一句话中最长的英文单词
#include<iostream>
using namespace std;
int main()
{
	string str1 , str2 = "";
	while (cin >> str1)
	{
		if (str1.size() > str2.size())
		{
			str2 = str1;
		}
	}
	cout << str2 << endl;
	return 0;
}