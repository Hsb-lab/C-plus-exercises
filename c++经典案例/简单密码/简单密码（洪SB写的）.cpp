//简单密码
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char arr1[101] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char arr2[101] = "bcdefghijklmnopqrstuvwxyza22233344455566677778889999";
	char arr[101];
	cin >> arr;
	int len = strlen(arr);//有效字符长度
	int len_1 = strlen(arr1);
	//int len_2 = strlen(arr2);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len_1; j++)
		{
			if (arr[i] == arr1[j])
			{
				cout << arr2[j];
				break;
			}
			if (j == len_1 - 1)  cout << arr[i];//找不到即为数字
		}
	}
}