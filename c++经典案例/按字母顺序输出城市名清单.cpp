//����Ŀ������
//��д�������������������ĸ˳������������嵥��
//��ע�����а�ƴ�����������
//��˼·��
//��1�������ַ����ȽϺ�����strcmp�������������㷨ʵ�֣�
//��2����̬����ָ�����飬ÿ������Ԫ�ص���������Ϊ��char* ��
//�������ʽ��
//��һ��һ������ n ��ʾ�������ĸ���
//������ n ��ÿ��һ���ַ�����ʾ������
//�������ʽ��
//n �� n ���ַ���, ��ʾ��������˳�������Ľ��
//������������
//3
//chongqing
//beijing
//shanghai
//�����������
//beijing
//chongqing
//shanghai
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
int main()
{
	int n; cin >> n;//n����Ԫ�صĸ���
	string m;//m������е�����
	string* arr = new string[n];//������̬����
	for (int i = 0; i < n; i++)//����̬���鸳ֵ
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