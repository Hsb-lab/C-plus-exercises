//Ѱ�Ҿ������Ӣ�ĵ���
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1;
	string str2[30];
	int arr[30] = { 0 };

	int i = 0;
	while (cin>>str1)
	{
		str2[i] = str1; 
		arr[i] = str1.size();
		i++;
	}
	int max = 0;
	for (int j = 0; j < i; j++)
	{
		if (arr[max] < arr[j])  max = j;//�����±�
	}
	cout << str2[max] << endl;
}